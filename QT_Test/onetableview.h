#ifndef ONETABLEVIEW_H
#define ONETABLEVIEW_H

#include <string>
//----------------------------------------
#include <QWidget>
#include <qstring.h>
#include <QtCore>
#include <qaction.h>
#include <qmenu.h>
#include <qaction.h>
#include <qsound.h>
#include <algorithm>
#include <qpixmap.h>
#include <qwidget.h>
#include <QtWidgets>
#include <qpainter.h>
#include <QDesktopWidget>
//--------------------------------------------
#include <dataBase\Save.h>
#include <dataBase\kTable.h>
//--------------------------------------------
using namespace std;

namespace Ui {
class oneTableView;
}

class oneTableView : public QWidget
{
    Q_OBJECT

public:
    explicit oneTableView(QWidget *parent = 0);
    ~oneTableView();
	void addRow(int pos,QString &);
	void addColumn(int pos,QString &);
	void kUpdate(QString& qstr);
	int rowNumber;
	int colNumber;
	void BigOpen();
public slots:
	void kExit();
protected:
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
private:
    Ui::oneTableView *ui;
	QPoint preMousePos;
	Save save;
};

#endif // ONETABLEVIEW_H
