#ifndef USERWINDOWS_H
#define USERWINDOWS_H

#include <QDialog>
#include <QMouseEvent>
#include <qobject.h>
#include <UserData.h>
#include <WarningWindows.h>
#include <QDesktopWidget>
#include <QTime>
#include <qwindowdefs.h>
#include <qsound.h>
#include <fstream>
using namespace std;

namespace Ui {
class UserWindow;
}
class UserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = 0);
    ~UserWindow();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void creatEvent();
	void timerEvent(QTimerEvent *event);
	void Kshow();
	string getUserName();
	bool isLogin;
public slots: 
	void userLogin();
	void userExit();

private:
    Ui::UserWindow *ui;
	
	int timeid;
	QPoint  preMousePos;
	QString sUsername;
	QString sPassword;
	UserData userDate;
	WarningWindows warningWindows;
	QString sMusic;
};

#endif // USERWINDOWS_H
