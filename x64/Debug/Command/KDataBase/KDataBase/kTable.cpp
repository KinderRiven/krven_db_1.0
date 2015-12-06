#include "kTable.h"
/*
����ṹ��
*/
struct ORDER_BY{
    string name;
    int id;
};
vector<ORDER_BY>order_vec;
bool cmp_asc(ORDER_BY o1,ORDER_BY o2){
    return o1.name < o2.name;
}
bool cmp_desc(ORDER_BY o1,ORDER_BY o2){
    return o1.name > o2.name;
}

/*
���캯��
*/
kTable::kTable(){
    dataNumber = 0;
    can_read = true;
    can_write = true;
}
kTable::~kTable(){

}
/*
���һ�У���Ҫ֪���е����֣��Ƿ�Ϊ�������е�����
*/
bool kTable::addColumn(string name, int type,int unit,int iskey){
	if (findColumn(name) != -1)
		return false;
	columnName.push_back(name);
	columnType.push_back(type);
	columnUnit.push_back(unit);
	isKey.push_back(iskey);
	string data("NULL");
	for(int i = 0; i < dataNumber; i++){
		tableData[i].push_back(data);
	}
	return true;
};

/*
Ѱ��ĳ�У������е�id����������ڷ���-1
*/
int kTable::findColumn(string name){
    int Size = columnName.size();
	for (int i = 0; i < Size; i++){
		if (columnName[i] == name)
			return i;
	}
	return -1;
};

/*
�ж��е�ֵ�Ƿ��ظ�
*/
bool kTable::judgeColnmn(string name, int type, int id){
	if (tableData[id][type] == name)
		return true;
	return false;
};

/*
    ��������
    �Բ�������ݵ��Ƿ�Ϊkey unique �Լ� not null�ж�
*/
bool kTable::insertData(vector<string>data){
    int Size = data.size();
    tableData[dataNumber].clear();
    //���ж�PRIMARY�Ƿ�Ϊ��
    for(int i = 0; i < Size; i++){
        if(data[i] == "NULL" && isKey[i] & (1 << 0)){
            cout << "[Error] The key is empty!" << endl;
            return false;
        }
        if(data[i] == "NULL" && isKey[i] & (1 << 2)){
            cout << "[Error] The column [" << columnName[i] << "]" << " is empty!" << endl;
            return false;
        }
    }
    //�ж��Ƿ��ظ�
    for(int i = 0; i < Size; i++)if(data[i] != "NULL" && ((isKey[i] & (1 << 1)) || (isKey[i] & (1 << 0)))){
        for(int j = 0; j < dataNumber; j++){
            if(tableData[j][i] == data[i]){
                cout << "[Error] The column [" << columnName[i] << "]" << " is same!" << endl;
                return false;
            }
        }
    }
    //�������ݵĲ���
    for(int i = 0; i < Size; i++){
        tableData[dataNumber].push_back(data[i]);
    }
    dataNumber ++;
    return true;
}

/*
    ���������ͼ
*/
void kTable::TableView(){
    //�����Ľṹ
    kLine::MakeLine(60,string("TableView"));
    int Size = columnName.size();
    cout << name << endl;
    cout << "(" << endl;
    for(int i = 0; i < Size; i++){
        cout << setw(5) << " ";
        cout << setw(10) << columnName[i];
        if(columnType[i] == 1)
            cout << " int";
        if(columnType[i] == 2)
            cout << " char";
        if(columnUnit[i] != 0)
            cout << "(" << columnUnit[i] << ")";
        cout << "," << endl;
    }
    cout << ")";
    cout << ";" << endl;
    //��������Ϣ
    kLine::MakeLine(60,string("TableData"));
    cout << setiosflags(ios::left);
    for(int i = 0; i < Size; i++)
        cout << setw(15) << columnName[i];
    cout << endl;
    for(int i = 0; i < dataNumber; i++){
        for(int j = 0; j < (int)tableData[i].size(); j++)
            cout << setw(15) << tableData[i][j];
        cout << endl;
    }
}

/*
    s1�ǲ�������
    s2����������
*/
bool kTable::findCondition(int action,Condition s1,Condition s2){
    int Size = s2.name.size();
    whereRow.clear();
    //ɸѡ�������������� ����whereRow��
    if(s2.name.size() == 0){
            for(int i = 0; i < dataNumber; i++)
                whereRow.push_back(i);
    }
    else{
        for(int i = 0; i < dataNumber; i++){
            int ok = 1;
            for(int j = 0; j < Size; j++){
                int cid = findColumn(s2.name[j]);
                if(cid == -1){
                    kLine::NotFindColumn(s2.name[j]);
                    return false;
                }
                if(!conditionJudge(tableData[i][cid],s2.symbol[j],s2.value[j])){
                    ok = 0;
                    break;
                }
            }
            if(ok)
                whereRow.push_back(i);
        }
    }
    if(action == 1){
        if(!selectData(s1))
            return false;
    }
    if(action == 2){
        if(!changeData(s1))
            return false;
    }
    if(action == 3){
        if(!deleteData(s1))
            return false;
    }
    if(action == 4){
        if(!inputView(s1)){
            return false;
        }
    }
    return true;
}

/*
    �ж�����
*/
bool kTable::conditionJudge(string a,int b,string c){
    if(b == 1){ // =
        if(a == c)
            return true;
    }
    if(b == 2){ // >

    }
    if(b == 3){ // <

    }
    return false;
}

/*
    �޸�����
*/
bool kTable::changeData(Condition s){
    //���жϺ��Ƿ����
    vector<int>col;
    int Size = s.name.size();
    for(int i = 0; i < Size; i++){
        int temp = findColumn(s.name[i]);
        if(temp == -1){
            kLine::NotFindColumn(s.name[i]);
            return false;
        }
        col.push_back(temp);
    }
    for(int i = 0; i < Size; i++){
        for(int j = 0; j < (int)whereRow.size(); j++){
            int ss = whereRow[j],cc = col[i];
            if(s.symbol[i] == 1){
                tableData[ss][cc] = s.value[i];
            }
        }
    }
    cout << "[OK] Updata successful." << endl;
    cout << "You have updated the data as follows : " << endl;
    kLine::MakeLine(60);
    cout << setiosflags(ios::left);
    for(int i = 0; i < (int)columnName.size(); i++)
        cout << setw(15) << columnName[i];
    cout << endl;
    for(int i = 0; i < (int)whereRow.size(); i++){
        for(int j = 0; j < (int)columnName.size(); j++){
            int ss = whereRow[i];
            cout << setw(15) << tableData[ss][j];
        }
        cout << endl;
    }
    kLine::MakeLine(60);
    return true;
}

/*
    ѡ������
*/
bool kTable::selectData(Condition s){
    vector<int>col;     //��Ҫ�������
    int Size = columnName.size();
    if(s.name.size() >= 1 && s.name[0] == "*"){
        for(int i = 0; i < Size; i++)
            col.push_back(i);
    }
    else{
        //�����������
        for(int i = 0; i < (int)s.name.size(); i++){
            int id = findColumn(s.name[i]);
            if(id == -1){
                kLine::NotFindColumn(s.name[i]);
                return false;
            }
            col.push_back(id);
        }
    }
    if(s.order){
        order_vec.clear();
        int col_id = findColumn(s.orderColumn);
        if(col_id == -1){
            kLine::NotFindColumn(s.orderColumn);
            return false;
        }
        ORDER_BY temp_by;
        for(int i = 0; i < (int)whereRow.size(); i++){
            temp_by.name =  tableData[whereRow[i]][col_id];
            temp_by.id = whereRow[i];
            order_vec.push_back(temp_by);
        }
        if(s.order == 1)
            sort(order_vec.begin(),order_vec.end(),cmp_asc);
        else
            sort(order_vec.begin(),order_vec.end(),cmp_desc);

        for(int i = 0; i < (int)whereRow.size(); i++){
            whereRow[i] = order_vec[i].id;
        }
    }
    cout << "[OK] The data you select as follows:" << endl;
    kLine::MakeLine(60);
    cout << setiosflags(ios::left);
    for(int i = 0; i < (int)col.size(); i++)
            cout << setw(15) << columnName[col[i]];
    cout << endl;
    for(int i = 0; i < (int)whereRow.size(); i++){
        for(int j = 0; j < (int)col.size(); j++){
            cout << setw(15) << tableData[whereRow[i]][col[j]];
        }
        cout << endl;
    }
    return true;
}
/*
    �������ݵ�ɾ��
*/
bool kTable::deleteData(Condition s){
    cout << "The data you delete as follows:" << endl;
    kLine::MakeLine(60);
    cout << setiosflags(ios::left);
    for(int i = 0; i < (int)columnName.size(); i++)
            cout << setw(15) << columnName[i];
    cout << endl;
    for(int i = 0; i < (int)whereRow.size(); i++){
        for(int j = 0; j < (int)columnName.size(); j++){
            cout << setw(15) << tableData[whereRow[i]][j];
        }
        cout << endl;
    }
    kLine::MakeLine(60);
    for(int i = 0; i < (int)whereRow.size(); i++){
        tableData[whereRow[i]].clear();
    }
    int j = 0;
    for(int i = 0; i < dataNumber; i++){
        if(tableData[i].size() != 0){
                tableData[j++] = tableData[i];
        }
    }
    dataNumber = j;
    return true;
}
/*
    ���������������ͼ
*/
bool kTable::inputView(Condition s){
    vector<int>col;     //��Ҫ�������
    //printf("%d\n",s.name.size());
    int Size = columnName.size();
    if(s.name.size() >= 1 && s.name[0] == "*"){
        for(int i = 0; i < Size; i++)
            col.push_back(i);
    }
    else{
        //�����������
        for(int i = 0; i < (int)s.name.size(); i++){
            int id = findColumn(s.name[i]);
            if(id == -1){
                cout << "Can't find column [" << s.name[i] << " ]" << endl;
                return false;
            }
            col.push_back(id);
        }
    }
    kLine::MakeLine(60);
    cout << setiosflags(ios::left);
    for(int i = 0; i < (int)col.size(); i++)
            cout << setw(15) << columnName[col[i]];
    cout << endl;
    for(int i = 0; i < (int)whereRow.size(); i++){
        for(int j = 0; j < (int)col.size(); j++){
            cout << setw(15) << tableData[whereRow[i]][col[j]];
        }
        cout << endl;
    }
    kLine::MakeLine(60);
    return true;
}

/*
    �ַ���stringת��Ϊint
*/
bool kTable::stringToInt(string str,int &value){
    value = 0;
    for(int i = 0; i < (int)str.size(); i++){
        value = 10 * value + str[i] - '0';
    }
    return true;
}
