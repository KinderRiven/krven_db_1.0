#include "MainWindow.h"
#include "UserWindow.h"
#include "MainDataBase.h"
#include "WarningWindows.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainDataBase mainBase;
	mainBase.Kshow();
	return a.exec();
}
