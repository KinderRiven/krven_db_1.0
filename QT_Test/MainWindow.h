#ifndef MainWindow_H
#define MainWindow_H

#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
//-------------------QT--------------------------------
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
//----------------------------------------------------
#include <dataBase\userDatabase.h>
//----------------------------------------------------
using namespace std;
//----------------------------------------------------
#include "UserWindow.h"
#include "WarningWindows.h"
#include "HelpWindow.h"
#include "tableview.h"
/*
	主窗口函数
*/
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void TimeStart();							//定时器函数
	void UserAction();							//用户菜单信号槽
	void DatabaseAction();						//数据库菜单信号槽
	void HelpAction();							//帮助界面信号槽
	void ExitAction();							//退出界面信号槽
	void CommandAction();						//命令行信号槽
	void LoadMusic();							//载入音乐函数
	void changeAction();						//改变动作函数
	QString getImage(QString fileName,int id);	//获得图片动作函数


protected:
	void timerEvent(QTimerEvent *event);
	void paintEvent(QPaintEvent *);				//图片绘制函数
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent *event);
private:
	Ui::MainWindowClass ui;			//ui
	int image_id;					//图片序号
	int nowAction;					//当前动作
	int timeid[128];				//时间

	QAction *menuAction[10];		//菜单指针
	QPoint  preMousePos;			//上次鼠标位置记录
	QPixmap image;					//窗口图片
	QString systemMusic,exitMusic;	//音乐文件
	QString imageFile;				//动作图片的路径
	                              
	//功能接口
	UserWindow userWindows;			//用户窗口
	HelpWindow userHelp;			//帮助窗口
	tableView  tableview;
};

#endif // MainWindow_H
