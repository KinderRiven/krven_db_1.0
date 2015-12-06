#ifndef KTABLE_H_INCLUDED
#define KTABLE_H_INCLUDED
#include<set>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include "Condition.h"
#include "kLine.h"
using namespace std;
//------------------------------------------------------------------
/*
    int is 1
    char is 2
*/
//-------------------------TABLE------------------------------------
const int dataMaxNum = 1005;
class kTable{
public:
	kTable();
	~kTable();
	bool addColumn(string name,int type,int unit,int iskey);
                                                //�������
	int  findColumn(string name);			    //�����е������ҵ��ڼ���
	bool judgeColnmn(string name, int type,int id);
	bool insertData(vector<string>data);        //��������
    bool findCondition(int action,Condition s1,Condition s2);
                                                //�ҵ�������������,��ִ�ж���
    bool conditionJudge(string a,int b,string c);
                                                //�ж���������
    bool changeData(Condition s);               //�޸�����
    bool selectData(Condition s);               //ѡ������
    bool deleteData(Condition s);               //ɾ������
    bool inputView(Condition  s);               //�����ͼ
	void TableView();                           //������������Ϣ
	bool stringToInt(string str,int & value);   //string to int
//private:
    //��Ķ���
    string name;                            //������
	vector<string>columnName;				//������
	vector<int>columnType;					//������
	vector<int>columnUnit;                  //������ĵ�λ
	vector<int>isKey;                       //����
	vector<string>tableData[dataMaxNum];	//����Ϣ
	int dataNumber;                         //������Ϣ����
	bool can_read;
	bool can_write;
	//���������Ķ���
	vector<int>whereRow;                    //������������
};
//-------------------------------------------------------------------


#endif // KTABLE_H_INCLUDED
