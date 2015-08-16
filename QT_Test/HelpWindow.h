#ifndef HelpWindow_H
#define HelpWindow_H

#include <QWidget>
/*
	帮助UI界面
*/
namespace Ui {
class HelpWindow;
}

class HelpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();

public slots:
	void Logout();		//退出信号槽

private:
    Ui::HelpWindow *ui;
};

#endif // HelpWindow_H
