#pragma once
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
//-----------------------------------------------
#include <QtCore>
#include <qmenu.h>
#include <qaction.h>
#include <qsound.h>
#include <algorithm>
#include <qpixmap.h>
#include <qwidget.h>
#include <QtWidgets>
#include <qpainter.h>
#include <QDesktopWidget>
#include "ui_MainWindow.h"
//---------------------------------------------------
using namespace std;
//----------------------------------------------------
#include "UserData.h"
#include "UserWindow.h"
#include "MainWindow.h"
/*
	�û���
*/
class MainDataBase
{
public:
	MainDataBase();
	~MainDataBase();
	MainWindow mainWindow;
	void Kshow();
};

