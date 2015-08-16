#include "UserWindow.h"
#include "ui_UserWindow.h"

UserWindow::UserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
	isLogin = false;
	//用户信息
	userDate.upDate();

	//设置窗口名称


	//去除标题栏
	Qt::WindowFlags flags = 0;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);


	//透明窗体
	setWindowOpacity(0.85);
	
	//密码条设置暗码格式
	ui->WordLine->setEchoMode(QLineEdit::Password);
	

	//去除pushbutton边框
	ui -> BExit  -> setFlat(true);
	ui -> BLogin -> setFlat(true);

	//位置
	QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();也可以
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);

	//Music
	sMusic = "music/system.wav";
}

UserWindow::~UserWindow()
{
    delete ui;
}

//鼠标单击事件
void UserWindow::mousePressEvent(QMouseEvent* event)
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
void UserWindow::mouseMoveEvent(QMouseEvent* event)
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


//用户的登陆函数
void UserWindow::userLogin()
{
	sUsername =  ui-> NameLine -> text();
	sPassword =  ui-> WordLine -> text();
	string sname = sUsername.toStdString();
	string spass = sPassword.toStdString();
	string tempname;
	string temppass;
	bool ok = false;
	for (int i = 0; i < userDate.userName.size(); i++)
	{
		tempname = userDate.userName[i];
		temppass = userDate.userPassword[i];
		if (sname == tempname && spass == temppass)
		{
			ok = true;
			break;
		}
	}
	if (ok){	//登陆成功
		isLogin = true;
		this->hide();
		warningWindows.newWindow("image/warning", "music/welcome.wav");
		warningWindows.Kshow();
		
		ofstream fr("nowuser.txt");
		fr << tempname;
		fr.close();
	}
	else{
		warningWindows.newWindow("image/warning2", "music/exit.wav");
		warningWindows.Kshow();
		ui->WordLine->clear();
	}
}

void UserWindow::userExit()
{
	this->hide();
}

void UserWindow::creatEvent()
{
	QObject::connect(ui->BLogin, SIGNAL(clicked()), this, SLOT(userLogin()));
	QObject::connect(ui->BExit, SIGNAL(clicked()),  this, SLOT(userExit()));
	timeid = startTimer(10);
}

void UserWindow::timerEvent(QTimerEvent *event)
{
	if (event -> timerId() == timeid)
	{
		int Kwidth = size().width();
		int Kheight = size().height();
		if (Kwidth <= 540 - 27){
			resize(QSize(Kwidth + 27, Kheight + 12));
		}
		if (Kwidth > 540 - 27)
		{
			killTimer(timeid);
		}
	}
}


//动画效果
void UserWindow::Kshow()
{
	resize(QSize(0, 0));
	QSound::play(sMusic);
	show();
	creatEvent();
}

string UserWindow::getUserName(){
	return sUsername.toStdString();
}