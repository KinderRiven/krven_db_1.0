/********************************************************************************
** Form generated from reading UI file 'qt_test.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_TEST_H
#define UI_QT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_TestClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *QT_TestClass)
    {
        if (QT_TestClass->objectName().isEmpty())
            QT_TestClass->setObjectName(QStringLiteral("QT_TestClass"));
        QT_TestClass->setEnabled(true);
        QT_TestClass->resize(930, 622);
        centralWidget = new QWidget(QT_TestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 290, 93, 28));
        QT_TestClass->setCentralWidget(centralWidget);

        retranslateUi(QT_TestClass);

        QMetaObject::connectSlotsByName(QT_TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_TestClass)
    {
        QT_TestClass->setWindowTitle(QApplication::translate("QT_TestClass", "QT_Test", 0));
        pushButton->setText(QApplication::translate("QT_TestClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class QT_TestClass: public Ui_QT_TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_TEST_H
