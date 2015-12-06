#include "Save.h"
/*
    文件操作:
    1 ~ n:
        列名字 + 列种类 +列长度
    n + 1 ~:
        数据
*/
bool Save::saveTable(kTable &table){
    char tablename[256];
    strcpy(tablename,"table\\");
    int j = strlen(tablename);
    int L = table.name.size();
    for(int i = 0; i < L; i++)
        tablename[j++] = table.name[i];
    tablename[j]   = '\0';
    //删除表文件之后建立
    ofstream fr(tablename,ios::out | ios::trunc);
    if(!fr)
        cout << "Can't build the txt file!" << endl;
    else{
        fr << setiosflags(ios::left);
        int Size = table.columnName.size();
        for(int i = 0; i < Size; i++){
            fr << table.columnName[i] << endl;
            //---------------------------
            fr << table.columnType[i] << endl;
            //----------------------------
            fr << table.columnUnit[i] << endl;;
            //----------------------------
            fr << table.isKey[i] << endl;
        }
        fr << "#" << endl;
        for(int i = 0; i < table.dataNumber; i++){
            for(int j = 0; j < Size; j++){
                fr << table.tableData[i][j] << endl;
            }
            fr << "$" << endl;
        }
        fr << "@";
        fr.close();
    }
    return true;
};

bool Save::getTable(kTable &table){
    char tablename[256];
    strcpy(tablename,"table\\");
    int j = strlen(tablename);
    int L = table.name.size();
    for(int i = 0; i < L; i++)
        tablename[j++] = table.name[i];
    tablename[j]   = '\0';
    //cout << tablename << endl;
    fstream fr(tablename,ios::in);
    if(fr){
        char data[2048];
        int op = 1;
        while(!fr.eof()){
            fr.getline(data,2048);
            if(data[0] == '@') break;
            if(data[0] == '#'){
                op ++;
            }
            else{
                if(op == 1){
                    string name(data);
                    int type,unit,key;
                    //提取行的属性数据
                    fr.getline(data,2048);
                    sscanf(data,"%d",&type);
                    fr.getline(data,2048);
                    sscanf(data,"%d",&unit);
                    fr.getline(data,2048);
                    sscanf(data,"%d",&key);

                    table.addColumn(name,type,unit,key);
                }
                else if(op == 2){
                    for(int i = 0; i < (int)table.columnName.size(); i++){
                        string temp(data);
                        table.tableData[table.dataNumber].push_back(temp);
                        //cout << temp << " ";
                        fr.getline(data,2048);
                    }
                    //cout << endl;
                    table.dataNumber ++;
                }
            }
        }
        //cout << table.columnName.size() << endl;
        fr.close();
    }
    else{
        //cout << "Can't find the table [" << tablename << "]" << endl;
        return false;
    }
    return true;
}

bool Save::saveView(kView& view){
    char viewname[256];
    strcpy(viewname,"view\\");
    int j = strlen(viewname);
    int L = view.viewname.size();
    for(int i = 0; i < L; i++)
        viewname[j++] = view.viewname[i];
    viewname[j]   = '\0';
    //删除表文件之后建立
    ofstream fr(viewname,ios::out | ios::trunc);
    if(!fr)
        cout << "Can't build the txt file!" << endl;
    else{
        /*
            vector<string>name;
            vector<int>symbol;
            vector<string>value;
        */
        fr << view.tablename << endl;
        fr << "#" << endl;
        for(int i = 0; i < (int)view.selectColumn.name.size(); i++)
            fr << view.selectColumn.name[i] << endl;
        fr << "#" << endl;
        for(int i = 0; i < (int)view.whereRow.name.size(); i++){
            fr << view.whereRow.name[i] << endl;
            fr << view.whereRow.symbol[i] << endl;
            fr << view.whereRow.value[i] << endl;
        }
        fr << "@" << endl;
    }
    return true;
}

bool Save::getView(kView &view){
    char viewname[256];
    strcpy(viewname,"view\\");
    int j = strlen(viewname);
    int L = view.viewname.size();
    for(int i = 0; i < L; i++)
        viewname[j++] = view.viewname[i];
    viewname[j]   = '\0';
    fstream fr(viewname,ios::in);
    if(fr){
        char data[2048];
        int op = 0;
        while(!fr.eof()){
            fr.getline(data,2048);
            if(data[0] == '@') break;
            if(data[0] == '#'){
                op ++;
            }
            else if(data[0] != '\0'){
                if(op == 0)
                    view.tablename = string(data);
                if(op == 1){
                    view.selectColumn.name.push_back(string(data));
                }
                if(op == 2){
                    view.whereRow.name.push_back(string(data));
                    fr.getline(data,2048);
                    int v;
                    sscanf(data,"%d",&v);
                    view.whereRow.symbol.push_back(v);
                    fr.getline(data,2048);
                    view.whereRow.value.push_back(string(data));
                }
            }
        }
        fr.close();
    }
    else{
        return false;
    }
    return true;
}

bool Save::saveIndex(kIndex &index){
    char indexname[256];
    strcpy(indexname,"index\\");
    int j = strlen(indexname);
    int L = index.name.size();
    for(int i = 0; i < L; i++)
        indexname[j++] = index.name[i];
    indexname[j]   = '\0';
    //删除表文件之后建立
    ofstream fr(indexname,ios::out | ios::trunc);
    if(!fr)
        cout << "Can't build the txt file!" << endl;
    else{
        fr << "#" << endl;
        fr << index.tablename << endl;
        fr << "#" << endl;
        fr << index.itype << endl;
        fr << "#" << endl;
        for(int i = 0;i < (int)index.column.size() ; i++){
            fr << index.column[i] << endl;
            fr << index.type[i] << endl;
            fr << "#" << endl;
        }
        fr << "@" << endl;
    }
    return true;
}
bool Save::getIndex(kIndex &index){
    char indexname[256];
    strcpy(indexname,"index\\");
    int j = strlen(indexname);
    int L = index.name.size();
    for(int i = 0; i < L; i++)
        indexname[j++] = index.name[i];
    indexname[j]   = '\0';
    fstream fr(indexname,ios::in);
    if(fr){
        char data[2048];
        int op = 0;
        while(!fr.eof()){
            fr.getline(data,2048);
            string temp(data);
            if(temp == "#")
                op ++;
            else if(temp == "@")
                break;
            else{
                if(op == 1){
                    index.tablename = temp;
                }
                if(op == 2){
                    if(temp == "1")
                        index.itype = 1;
                    if(temp == "2")
                        index.itype = 2;
                }
                if(op >= 3){
                    index.column.push_back(temp);
                    fr.getline(data,2048);
                    string _temp(data);
                    if(_temp == "1")
                        index.type.push_back(1);
                    if(_temp == "2")
                        index.type.push_back(2);
                }
            }
        }
        fr.close();
    }
    else{
        return false;
    }
    return true;
}
