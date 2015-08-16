#ifndef CONDITION_H_INCLUDED
#define CONDITION_H_INCLUDED
#include<vector>
#include<string>
using namespace std;
/*
symbol:
    1. =
    2. >
    3. <
    4. !=
order:
    0.
    1. ASD
    2. DESC
*/
class Condition{
public:
    vector<string>name;
    vector<int>symbol;
    vector<string>value;
    int order;
    string orderColumn;
    void init();
    bool addValue(string name,string symbol,string value);
    Condition();
};


#endif // CONDITION_H_INCLUDED
