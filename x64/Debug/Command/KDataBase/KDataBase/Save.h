#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED
#include "kTable.h"
#include "kView.h"
#include "kIndex.h"
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
class Save{
public:
    bool saveTable(kTable &table);
    bool getTable (kTable &table);
    bool saveView (kView  &view);
    bool getView  (kView  &view);
    bool saveIndex(kIndex &index);
    bool getIndex(kIndex &index);
};


#endif // SAVE_H_INCLUDED
