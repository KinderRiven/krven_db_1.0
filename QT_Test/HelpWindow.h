#ifndef HelpWindow_H
#define HelpWindow_H

#include <QWidget>
/*
	����UI����
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
	void Logout();		//�˳��źŲ�

private:
    Ui::HelpWindow *ui;
};

#endif // HelpWindow_H
