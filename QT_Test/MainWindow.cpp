#include "MainWindow.h"
#include <QMouseEvent>
#include <QTime>
#include <Windows.h>
#include <time.h>

/*
	用户窗口初始化
*/
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//去除标题栏、窗口置顶
	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	//设置窗口大小
	
	//背景透明
	setAttribute(Qt::WA_TranslucentBackground, true);

	//播放音乐 加载音乐路径
	LoadMusic();

	//定时器设置
	TimeStart();

	//当前动作
	nowAction = 1;

	//加载图像
	image.load("image/database");
	//changeAction();

	//窗口开始位置
	resize(image.width(), image.height());
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()), 0);
}
/*
	析构函数
*/
MainWindow::~MainWindow()
{

}
/*
	绘画函数
	每次update都更新
*/
void MainWindow::paintEvent(QPaintEvent *){
	QPainter painter(this);
	resize(image.width(), image.height());
	painter.drawPixmap(0, 0, image.width(), image.height(), image);
}

/*
	鼠标单击事件
*/
void MainWindow::mousePressEvent(QMouseEvent* event)
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

/*
	鼠标拖动事件
*/
void MainWindow::mouseMoveEvent(QMouseEvent* event)
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

/*
	鼠标双击事件
*/
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{

}

/*
	鼠标右键菜单
*/
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
	QCursor cur = this->cursor();

	//创建一个属于该窗口的子菜单
	QMenu *menu = new QMenu(this);

	//字体设置
	QFont font;
	font.setFamily(QStringLiteral("SAO UI"));
	font.setPointSize(12);
	//用户信息
	menuAction[0] = new QAction(QIcon("image/user"), tr("User"), this);
	menuAction[0]->setFont(font);
	connect(menuAction[0], &QAction::triggered, this, &MainWindow::UserAction);
	menu->addAction(menuAction[0]);

	//数据库选择Database
	menuAction[1] = new QAction(QIcon("image/window"), tr("GUI"), this);
	menuAction[1]->setFont(font);
	connect(menuAction[1], &QAction::triggered, this, &MainWindow::DatabaseAction);
	menu->addAction(menuAction[1]);
	menuAction[1]->setDisabled(true);

	//命令行
	menuAction[2] = new QAction(QIcon("image/eye"), tr("Command"), this);
	menuAction[2]->setFont(font);
	connect(menuAction[2], &QAction::triggered, this, &MainWindow::CommandAction);
	menu->addAction(menuAction[2]);
	menuAction[2]->setDisabled(true);
	
	//Help
	menuAction[3] = new QAction(QIcon("image/help"), tr("Help"), this);
	menuAction[3]->setFont(font);
	connect(menuAction[3], &QAction::triggered, this, &MainWindow::HelpAction);
	menu->addAction(menuAction[3]);
	
	//退出选择键
	menuAction[4] = new QAction(QIcon("image/exit"), tr("Exit"), this);
	menuAction[4]->setFont(font);
	connect(menuAction[4], &QAction::triggered, this, &MainWindow::ExitAction);
	menu->addAction(menuAction[4]);

	//判断菜单的隐藏，在没登陆之前这些菜单需要隐藏
	if (userWindows.isLogin)
	{
		menuAction[1]->setDisabled(false);
		menuAction[2]->setDisabled(false);
	}
	//菜单弹出位置
	menu->exec(cur.pos());

}

/*
	右键用户菜单响应函数
*/
void MainWindow::UserAction()
{
	userWindows.Kshow();
}

/*
	右键命令行菜单响应函数
*/
void MainWindow::CommandAction()
{
	WinExec("Command/mydatabase.exe",5);
}

/*
	右键图形界面菜单响应函数
*/
void MainWindow::DatabaseAction()
{

	string username = userWindows.getUserName();
	if (userWindows.isLogin){
		userDatabase user(username);
		tableview.user = user;
		int Size = user.myTable.size();
		for (int i = 0; i < Size; i++){
			string tablename = user.myTable[i].name;
			tableview.addRow(tablename);
		}
	}
	tableview.show();
}

/*
	右键帮助菜单响应函数
*/
void MainWindow::HelpAction()
{
	userHelp.show();
}

/*
	右键退出菜单响应函数
*/
void MainWindow::ExitAction()
{
	exit(0);
}

/*
	背景音乐加载
*/
void MainWindow::LoadMusic(){

	systemMusic = "music/system.wav";
	exitMusic = "music/exit.wav";
}

/*
	定时器开始函数
*/
void MainWindow::TimeStart()
{
	//timeid[0] = startTimer(105);		//动作动画
	//timeid[1] = startTimer(1000 * 3);	//动作改变
}

/*
	定时器接收函数
*/
void MainWindow::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timeid[0])
	{
		if (nowAction == 1)
		{
			image_id++;
			if (image_id > 5)
			{
				image_id = 1;
			}
			image.load(getImage(imageFile, image_id));
			update();
		}
		if (nowAction == 2 || nowAction == 3)
		{
			image_id++;
			if (image_id > 12)
			{
				image_id = 1;
			}
			image.load(getImage(imageFile, image_id));
			int x = pos().x() - 4;
			int y = pos().y();
			if (x < -width())
				x = QApplication::desktop()->width();
			move(QPoint(x, y));
			update();
		}
	}
	if (event->timerId() == timeid[1])
	{
		srand(unsigned(time(NULL)));
		nowAction = rand() % 3 + 1;
		changeAction();
	}
}

/*
	获得制定路径图片的函数
*/
QString MainWindow::getImage(QString fileName,int id)
{
	QString qs = QString::number(id, 10);
	return fileName + qs;
}

/*
	动画函数
*/
void MainWindow::changeAction()
{
	if (nowAction == 1)
	{
		image_id = 1;
		imageFile = "image/miku/stand/";
	}
	if (nowAction == 2)
	{
		image_id = 1;
		imageFile = "image/miku/walk/";
	}
	if (nowAction == 3)
	{
		image_id = 1;
		imageFile = "image/miku/run/";
	}
	image.load(getImage(imageFile, image_id));
	update();
}
