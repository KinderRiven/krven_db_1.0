#include"condition.h"
Condition::Condition(){
    order = 0;          //����״̬��ʼ��
}

/*
��ʼ������
*/
void Condition::init(){
    name.clear();
    symbol.clear();
    value.clear();
    order = 0;
};

/*
�����������
*/
bool Condition::addValue(string na,string sy,string va){
    int sym;
    if(sy == "=")
        sym = 1;
    else if(sy == ">")
        sym = 2;
    else if(sy == "<")
        sym = 3;
    else if(sy == "!=")
        sym = 4;
    else
        return false;
    name.push_back(na);
    symbol.push_back(sym);
    value.push_back(va);
    return true;
};
