#ifndef KINDEX_H_INCLUDED
#define KINDEX_H_INCLUDED
#include <vector>
#include <string>
#include "kLine.h"
#include <iostream>
#include <iomanip>
using namespace std;
/*
    unique 1
    cluster 2
*/
class kIndex{
public:
    string name;
    string tablename;
    vector<string>column;
    vector<int>type;
    int itype;
    kIndex();
    void InputView();
};

#endif // KINDEX_H_INCLUDED
