#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
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
#include <string>
#include "onetableview.h"
#include "dataBase\userDatabase.h"
using namespace std;

namespace Ui {
class tableView;
}

class tableView : public QWidget
{
    Q_OBJECT

public:
    explicit tableView(QWidget *parent = 0);
	void addRow(string rowName = "NULL");
	void kShow();
	void kUpdate();
    ~tableView();
	userDatabase user;				//用户数据
public slots:
	void ExitButton();
	void GetTableView(QListWidgetItem *);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
    Ui::tableView *ui;
	QPoint  preMousePos;			//上次鼠标位置记录
	QListWidgetItem *item[1024];	//列数指针
	int rowNumber;

	oneTableView onetableview;
};

#endif // TABLEVIEW_H
