#ifndef USERDATABASE_H_INCLUDED
#define USERDATABASE_H_INCLUDED
#include "help.h"
#include "Save.h"
#include "kView.h"
#include "kTable.h"
#include "readSQL.h"
#include "condition.h"
#include "kLine.h"
#include <iomanip>
#include <fstream>
#include "kView.h"
#include "kIndex.h"
using namespace std;
class userDatabase{
public:
    userDatabase(string user = "guest");
    ~userDatabase();
    bool userStart();               //�û�������
    bool userGetTable();            //�û���ȡ���ļ�
    bool userGetView();             //�û���ȡ��ͼ��
    bool userGetIndex();
    bool userRead();                //SQL����ȡ

    bool CreateTable();             //������
    bool InsertTable();             //����в���Ԫ��
    bool SelectTable();             //���ұ�
    bool DeleteTable();             //ɾ�����
    bool DeleteData();              //ɾ������ڵ�����
    bool UpdateTable();             //�޸ı������
    bool InputTable(string name);   //���һ����
    bool InputAllTable();           //������б����ͼ

    bool CreateView();              //������ͼ
    bool DeleteView();
    bool InputView(string name);    //���һ����ͼ
    bool InputAllView();            //���������ͼ

    bool CreateIndex();             //����һ������
    bool InputIndex(string name);
    bool InputAllIndex();           //�����������

    bool canRead(int pos);          //���߽��ж�
    int  JudgeType(int pos);        //�ж�����
    int  JudgeKey (int &pos);       //�жϼ�ֵ
    int  JudgeUnit(int pos);        //�ж��Ƿ�Ϊ����
    bool GrantToUser();             //��Ȩ����
    int  JudgeGrant(int &pos);
    int  FindTable(string name);    //���ұ�
    int  FindView(string name);
    int  FindIndex(string name);    //������ͼ

    vector<kTable>myTable;
    vector<kView>myView;
    vector<kIndex>myIndex;
    string username;

    Help readme;
    readSQL mySql;
    Save save;
};


#endif // USERDATABASE_H_INCLUDED
