#ifndef READSQL_H_INCLUDED
#define READSQL_H_INCLUDED
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class readSQL{
public:
    char str[1005];             //总输入
    vector<string>sqlWord;      //SQL分段之后
    int read();                 //读入SQL语句
    void GetSql();              //SQL语句分段
    int SqlJudge();             //SQL语句功能判断
    bool readJudge(char m);     //读入判断
    bool judgeSymbol(char m);   //判断断句符号
};


#endif // READSQL_H_INCLUDED
