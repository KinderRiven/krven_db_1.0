#include "onetableview.h"
#include "ui_onetableview.h"

oneTableView::oneTableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::oneTableView)
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	ui->ExitButton->setFlat(true);

	QObject::connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(kExit()));
	
}
/*
	 setText(QApplication::translate("oneTableView", "Name", 0));
	 tableWidget->setVerticalHeaderItem(0, item);
	 tableWidget->setHorizontalHeaderItem(0,item);
*/
oneTableView::~oneTableView()
{
    delete ui;
}

void oneTableView::addRow(int pos,QString &qstr)
{
	QTableWidgetItem* newRow = new QTableWidgetItem();
	newRow->setText(qstr);
	ui->tableWidget->setVerticalHeaderItem(pos, newRow);
}

void oneTableView::addColumn(int pos,QString &qstr)
{
	QTableWidgetItem* newColumn = new QTableWidgetItem();
	newColumn->setText(qstr);
	ui->tableWidget->setHorizontalHeaderItem(pos, newColumn);
}

void oneTableView::kUpdate(QString& qstr)
{
	kTable table;
	table.name = qstr.toStdString();
	save.getTable(table);
	ui->tableWidget->setColumnCount(table.columnName.size());
	ui->tableWidget->setRowCount(table.dataNumber);
	
	//setHorizontalHeaderItem(int column, QTableWidgetItem * item)
	char s[256];
	int  j;
	//�����е�����
	for (int i = 0; i < (int)table.columnName.size(); i++){
		QTableWidgetItem *item = new QTableWidgetItem();
		for (j = 0; j < (int)table.columnName[i].size(); j++)
			s[j] = table.columnName[i][j];
		s[j] = '\0';
		item->setText(s);
		ui-> tableWidget->setHorizontalHeaderItem(i, item);
	}
	//�������� setCellWidget(int row, int column, QWidget * widget)
	int Size = table.columnName.size();
	int k;
	for (int i = 0; i < table.dataNumber; i++){
		for (int j = 0; j < Size; j++){
			string sstr = table.tableData[i][j];
			for (k = 0; k < (int)sstr.size(); k++)
				s[k] = sstr[k];
			s[k] = '\0';
			ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString(s)));
		}
	}
	update();
}

void oneTableView::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		preMousePos = cursor().pos();
		update();
	}
	if (event->button() == Qt::RightButton)
	{

	}
}

//����϶��¼�
void oneTableView::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		QPoint mpos = cursor().pos();	//�������

		/*�ƶ��Ĺ�ʽ��
		���õ�λ�� = ֮ǰ����λ�� + ����ǰ���λ�� - ֮ǰ���λ�ã�
		*/
		int posX = pos().x() + mpos.x() - preMousePos.x();
		int posY = pos().y() + mpos.y() - preMousePos.y();
		move(QPoint(posX, posY));

		//�����������ֵ
		preMousePos = mpos;
	}
}

void oneTableView::kExit()
{
	this->hide();
}

void oneTableView::BigOpen()
{
	QDesktopWidget* desktop = QApplication::desktop();
	move(0, 0);
	resize(desktop->width(), desktop->height());
}