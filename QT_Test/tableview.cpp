#include "tableview.h"
#include "ui_tableview.h"


tableView::tableView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableView)
{
    ui->setupUi(this);

	//隐藏
	setWindowFlags(Qt::FramelessWindowHint);
	
	//
	rowNumber = 1;

	//
	QObject::connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(ExitButton()));
	QObject::connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)),
		this, SLOT(GetTableView(QListWidgetItem *)));
	//
}

tableView::~tableView()
{
    delete ui;
}

void tableView::mousePressEvent(QMouseEvent* event)
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

//鼠标拖动事件
void tableView::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		QPoint mpos = cursor().pos();	//鼠标坐标

		/*移动的公式：
		设置的位置 = 之前窗口位置 + （当前鼠标位置 - 之前鼠标位置）
		*/
		int posX = pos().x() + mpos.x() - preMousePos.x();
		int posY = pos().y() + mpos.y() - preMousePos.y();
		move(QPoint(posX, posY));

		//更新鼠标坐标值
		preMousePos = mpos;
	}
}

void tableView::addRow(string name)
{
	int L = name.size();
	char cname[256];
	for (int i = 0; i < L; i++)
		cname[i] = name[i];
	cname[L] = '\0';
	
	//
	item[rowNumber] = new QListWidgetItem(ui->listWidget);
	item[rowNumber]->setText(QApplication::translate("tableView",cname, 0));
	
	//设置字体类型
	QFont font;
	font.setFamily(QStringLiteral("SAO UI"));
	font.setPointSize(16);
	item[rowNumber]->setFont(font);

	//设置内容居中
	item[rowNumber]->setTextAlignment(Qt::AlignHCenter);
	//
	rowNumber++;
}

void tableView::ExitButton()
{
	this->hide();
	ui->listWidget->clear();
}

void tableView::kShow()
{

}

void tableView::GetTableView(QListWidgetItem *item)
{
	QString qstr = item->text();
	onetableview.kUpdate(qstr);
	onetableview.show();
}

void tableView::kUpdate()
{

}