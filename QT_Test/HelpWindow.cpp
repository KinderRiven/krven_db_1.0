#include "HelpWindow.h"
#include "ui_helpwindow.h"

/*
	�������ڳ�ʼ��
*/
HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);

	setWindowOpacity(0.75);			//͸����

	ui->Exit->setFlat(true);		//��������ʾ�ײ�

	connect(ui->Exit, SIGNAL(clicked()), this, SLOT(Logout()));	//�˳�
}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::Logout()
{
	this->hide();	//�˳�
}
