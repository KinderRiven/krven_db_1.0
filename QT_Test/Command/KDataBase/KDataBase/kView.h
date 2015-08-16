#ifndef KVIEW_H_INCLUDED
#define KVIEW_H_INCLUDED
#include<string>
#include "condition.h"
using namespace std;
class kView{
public:
    string tablename;
    string viewname;
    Condition selectColumn;
    Condition whereRow;
};
#endif // KVIEW_H_INCLUDED
