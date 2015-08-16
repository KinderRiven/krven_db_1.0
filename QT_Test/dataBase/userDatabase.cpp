#include "userDatabase.h"

//--------------------�û����ݶ�д��-----------------

//���캯�������û����ݵĳ�ʼ��
userDatabase::userDatabase(string user){
    username = user;
    userStart();
};
//�û����ݵĳ�ʼ��
bool userDatabase::userStart(){
    //read
    int L = username.size();
    char name[256];
    strcpy(name,"user\\");
    int  j = strlen(name);
    for(int i = 0; i < L; i++)
        name[j++] = username[i];
    name[j] = '\0';
    fstream fr(name,ios::in);
    //------------�û����ݵĶ�ȡ---------------
    if(fr){
        char data[2048];
        int op = 0;
        while(!fr.eof()){
            fr.getline(data,2048);
            if(data[0] == '#'){
                op ++;
            }
            else{
                if(op == 1 && data[0] != '\0'){
                    string temp_name(data);
                    //cout << "can_read " << temp_name << endl;
                    int id = FindTable(temp_name);
                    //û�б��û���ȡ��
                    if(id == -1){
                        kTable newTable;
                        newTable.name = temp_name;
                        newTable.can_read = true;
                        myTable.push_back(newTable);
                    }
                    else
                        myTable[id].can_read = true;
                }
                if(op == 2 && data[0] != '\0'){
                    string temp_name(data);
                    //cout << "can_write " << temp_name << endl;
                    int id = FindTable(temp_name);
                    if(id == -1){
                        kTable newTable;
                        newTable.name = temp_name;
                        newTable.can_write = true;
                        myTable.push_back(newTable);
                    }
                    else
                        myTable[id].can_write = true;
                }
                if(op == 3 && data[0] != '\0'){
                    string temp_name(data);
                    //
                    kView newView;
                    newView.viewname = temp_name;
                    //cout << newView.viewname << endl;
                    myView.push_back(newView);
                }
                if(op == 4 && data[0] != '\0'){
                    string temp_name(data);
                    kIndex newindex;
                    newindex.name = temp_name;
                    //cout << newindex.name << endl;
                    myIndex.push_back(newindex);
                }
            }
        }
        fr.close();
        //----------�û������ݵĶ�ȡ--------------
        userGetTable();
        userGetView();
        userGetIndex();
        //----------------------------------------
    }
    else{
        ofstream fr(name);
        fr << "#" << endl;
        fr << "#" << endl;
        fr.close();
    }
    //-------------------------------
    return true;
}
//��������,�����û���Ϣ�Ĵ洢
userDatabase::~userDatabase(){
    int Size = myTable.size();
    for(int i = 0; i < Size; i++){
        save.saveTable(myTable[i]);
    }
    Size = myView.size();
    for(int i = 0; i < Size; i++){
        save.saveView(myView[i]);
    }
    Size = myIndex.size();
    for(int i = 0; i < Size; i++){
        save.saveIndex(myIndex[i]);
    }
    Size = myTable.size();
    //open �����û��ļ�
    int L = username.size();
    char cname[256];
    strcpy(cname,"user\\");
    int j = strlen(cname);
    for(int i = 0; i < L; i++)
        cname[j++] = username[i];
    cname[j] = '\0';
    //ɾ��֮����
    ofstream fr(cname,ios::trunc | ios::out);
    //------------username--------------------
    //fr << username << endl;
    //--------------read----------------------
    fr << "#" << endl;
    for(int i = 0; i < Size; i++)
        if(myTable[i].can_read == true){
            fr << myTable[i].name << endl;
        }
    //--------------write---------------------
    fr << "#" << endl;
    for(int i = 0; i < Size; i++)
        if(myTable[i].can_write == true){
            fr << myTable[i].name << endl;
        }
    //--------------view----------------------
    fr << "#" << endl;
    Size = myView.size();
    for(int i = 0; i < Size; i++){
        fr << myView[i].viewname << endl;
    }
    //--------------Index---------------------
    fr << "#" << endl;
    Size = myIndex.size();
    for(int i = 0; i < Size; i++){
        fr << myIndex[i].name << endl;
    }
    fr.close();
};
//�û���ñ���
bool userDatabase::userGetTable(){
    int Size = myTable.size();
    for(int i = 0; i < Size; i++)
        save.getTable(myTable[i]);
    //�Դ����ľ�����
    vector<kTable>::iterator it;
    for(it = myTable.begin(); it != myTable.end();){
        if((*it).columnName.size() == 0){
            it = myTable.erase(it);
        }
        else it++;
    }
    return true;
}
//�û������ͼ����
bool userDatabase::userGetView(){
    int Size = myView.size();
    for(int i = 0; i < Size; i++)
        save.getView(myView[i]);
    return true;
}

bool userDatabase::userGetIndex(){
    int Size = myIndex.size();
    for(int i = 0; i < Size; i++)
        save.getIndex(myIndex[i]);
    return true;
}
//-------------------����������-----------------------

//���ܶ��봰�ڣ����ຯ��������false��ʱ��������
bool userDatabase::userRead(){
    cout << endl << username << ">" << endl;
    switch(mySql.read()){
        case 0: return false;
        case 1:
            if(!CreateTable())  cout << "[Error] Create table error!" << endl;
                break;
        case 2:
            if(!CreateView())   cout << "[Error] Create view error!" << endl;
            break;
        case 3:
            if(!CreateIndex())  cout << "[Error] Create index error!" << endl;
            break;
        case 10:
            if(!InsertTable())  cout << "[Error] Insert error!" << endl;
                break;
        case 11:
            if(!SelectTable())  cout << "[Error] Select error!" << endl;
                break;
        case 12:
            if(!DeleteTable())  cout << "[Error] Drop table error!" << endl;
                break;
        case 13:
            if(!UpdateTable())  cout << "[Error] Update table error!" << endl;
                break;
        case 14:
            if(!DeleteData())   cout << "[Error] Delete data error!" << endl;
                break;
        case 15:
            if(!DeleteView())   cout << "[Error] Delete view error!" << endl;
                break;
        case 16:
            if(!GrantToUser())  cout << "[Error] Grant to user error!" << endl;
            break;
        case 20:
            readme.createHelp();
            break;
        case 21:
            readme.selectHelp();
            break;
        case 22:
            readme.insertHelp();
            break;
        case 23:
            readme.dropHelp();
            break;
        case 24:
            readme.updateHelp();
            break;
        case 25:
            InputAllTable();
            InputAllView();
            InputAllIndex();
            break;
        case 26:
            InputAllTable();
            break;
        case 27:
            InputAllView();
            break;
        case 28:
            InputAllIndex();
            break;
        default :
            printf("[Error] SQL input error!\n");
            break;
    }
    return true;
};
//�ж����� int char
int userDatabase::JudgeType(int pos){
    if(canRead(pos)){
        if(mySql.sqlWord[pos] == "int")  return 1;
        if(mySql.sqlWord[pos] == "char") return 2;
    }
    return -1;
};
//�жϼ�ֵ
//NOT NULL,UNIQUE,PRIMARY KEY
int userDatabase::JudgeKey(int &pos){
    int cnt = 0;
    //���ö����Ƶ�λ�����ж�
    /*
        ����λ Ϊ PRIMARY KEY
        ��һλ Ϊ UNIQUE
        �ڶ�λ Ϊ NOT NULL
    */
    while(true){
        if(canRead(pos + 1) && mySql.sqlWord[pos] == "primary" && mySql.sqlWord[pos + 1] == "key"){
            cnt |= (1 << 0);
            pos += 2;
        }
        else if(canRead(pos) && mySql.sqlWord[pos] == "unique"){
            cnt |= (1 << 1);
            pos ++;
        }
        else if(canRead(pos + 1) && mySql.sqlWord[pos] == "not" && mySql.sqlWord[pos + 1] == "null"){
            cnt |= (1 << 2);
            pos +=2;
        }
        else
            break;
    }
    return cnt;
};
//�жϵ�λ ���� char(20)
int userDatabase::JudgeUnit(int pos){
    if(canRead(pos)){
        int Size = mySql.sqlWord[pos].size();
        int unit = 0;
        for(int i = 0; i < Size; i++){
            char c = mySql.sqlWord[pos][i];
            if(c >= '0' && c <= '9')
                unit = unit * 10 + (c - '0');
            else
                return -1;
        }
        return unit;
    }
    return -1;
};
//�ҵ�������֣������ڷ���-1
/*
    �������ֲ��ұ�
    ���ɹ����� -1
*/
int userDatabase::FindTable(string name){
    int Size = myTable.size();
    string stemp;
    for(int i = 0 ; i < Size; i++){
        stemp = myTable[i].name;
        if(stemp == name)
            return i;
    }
    return -1;
};
//������ͼ�������ڷ���-1
int userDatabase::FindView(string name){
    int Size = myView.size();
    string stemp;
    for(int i = 0; i < Size; i++){
        stemp = myView[i].viewname;
        if(stemp == name)
            return i;
    }
    return -1;
}
//�����ж�
int userDatabase::FindIndex(string name){
    int Size = myIndex.size();
    for(int i = 0; i < Size; i++)
        if(name == myIndex[i].name)
            return i;
    return -1;
}
bool userDatabase::canRead(int pos){
    int Size = mySql.sqlWord.size();
    if(pos < Size)
        return true;
    return false;
}

//------------------SQL������(��)------------------------
//�������
/*
�磺
    CREATE TABLE student(
        name char(20),
        id int,
        class char(10),
    );
*/
bool userDatabase::CreateTable(){
    kTable newTable;
    int Size = mySql.sqlWord.size();
    if(Size < 3)
        return false;
    newTable.name = mySql.sqlWord[2];
    int i = 3;
    string name;
    int type,unit,iskey;
    // if(i < Size)
    for(; i < Size; i++){
        type = -1;
        unit = 0;
        iskey = 0;
        //��ȡ����
        name = mySql.sqlWord[i];
        i ++;
        //��ȡ����
        if(canRead(i))
            type = JudgeType(i);
        if(type == -1) return false;
        i++;
        //�жϵ�λ
        if(canRead(i) && mySql.sqlWord[i] != ","){
            if(type == 2){
                unit = JudgeUnit(i);
                i++;
            }
            if(canRead(i) && mySql.sqlWord[i] != ","){
                iskey = JudgeKey(i);
            }
        }
        if(!newTable.addColumn(name,type,unit,iskey)){
            cout << "[Error] The table have the same column!" << endl;
            return false;
        }
        //�ж�����
    }
    Size = newTable.columnName.size();
    if(FindTable(newTable.name) != -1){
        cout << "[Error] Table is existing!" << endl;
        return false;
    }
    if((int)newTable.columnName.size() == 0){
        cout << "[Error] Can't create a empty table!" << endl;
        return false;
    }
    //--------------------------------------------------------------------
    cout << "[OK] Creating tables  success." << endl;
    kLine::MakeLine(60);
    cout << "Table's name is" << " [" << newTable.name << "]" << endl;
    cout << setiosflags(ios::left);
    cout << setw(15)  << "ColumnName";
    cout << setw(10)  << "type";
    cout << setw(10)  << "unit";
    cout << setw(15)  << "key" << endl;
    for(int i = 0; i < Size; i++){
        //������
        cout << setw(15)  << newTable.columnName[i];
        //������
        if(newTable.columnType[i] == 1)
            cout << setw(10) << "int";
        if(newTable.columnType[i] == 2)
            cout << setw(10) << "char";
        //
        cout << setw(10) << newTable.columnUnit[i];
        if(newTable.isKey[i] & (1 << 0))
            cout << setw(15) << "[PRIMARY KEY] ";
        if(newTable.isKey[i] & (1 << 1))
            cout << setw(8) << "[UNIQUE] ";
        if(newTable.isKey[i] & (1 << 2))
            cout << setw(10) << "[NOT NULL]";
        cout << endl;
    }
    kLine::MakeLine(60);
    myTable.push_back(newTable);
    return true;
};
//��������
/*
    ��һ�����������
*/
bool userDatabase::InsertTable(){
    int Size = mySql.sqlWord.size();
    //int all  = 0;
    vector<string>insertname;                       //��Ҫ���������
    vector<string>value;                            //��Ҫ�����ֵ
    vector<string>insertvalue;
    int tableid;
    if(Size >= 4 && mySql.sqlWord[1] == "into"){
        string name = mySql.sqlWord[2];
        tableid = FindTable(name);
        //���ұ��Ƿ����
        if(tableid == -1){
            kLine::NotFindTable(name);
            return false;
        }
        //ȫ����ģʽ
        int tSize = myTable[tableid].columnName.size();
        if(canRead(3) && mySql.sqlWord[3] == "values"){
            for(int i = 4; i < Size; i ++){
                if(canRead(i) && mySql.sqlWord[i] != ",")
                    insertvalue.push_back(mySql.sqlWord[i]);
            }
            //�������Ŀ�ͱ��������һ��
            if((int)insertvalue.size() != tSize){
                cout << "[Error] The number of values are error!" << endl;
                return false;
            }
        }
        else{
            for(int i = 0; i < tSize; i++)  insertvalue.push_back("NULL");
            int pos = 3,iSize;
            for(;pos < Size;pos++){
                if(canRead(pos) && mySql.sqlWord[pos] == "values"){
                    pos ++;
                    break;
                }
                if(canRead(pos) && mySql.sqlWord[pos] != ",")
                    insertname.push_back(mySql.sqlWord[pos]);
            }
            for(;pos < Size;pos++){
                if(canRead(pos) && mySql.sqlWord[pos] != ",")
                    value.push_back(mySql.sqlWord[pos]);
            }
            if(insertname.size() != value.size()){
                cout << "[Error] The number of values are error!" << endl;
                return false;
            }
            iSize = insertname.size();
            for(int i = 0; i < iSize; i++){
                int id = myTable[tableid].findColumn(insertname[i]);
                if(id == -1){
                    kLine::NotFindColumn(insertname[i]);
                    return false;
                }
                insertvalue[id] = value[i];
            }
        }
    }
    else{
        return false;
    }
    //for(int i = 0; i < insertname.size(); i++)
    //    cout << insertvalue[i] << endl;
    if(myTable[tableid].insertData(insertvalue)){
        cout << "[OK] Insert Success." << endl;
        kLine::MakeLine(60);
        cout << "Value:" << endl;
        cout << "(";
        for(int i = 0; i < (int)insertvalue.size(); i++)
            cout << "'" << insertvalue[i] << "' ";
        cout << ")" << endl;
        kLine::MakeLine(60);
        return true;
    }
    else
        return false;
}
//�޸ı�
/*
    �޸�һ���������
*/
bool userDatabase::UpdateTable(){
    string name = mySql.sqlWord[1];
    int tableid = FindTable(name);
    int Size = mySql.sqlWord.size();
    if(tableid == -1){
        kLine::NotFindTable(name);
        return false;
    }
    Condition setValue,whereValue;
    int pos = 3;
    string na,sy,va;
    for(;pos < Size;pos++){
        if(canRead(pos))
            na = mySql.sqlWord[pos++];
        if(canRead(pos))
            sy = mySql.sqlWord[pos++];
        if(canRead(pos))
            va = mySql.sqlWord[pos++];
        if(!setValue.addValue(na,sy,va)){
            return false;
        }
        if(canRead(pos) && mySql.sqlWord[pos] == "where"){
            pos ++;
            break;
        }
    }

    for(;pos < Size;pos++){
        if(canRead(pos))
            na = mySql.sqlWord[pos++];
        if(canRead(pos))
            sy = mySql.sqlWord[pos++];
        if(canRead(pos))
            va = mySql.sqlWord[pos++];
        if(!whereValue.addValue(na,sy,va)){
            return false;
        }
    }
    if(myTable[tableid].findCondition(2,setValue,whereValue))
        return true;
    else
        return false;
}
//ѡ������
/*
    �����ݵĲ���
*/
bool userDatabase::SelectTable(){
    int Size = mySql.sqlWord.size();
    int from = 0,pos = 1;
    int tableid;
    Condition selectValue,whereValue;
    string name = "";
    for(;from < Size; from ++){
        if(mySql.sqlWord[from] == "from"){
            from ++;
            break;
        }
    }
    if(canRead(from)){
        name = mySql.sqlWord[from];
    }
    tableid = FindTable(name);
    if(tableid == -1){
        kLine::NotFindTable(name);
        return false;
    }
    int ok = 0;
    for(;pos < Size; pos ++){
        if(mySql.sqlWord[pos] == "from") ok = 1;
        if(!ok && mySql.sqlWord[pos] != ","){
            selectValue.addValue(string(mySql.sqlWord[pos]),string("="),string("NULL"));
        }
        if(mySql.sqlWord[pos] == "order" || mySql.sqlWord[pos] == "group" || mySql.sqlWord[pos] == "having"){
            break;
        }
        if(mySql.sqlWord[pos] == "where"){
            pos ++;
            break;
        }
    }
    string na,sy,va;
    for(;pos < Size;pos++){
        if(canRead(pos) && (mySql.sqlWord[pos] == "," || mySql.sqlWord[pos] == "and")){
            continue;
        }
        if(canRead(pos)){
            if(canRead(pos + 2) && mySql.sqlWord[pos] == "order" && mySql.sqlWord[pos + 1] == "by"){
                selectValue.orderColumn = mySql.sqlWord[pos + 2];
                if(canRead(pos + 3) && mySql.sqlWord[pos + 3] == "asc"){
                    selectValue.order = 1;
                    //cout << "ASC ";
                    //cout << selectValue.orderColumn << endl;
                    pos += 3;
                }
                else if(canRead(pos + 3) && mySql.sqlWord[pos + 3] == "desc"){
                    selectValue.order = 2;
                    //cout << "DESC ";
                    //cout << selectValue.orderColumn << endl;
                    pos += 3;
                }
                else{
                    selectValue.order = 1;
                    //cout << "ASC ";
                    //cout << selectValue.orderColumn << endl;
                    pos += 2;
                }
                continue;
            }
            if(canRead(pos + 2) && mySql.sqlWord[pos] == "group" && mySql.sqlWord[pos + 1] == "by"){
                //cout << mySql.sqlWord[pos + 2] << endl;
                pos += 2;
                continue;
            }
        }
        if(canRead(pos))
            na = mySql.sqlWord[pos++];
        if(canRead(pos))
            sy = mySql.sqlWord[pos++];
        if(canRead(pos))
            va = mySql.sqlWord[pos];
        //cout << na << " " << sy << " " << va << endl;
        if(!whereValue.addValue(na,sy,va)){
            return false;
        }
    }
    if(myTable[tableid].findCondition(1,selectValue,whereValue))
        return true;
    return true;
}
//ɾ�����
/*
    ɾ��һ����
*/
bool userDatabase::DeleteTable(){
    if(canRead(2)){
        string name = mySql.sqlWord[2];
        int tableid = FindTable(name);
        if(tableid == -1){
            kLine::NotFindTable(name);
            return false;
        }
        myTable.erase(myTable.begin() + tableid);
        //---------------------------------------
        char path[256];
        strcpy(path,"table\\");
        int j = strlen(path);
        for(int i = 0; i < (int)name.size(); i++){
            path[j++] = name[i];
        }
        path[j] = '\0';
        //---------------------------------------
        remove(path);
        cout << "[OK] Delete the table [" << name << "] success." << endl;
    }
    return true;
}
//ɾ������
/*
    ɾ�����е�һ������
*/
bool userDatabase::DeleteData(){
    int Size = mySql.sqlWord.size();
    if(mySql.sqlWord[1] == "from"){
        string name = mySql.sqlWord[2];
        int tableid = FindTable(name);
        if(tableid != -1){
            Condition selectValue,whereValue;
            if(canRead(4) && mySql.sqlWord[3]  == "where"){
                    string na,sy,va;
                    for(int pos = 4;pos < Size;pos++){
                        if(canRead(pos))
                            na = mySql.sqlWord[pos++];
                        if(canRead(pos))
                            sy = mySql.sqlWord[pos++];
                        if(canRead(pos))
                            va = mySql.sqlWord[pos++];
                        //cout << na << " " << sy << " " << va << endl;
                        if(!whereValue.addValue(na,sy,va)){
                            return false;
                        }
                    }
            }
            if(myTable[tableid].findCondition(3,selectValue,whereValue))
                return true;
            else
                return false;
        }
        else
            kLine::NotFindTable(name);
    }
    return false;
}
//������б�
bool userDatabase::InputAllTable(){
    int Size = myTable.size();
    cout << endl;
    kLine::MakeLine3(60,string("ALL TABLE"));
    cout << endl;
    for(int i = 0; i < Size; i++)
        InputTable(myTable[i].name);
    cout << endl;
    kLine::MakeLine3(60);
    cout << endl;
    return true;
}
//���һ����
/*
    ����û���ӵ�б��������Ϣ
*/
bool userDatabase::InputTable(string name){
    int tableid = FindTable(name);
    if(tableid == -1){
        kLine::NotFindTable(name);
        return false;
    }
    myTable[tableid].TableView();
    return true;
}
//------------------SQL������(��ͼ)------------------------
//ɾ����ͼ
/*
    ɾ����ͼ
*/
bool userDatabase::DeleteView(){
    if(canRead(2)){
        string name = mySql.sqlWord[2];
        int viewid = FindView(name);
        if(viewid == -1){
            kLine::NotFindView(name);
            return false;
        }
        myView.erase(myView.begin() + viewid);
        //---------------------------------------
        char path[256];
        strcpy(path,"view\\");
        int j = strlen(path);
        for(int i = 0; i < (int)name.size(); i++){
            path[j++] = name[i];
        }
        path[j] = '\0';
        //---------------------------------------
        remove(path);
        cout << "[OK] Delete view [" << name << "] success." << endl;
    }
    return false;
}

bool userDatabase::CreateView(){
    string viewname = mySql.sqlWord[2];
    if(FindView(viewname) != -1){
        cout << "[Error] View is existing!" << endl;
        return false;
    }
    int Size = mySql.sqlWord.size();
    if(Size >= 4 && mySql.sqlWord[3] == "as"){
        int from = 0,pos = 1;
        int tableid;
        kView view;
        view.viewname = viewname;
        string name = "";
        for(;from < Size; from ++){
            if(mySql.sqlWord[from] == "from"){
                from ++;
                break;
            }
        }
        if(canRead(from)){
            name = mySql.sqlWord[from];
        }
        tableid = FindTable(name);
        if(tableid == -1){
            kLine::NotFindTable(name);
            return false;
        }
        //��ͼ���ڵı�����
        view.tablename = name;
        int ok = 0;
        for(;pos < Size;pos++)
            if(mySql.sqlWord[pos] == "select"){
                pos ++;
                break;
            }
        for(;pos < Size; pos ++){
            if(mySql.sqlWord[pos] == "from") ok = 1;
            if(!ok && mySql.sqlWord[pos] != ","){
                view.selectColumn.addValue(string(mySql.sqlWord[pos]),string("="),string("NULL"));
            }
            if(mySql.sqlWord[pos] == "where"){
                pos ++;
                break;
            }
        }
        string na,sy,va;
        for(;pos < Size;pos++){
            if(canRead(pos))
                na = mySql.sqlWord[pos++];
            if(canRead(pos))
                sy = mySql.sqlWord[pos++];
            if(canRead(pos))
                va = mySql.sqlWord[pos++];
            if(!view.whereRow.addValue(na,sy,va)){
                return false;
            }
        }
        myView.push_back(view);
        InputView(viewname);
        return true;
    }
    return false;
}

bool userDatabase::InputView(string name){
    int viewid = FindView(name);
    if(viewid == -1){
        kLine::NotFindView(name);
        return false;
    }
    else{
        int tableid = FindTable(myView[viewid].tablename);
        if(tableid == -1){
            cout << "[Error] Can't find the table for the view" << endl;
            return false;
        }
        if(myTable[tableid].findCondition(4,myView[viewid].selectColumn,myView[viewid].whereRow)){
            return true;
        }
        else{
            myView.erase(myView.begin() + viewid);
            cout << "[Warning] The error view has been deleted" << endl;
            return false;
        }
    }
    return false;
}

bool userDatabase::InputAllView(){
    int Size = myView.size();
    cout << endl;
    kLine::MakeLine3(60,string("ALL VIEW"));
    cout << endl;
    for(int i = 0; i < Size;i++){
        kLine::MakeLine(60,myView[i].viewname);
        InputView(myView[i].viewname);
    }
    cout << endl;
    kLine::MakeLine3(60);
    cout << endl;
    return true;
}

//------------------SQL������(����)-------------------------
/*
    ��������
*/
bool userDatabase::CreateIndex(){
    kIndex newindex;
    newindex.name = mySql.sqlWord[3];
    int Size = mySql.sqlWord.size();
    if(FindIndex(newindex.name) != -1){
        cout << "[Error] The index has existing!" << endl;
        return false;
    }
    if(mySql.sqlWord[1] == "unique") newindex.itype = 1;
    if(mySql.sqlWord[1] == "cluster")newindex.itype = 2;

    if(newindex.itype == 0){
        cout << "[Error] The type of the index is wrong!" << endl;
        return false;
    }

    newindex.tablename = mySql.sqlWord[5];
    int tid = FindTable(newindex.tablename);
    if(tid == -1){
        kLine::NotFindTable(newindex.tablename);
        return false;
    }
    for(int pos = 6; pos < Size; pos++){
        string column = mySql.sqlWord[pos];
        if(column == "," || column == "and")
            continue;
        int cid = myTable[tid].findColumn(column);
        if(cid == -1){
            kLine::NotFindColumn(column);
            return false;
        }
        newindex.column.push_back(column);
        if(pos + 1 < Size){
            if(mySql.sqlWord[pos + 1] == "asc"){
                newindex.type.push_back(1);
                pos ++;
            }
            if(mySql.sqlWord[pos + 1] == "desc"){
                newindex.type.push_back(2);
                pos ++;
            }
            else{
                newindex.type.push_back(1);
            }
        }
        else
            newindex.type.push_back(1);
    }
    myIndex.push_back(newindex);
    cout << "[OK] Create index success!" << endl;
    InputIndex(newindex.name);
    return true;
}

bool userDatabase::InputIndex(string index){
    int iid = FindIndex(index);
    if(iid == -1){
        kLine::NotFindIndex(index);
        return false;
    }
    myIndex[iid].InputView();
    return true;
}

bool userDatabase::InputAllIndex(){
    int Size = myIndex.size();
    cout << endl;
    kLine::MakeLine3(60,string("ALL Index"));
    cout << endl;
    for(int i = 0; i < Size;i++){
        kLine::MakeLine(60,myIndex[i].name);
        InputIndex(myIndex[i].name);
    }
    cout << endl;
    kLine::MakeLine3(60);
    cout << endl;
    return true;
}
//------------------Ȩ�޲���--------------------------------
/*
GRANT ALL PRIVILEGES
ON student TO Hanshukai;
*/
int userDatabase::JudgeGrant(int &pos){
    if(mySql.sqlWord[pos] == "select"){
        pos ++;
        return 1;
    }
    if(mySql.sqlWord[pos] == "all" && mySql.sqlWord[pos + 1] == "privileges"){
        pos += 2;
        return 2;
    }
    return -1;
}
//
bool userDatabase::GrantToUser(){
    int pos = 1;
    int type = JudgeGrant(pos);
    int Size = mySql.sqlWord.size();
    string tablename;
    string username;
    int step = 0;
    //cout << type << endl;
    if(type == -1){
        return false;
    }
    for(;pos < Size; pos++){
        if(mySql.sqlWord[pos] == "on"){
            pos ++;
            break;
        }
    }
    for(;pos < Size;pos ++){
        if(step == 0){
            tablename = mySql.sqlWord[pos];
            step ++;
        }
        else if(step == 1 && mySql.sqlWord[pos] == "to"){
            step ++;
        }
        else if(step == 2){
            username = mySql.sqlWord[pos];
            step ++;
            break;
        }
    }

    if(step == 3){
        int id = FindTable(tablename);
        if(id == -1){
            kLine::NotFindTable(tablename);
            return false;
        }
        //���ж��Լ��Ƿ���Ȩ��
        if(type == 1){
            if(!myTable[id].can_read){
                cout << "[Warning] You do not have permission!" << endl;
                return false;
            }
            userDatabase user(username);
            int tid = user.FindTable(tablename);
            if(tid == -1){
                kTable newtable;
                newtable.name = tablename;
                save.getTable(newtable);
                user.myTable.push_back(newtable);
                newtable.can_read  = true;
                newtable.can_write = false;
            }
            else{
                user.myTable[tid].can_read = true;
            }
            cout << "[OK] User [" << username  << "] has the permission of [" << tablename << "] (select)" << endl;
            return true;
        }
        if(type == 2){
            if(!myTable[id].can_read || !myTable[id].can_write){
                cout << "[Warning] You do not have permission!" << endl;
                return false;
            }
            userDatabase user(username);
            int tid = user.FindTable(tablename);
            if(tid == -1){
                kTable newtable;
                newtable.name = tablename;
                save.getTable(newtable);
                user.myTable.push_back(newtable);
                newtable.can_read  = true;
                newtable.can_write = true;
            }
            else{
                user.myTable[tid].can_read  = true;
                user.myTable[tid].can_write = true;
            }
            cout << "[OK] User [" << username  << "] has the permission of [" << tablename << "] (all)" << endl;
            return true;
        }
    }
    return false;
}
