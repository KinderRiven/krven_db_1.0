#include "userDatabase.h"
#include "Help.h"
#include "Help.cpp"
#include "kLine.h"
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
char name[256];
int main(){
    //----------------Test----------------------------
    //------------------------------------------------
    fstream fr;
    fr.open("nowuser.txt",ios::in | ios::out);
    while(!fr.eof()){
        fr.getline(name,256);
    }
    fr.close();
    string sname(name);
    userDatabase userk(sname);
    //-----------------------------------------------
    cout << "Database  Software(1.0.0)" << endl;
    cout << "(c) 2015 Han Shukai ( IOT 13 - 1 )" << endl;
    while(userk.userRead());
    return 0;
}
