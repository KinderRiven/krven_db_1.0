#include "MainWindow.h"
#include <QMouseEvent>
#include <QTime>
#include <Windows.h>
#include <time.h>

/*
	�û����ڳ�ʼ��
*/
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//ȥ���������������ö�
	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	//���ô��ڴ�С
	
	//����͸��
	setAttribute(Qt::WA_TranslucentBackground, true);

	//�������� ��������·��
	LoadMusic();

	//��ʱ������
	TimeStart();

	//��ǰ����
	nowAction = 1;

	//����ͼ��
	image.load("image/database");
	//changeAction();

	//���ڿ�ʼλ��
	resize(image.width(), image.height());
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()), 0);
}
/*
	��������
*/
MainWindow::~MainWindow()
{

}
/*
	�滭����
	ÿ��update������
*/
void MainWindow::paintEvent(QPaintEvent *){
	QPainter painter(this);
	resize(image.width(), image.height());
	painter.drawPixmap(0, 0, image.width(), image.height(), image);
}

/*
	��굥���¼�
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
	����϶��¼�
*/
void MainWindow::mouseMoveEvent(QMouseEvent* event)
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

/*
	���˫���¼�
*/
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{

}

/*
	����Ҽ��˵�
*/
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
	QCursor cur = this->cursor();

	//����һ�����ڸô��ڵ��Ӳ˵�
	QMenu *menu = new QMenu(this);

	//��������
	QFont font;
	font.setFamily(QStringLiteral("SAO UI"));
	font.setPointSize(12);
	//�û���Ϣ
	menuAction[0] = new QAction(QIcon("image/user"), tr("User"), this);
	menuAction[0]->setFont(font);
	connect(menuAction[0], &QAction::triggered, this, &MainWindow::UserAction);
	menu->addAction(menuAction[0]);

	//���ݿ�ѡ��Database
	menuAction[1] = new QAction(QIcon("image/window"), tr("GUI"), this);
	menuAction[1]->setFont(font);
	connect(menuAction[1], &QAction::triggered, this, &MainWindow::DatabaseAction);
	menu->addAction(menuAction[1]);
	menuAction[1]->setDisabled(true);

	//������
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
	
	//�˳�ѡ���
	menuAction[4] = new QAction(QIcon("image/exit"), tr("Exit"), this);
	menuAction[4]->setFont(font);
	connect(menuAction[4], &QAction::triggered, this, &MainWindow::ExitAction);
	menu->addAction(menuAction[4]);

	//�жϲ˵������أ���û��½֮ǰ��Щ�˵���Ҫ����
	if (userWindows.isLogin)
	{
		menuAction[1]->setDisabled(false);
		menuAction[2]->setDisabled(false);
	}
	//�˵�����λ��
	menu->exec(cur.pos());

}

/*
	�Ҽ��û��˵���Ӧ����
*/
void MainWindow::UserAction()
{
	userWindows.Kshow();
}

/*
	�Ҽ������в˵���Ӧ����
*/
void MainWindow::CommandAction()
{
	WinExec("Command/mydatabase.exe",5);
}

/*
	�Ҽ�ͼ�ν���˵���Ӧ����
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
	�Ҽ������˵���Ӧ����
*/
void MainWindow::HelpAction()
{
	userHelp.show();
}

/*
	�Ҽ��˳��˵���Ӧ����
*/
void MainWindow::ExitAction()
{
	exit(0);
}

/*
	�������ּ���
*/
void MainWindow::LoadMusic(){

	systemMusic = "music/system.wav";
	exitMusic = "music/exit.wav";
}

/*
	��ʱ����ʼ����
*/
void MainWindow::TimeStart()
{
	//timeid[0] = startTimer(105);		//��������
	//timeid[1] = startTimer(1000 * 3);	//�����ı�
}

/*
	��ʱ�����պ���
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
	����ƶ�·��ͼƬ�ĺ���
*/
QString MainWindow::getImage(QString fileName,int id)
{
	QString qs = QString::number(id, 10);
	return fileName + qs;
}

/*
	��������
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
