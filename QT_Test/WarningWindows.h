#ifndef WARNINGWINDOWS_H
#define WARNINGWINDOWS_H

#include "qmainwindow.h"
#include "qpainter.h"
#include <QTime>
#include <QTimerEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <qmainwindow.h>
#include <qaction.h>
#include <qwidget.h>


class WarningWindows :
	public QMainWindow
{
public:
	WarningWindows(QWidget *parent = 0);
	~WarningWindows();
	void paintEvent(QPaintEvent *);
	void timerEvent(QTimerEvent *event);
	void Kshow();
	void GetImage(QString imageName);
	void GetMusic(QString musicName);
	void newWindow(QString imageName, QString musicName);
private:
	QPixmap image;
	int timeid;
	double opac;
	QString sMusic;
	QString sImage;
};
#endif

