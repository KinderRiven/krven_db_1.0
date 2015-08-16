#include "kIndex.h"
kIndex::kIndex(){
    itype = 0;
}

void kIndex::InputView(){
    //输出表的结构
    kLine::MakeLine(60,string("IndexView"));
    int Size = column.size();
    cout << name << " for " << tablename << " [";
    if(itype == 1)
        cout << "UNIQUE";
    if(itype == 2)
        cout << "CLUSTER";
    cout << "]" << endl;
    cout << "(" << endl;
    for(int i = 0; i < Size; i++){
        cout << setw(5) << " ";
        cout << setw(10) << column[i];
        if(type[i] == 1)
            cout << " ASC";
        if(type[i] == 2)
            cout << " DESC";
        cout << "," << endl;
    }
    cout << ")";
    cout << ";" << endl;
    //输出表的信息
}
