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
	�����ں���
*/
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void TimeStart();							//��ʱ������
	void UserAction();							//�û��˵��źŲ�
	void DatabaseAction();						//���ݿ�˵��źŲ�
	void HelpAction();							//���������źŲ�
	void ExitAction();							//�˳������źŲ�
	void CommandAction();						//�������źŲ�
	void LoadMusic();							//�������ֺ���
	void changeAction();						//�ı䶯������
	QString getImage(QString fileName,int id);	//���ͼƬ��������


protected:
	void timerEvent(QTimerEvent *event);
	void paintEvent(QPaintEvent *);				//ͼƬ���ƺ���
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent *event);
private:
	Ui::MainWindowClass ui;			//ui
	int image_id;					//ͼƬ���
	int nowAction;					//��ǰ����
	int timeid[128];				//ʱ��

	QAction *menuAction[10];		//�˵�ָ��
	QPoint  preMousePos;			//�ϴ����λ�ü�¼
	QPixmap image;					//����ͼƬ
	QString systemMusic,exitMusic;	//�����ļ�
	QString imageFile;				//����ͼƬ��·��
	                              
	//���ܽӿ�
	UserWindow userWindows;			//�û�����
	HelpWindow userHelp;			//��������
	tableView  tableview;
};

#endif // MainWindow_H
