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
    bool userStart();               //用户启动区
    bool userGetTable();            //用户读取表文件
    bool userGetView();             //用户读取视图表
    bool userGetIndex();
    bool userRead();                //SQL语句读取

    bool CreateTable();             //创建表
    bool InsertTable();             //向表中插入元素
    bool SelectTable();             //查找表
    bool DeleteTable();             //删除表格
    bool DeleteData();              //删除表格内的数据
    bool UpdateTable();             //修改表的数据
    bool InputTable(string name);   //输出一个表
    bool InputAllTable();           //输出所有表的视图

    bool CreateView();              //创建视图
    bool DeleteView();
    bool InputView(string name);    //输出一个视图
    bool InputAllView();            //输出所有视图

    bool CreateIndex();             //创建一个索引
    bool InputIndex(string name);
    bool InputAllIndex();           //输出所有索引

    bool canRead(int pos);          //语句边界判断
    int  JudgeType(int pos);        //判断类型
    int  JudgeKey (int &pos);       //判断键值
    int  JudgeUnit(int pos);        //判断是否为数字
    bool GrantToUser();             //提权操作
    int  JudgeGrant(int &pos);
    int  FindTable(string name);    //查找表
    int  FindView(string name);
    int  FindIndex(string name);    //查找视图

    vector<kTable>myTable;
    vector<kView>myView;
    vector<kIndex>myIndex;
    string username;

    Help readme;
    readSQL mySql;
    Save save;
};


#endif // USERDATABASE_H_INCLUDED
