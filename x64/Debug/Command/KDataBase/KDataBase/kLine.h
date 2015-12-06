#ifndef KLINE_H_INCLUDED
#define KLINE_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class kLine{
public:
    static void MakeLine(int n,string name = "");
    static void MakeLine2(int n,string name = "");
    static void MakeLine3(int n,string name = "");
    static void NotFindTable(string name);
    static void NotFindColumn(string name);
    static void NotFindView(string name);
    static void NotFindIndex(string name);
};
#endif // KLINE_H_INCLUDED
