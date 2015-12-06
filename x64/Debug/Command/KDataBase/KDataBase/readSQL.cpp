#include "readSQL.h"
#include <string.h>
void readSQL::GetSql(){
    int cnt = 0,L = strlen(str);
    char s[1005];
    int canread = 0;
    //实现分号内语句的归一
    for(int i = 0; i <= L; i++){
        if(str[i] == '\'')
            canread ^= 1;
        if(((readJudge(str[i]) || canread)) && str[i] != '\''){
                if(canread == 1)
                    s[cnt++] = str[i];
                else{
                    if(str[i] >= 'A' && str[i] <= 'Z')
                        str[i] += 32;
                    s[cnt++] = str[i];
                }
        }
        else if(canread != 1){
            if(cnt){
                s[cnt] = '\0';
                sqlWord.push_back(string(s));
                cnt = 0;
            }
            if(judgeSymbol(str[i])){
                string temp = "";
                temp += str[i];
                sqlWord.push_back(temp);
            }
        }
    }
    //for(int i = 0; i < (int)sqlWord.size(); i++)
    //    cout << sqlWord[i] << endl;
}

int readSQL::SqlJudge(){
    int Size = sqlWord.size();
    //exit 0
    if(Size >= 1 && sqlWord[0] == "exit")            //EXIT
        return 0;
    //创建 1 ~ 9
    if(Size >= 1 && sqlWord[0] == "create"){         //CREATE
        if(Size >= 3 && sqlWord[1] == "table")       //CREATE TABLE
            return 1;
        if(Size >= 3 && sqlWord[1] == "view")
            return 2;
        if(Size >= 6 && sqlWord[2] == "index")
            return 3;
    }
    //操作 10 ~ 19
    if(Size >= 1 && sqlWord[0] == "insert")          //INSERT
        return 10;
    if(Size >= 1 && sqlWord[0] == "select")          //SELECT
        return 11;
    if(Size >= 3 && sqlWord[0] == "drop" && sqlWord[1] == "table") //DROP TABLE
        return 12;
    if(Size >= 1 && sqlWord[0] == "update")         //UPDATE
        return 13;
    if(Size >= 3 && sqlWord[0] == "delete")
        return 14;
    if(Size >= 3 && sqlWord[0] == "drop" && sqlWord[1] == "view")
        return 15;
    if(Size >= 6 && sqlWord[0] == "grant")
        return 16;
    //帮助 20~29
    if(Size >= 2 && sqlWord[0] == "help"){
        if(sqlWord[1] == "create")
            return 20;
        if(sqlWord[1] == "select")
            return 21;
        if(sqlWord[1] == "insert")
            return 22;
        if(sqlWord[1] == "drop")
            return 23;
        if(sqlWord[1] == "update")
            return 24;
        if(sqlWord[1] == "data")
            return 25;
        if(sqlWord[1] == "table")
            return 26;
        if(sqlWord[1] == "view")
            return 27;
        if(sqlWord[1] == "index")
            return 28;
    }
    return -1;
};

int readSQL::read(){
    char m;
    int  cnt;
    cnt = 0;
    sqlWord.clear();
    while((m = getchar())!= ';'){
        str[cnt++] = m;
    }
    str[cnt] = '\0';
    GetSql();
    return SqlJudge();
};

bool readSQL::readJudge(char m){
    if(m >= '0' && m <= '9') return true;
    if(m >= 'a' && m <= 'z') return true;
    if(m >= 'A' && m <= 'Z') return true;
    if(m == '_') return true;
    if(m == '*') return true;
    return false;
};

bool readSQL::judgeSymbol(char m){
    if(m == ',')
        return true;
    if(m == '=')
        return true;
    if(m == '>')
        return true;
    if(m == '<')
        return true;
    return false;
};

