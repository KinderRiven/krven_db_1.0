#ifndef READSQL_H_INCLUDED
#define READSQL_H_INCLUDED
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class readSQL{
public:
    char str[1005];             //������
    vector<string>sqlWord;      //SQL�ֶ�֮��
    int read();                 //����SQL���
    void GetSql();              //SQL���ֶ�
    int SqlJudge();             //SQL��书���ж�
    bool readJudge(char m);     //�����ж�
    bool judgeSymbol(char m);   //�ж϶Ͼ����
};


#endif // READSQL_H_INCLUDED
