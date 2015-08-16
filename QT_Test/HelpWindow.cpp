#include "HelpWindow.h"
#include "ui_helpwindow.h"

/*
	帮助窗口初始化
*/
HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);

	setWindowOpacity(0.75);			//透明度

	ui->Exit->setFlat(true);		//按键不显示底部

	connect(ui->Exit, SIGNAL(clicked()), this, SLOT(Logout()));	//退出
}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::Logout()
{
	this->hide();	//退出
}
