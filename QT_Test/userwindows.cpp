#include "UserWindow.h"
#include "ui_UserWindow.h"

UserWindow::UserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
	isLogin = false;
	//�û���Ϣ
	userDate.upDate();

	//���ô�������


	//ȥ��������
	Qt::WindowFlags flags = 0;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);


	//͸������
	setWindowOpacity(0.85);
	
	//���������ð����ʽ
	ui->WordLine->setEchoMode(QLineEdit::Password);
	

	//ȥ��pushbutton�߿�
	ui -> BExit  -> setFlat(true);
	ui -> BLogin -> setFlat(true);

	//λ��
	QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();Ҳ����
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);

	//Music
	sMusic = "music/system.wav";
}

UserWindow::~UserWindow()
{
    delete ui;
}

//��굥���¼�
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

//����϶��¼�
void UserWindow::mouseMoveEvent(QMouseEvent* event)
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


//�û��ĵ�½����
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
	if (ok){	//��½�ɹ�
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


//����Ч��
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