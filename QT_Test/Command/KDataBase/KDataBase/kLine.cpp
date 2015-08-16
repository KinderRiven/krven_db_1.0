#include "kLine.h"
//打印一条长度为n的-
void kLine::MakeLine(int n,string name){
    int Size = name.size();
    int d = (n - Size) / 2;
    for(int i = 0; i < d; i++)
        cout << "-";
    cout << name;
    for(int i = 0; i < d; i++)
        cout << "-";
    cout << endl;
}

//打印一条长度为n的=
void kLine::MakeLine2(int n,string name){
    int Size = name.size();
    int d = (n - Size) / 2;
    for(int i = 0; i < d; i++)
        cout << "=";
    cout << name;
    for(int i = 0; i < d; i++)
        cout << "=";
    cout << endl;
}

//打印一条长度为n的*
void kLine::MakeLine3(int n,string name){
    int Size = name.size();
    int d = (n - Size) / 2;
    for(int i = 0; i < d; i++)
        cout << "*";
    cout << name;
    for(int i = 0; i < d; i++)
        cout << "*";
    cout << endl;
}

void kLine::NotFindTable(string name){
    cout << "[Error] Can not find the table [" << name << "]" << endl;
}
void kLine::NotFindColumn(string name){
    cout << "[Error] Can not find the column [" << name << "]" << endl;
}

void kLine::NotFindView(string name){
    cout << "[Error] Can not find the view [" << name << "]" << endl;
}

void kLine::NotFindIndex(string name){
    cout << "[Error] Can not find the index [" << name << "]" << endl;
}

