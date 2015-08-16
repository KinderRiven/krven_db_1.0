#include "WarningWindows.h"
#include "qsound.h"
#include <QDesktopWidget>


WarningWindows::WarningWindows(QWidget *parent)
	: QMainWindow(parent)
{
	//去除标题栏
	//Qt::WindowFlags flags = 0;
	//flags |= Qt::FramelessWindowHint;
	//setWindowFlags(flags);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	//背景透明
	setAttribute(Qt::WA_TranslucentBackground, true);

	//

	//设置初始透明度
	setWindowOpacity(opac = 1.0);

	//
	timeid = startTimer(100);

	//music

	//位置
	QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();也可以
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}


WarningWindows::~WarningWindows()
{

}

void WarningWindows::paintEvent(QPaintEvent *){
	QPainter painter(this);
	resize(image.width(), image.height());
	painter.drawPixmap(0, 0, image.width(), image.height(), image);
}

void WarningWindows::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timeid)
	{
		if (opac > 0)
			opac -= 0.05;
		else
			this -> hide();
		setWindowOpacity(opac);
	}
}

void WarningWindows::Kshow()
{
	
	opac = 1.0;
	QSound::play(sMusic);
	show();
}
void WarningWindows::GetImage(QString imageName)
{
	sImage = imageName;
	image.load(imageName);
}
void WarningWindows::GetMusic(QString musicName)
{
	sMusic = musicName;
}

void WarningWindows::newWindow(QString imageName, QString musicName)
{
	GetImage(imageName);
	GetMusic(musicName);
}