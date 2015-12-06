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
                                                //添加数据
	int  findColumn(string name);			    //根据列的名字找到第几列
	bool judgeColnmn(string name, int type,int id);
	bool insertData(vector<string>data);        //插入数据
    bool findCondition(int action,Condition s1,Condition s2);
                                                //找到符合条件的行,并执行动作
    bool conditionJudge(string a,int b,string c);
                                                //判断条件分析
    bool changeData(Condition s);               //修改数据
    bool selectData(Condition s);               //选择数据
    bool deleteData(Condition s);               //删除数据
    bool inputView(Condition  s);               //输出视图
	void TableView();                           //输出表的所有信息
	bool stringToInt(string str,int & value);   //string to int
//private:
    //表的定义
    string name;                            //表名字
	vector<string>columnName;				//列名字
	vector<int>columnType;					//列种类
	vector<int>columnUnit;                  //列种类的单位
	vector<int>isKey;                       //条件
	vector<string>tableData[dataMaxNum];	//表信息
	int dataNumber;                         //表中信息数量
	bool can_read;
	bool can_write;
	//辅助变量的定义
	vector<int>whereRow;                    //符合条件的行
};
//-------------------------------------------------------------------


#endif // KTABLE_H_INCLUDED
