/********************************************************************************
** Form generated from reading UI file 'HelpWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QLabel *Author;
    QLabel *K;
    QPushButton *Exit;
    QLabel *K_2;
    QLabel *K_3;
    QLabel *K_4;
    QLabel *K_5;
    QLabel *K_6;
    QLabel *K_7;
    QLabel *K_8;
    QLabel *K_9;
    QLabel *K_10;
    QLabel *K_11;

    void setupUi(QWidget *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QStringLiteral("HelpWindow"));
        HelpWindow->resize(724, 458);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 252, 252, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 253, 253, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 126, 126, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 168, 168, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        HelpWindow->setPalette(palette);
        Author = new QLabel(HelpWindow);
        Author->setObjectName(QStringLiteral("Author"));
        Author->setGeometry(QRect(490, 370, 201, 51));
        QFont font;
        font.setFamily(QStringLiteral("SAO UI"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        Author->setFont(font);
        K = new QLabel(HelpWindow);
        K->setObjectName(QStringLiteral("K"));
        K->setGeometry(QRect(550, 330, 141, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("SAO UI"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        K->setFont(font1);
        Exit = new QPushButton(HelpWindow);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setGeometry(QRect(670, 10, 41, 41));
        QIcon icon;
        icon.addFile(QStringLiteral("image/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        Exit->setIcon(icon);
        K_2 = new QLabel(HelpWindow);
        K_2->setObjectName(QStringLiteral("K_2"));
        K_2->setGeometry(QRect(20, 20, 311, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        K_2->setFont(font2);
        K_3 = new QLabel(HelpWindow);
        K_3->setObjectName(QStringLiteral("K_3"));
        K_3->setGeometry(QRect(20, 70, 251, 31));
        K_3->setFont(font2);
        K_4 = new QLabel(HelpWindow);
        K_4->setObjectName(QStringLiteral("K_4"));
        K_4->setGeometry(QRect(20, 130, 181, 31));
        K_4->setFont(font2);
        K_5 = new QLabel(HelpWindow);
        K_5->setObjectName(QStringLiteral("K_5"));
        K_5->setGeometry(QRect(20, 190, 171, 31));
        K_5->setFont(font2);
        K_6 = new QLabel(HelpWindow);
        K_6->setObjectName(QStringLiteral("K_6"));
        K_6->setGeometry(QRect(20, 250, 181, 31));
        K_6->setFont(font2);
        K_7 = new QLabel(HelpWindow);
        K_7->setObjectName(QStringLiteral("K_7"));
        K_7->setGeometry(QRect(20, 310, 201, 31));
        K_7->setFont(font2);
        K_8 = new QLabel(HelpWindow);
        K_8->setObjectName(QStringLiteral("K_8"));
        K_8->setGeometry(QRect(20, 370, 201, 31));
        K_8->setFont(font2);
        K_9 = new QLabel(HelpWindow);
        K_9->setObjectName(QStringLiteral("K_9"));
        K_9->setGeometry(QRect(290, 70, 201, 31));
        K_9->setFont(font2);
        K_10 = new QLabel(HelpWindow);
        K_10->setObjectName(QStringLiteral("K_10"));
        K_10->setGeometry(QRect(290, 130, 321, 31));
        K_10->setFont(font2);
        K_11 = new QLabel(HelpWindow);
        K_11->setObjectName(QStringLiteral("K_11"));
        K_11->setGeometry(QRect(290, 190, 321, 31));
        K_11->setFont(font2);

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QWidget *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "Form", 0));
        Author->setText(QApplication::translate("HelpWindow", "Sun Chuanbo", 0));
        K->setText(QApplication::translate("HelpWindow", "KDataBase1.0.1", 0));
        Exit->setText(QString());
        K_2->setText(QApplication::translate("HelpWindow", "1.help data/table/view/[order] ", 0));
        K_3->setText(QApplication::translate("HelpWindow", "2.SELECT \343\200\220\346\237\245\350\257\242\343\200\221", 0));
        K_4->setText(QApplication::translate("HelpWindow", "3.UPDATE \343\200\220\346\233\264\346\226\260\343\200\221", 0));
        K_5->setText(QApplication::translate("HelpWindow", "4.INSERT \343\200\220\346\217\222\345\205\245\343\200\221", 0));
        K_6->setText(QApplication::translate("HelpWindow", "5.DELETE \343\200\220\345\210\240\351\231\244\343\200\221", 0));
        K_7->setText(QApplication::translate("HelpWindow", "6.CREATE \343\200\220\345\210\233\345\273\272\343\200\221", 0));
        K_8->setText(QApplication::translate("HelpWindow", "7.GRANT  \343\200\220\346\217\220\346\235\203\343\200\221", 0));
        K_9->setText(QApplication::translate("HelpWindow", "8. DROP  \343\200\220\345\210\240\351\231\244\350\241\250\343\200\221", 0));
        K_10->setText(QApplication::translate("HelpWindow", "9.\347\224\250\346\210\267\347\231\273\345\275\225\344\273\245\345\217\212\346\226\207\344\273\266\345\255\230\345\202\250", 0));
        K_11->setText(QApplication::translate("HelpWindow", "10.TABLE\343\200\201VIEW\343\200\201INDEX", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
