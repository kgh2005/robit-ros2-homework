/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *up_button;
    QPushButton *down_button;
    QPushButton *left_button;
    QPushButton *right_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(72, 72, 72);\n"
"color: rgb(255, 255, 255)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        up_button = new QPushButton(centralwidget);
        up_button->setObjectName(QString::fromUtf8("up_button"));
        up_button->setGeometry(QRect(240, 120, 121, 111));
        up_button->setStyleSheet(QString::fromUtf8("font: 56pt \"Ubuntu\";"));
        down_button = new QPushButton(centralwidget);
        down_button->setObjectName(QString::fromUtf8("down_button"));
        down_button->setGeometry(QRect(240, 250, 121, 111));
        down_button->setStyleSheet(QString::fromUtf8("font: 56pt \"Ubuntu\";"));
        left_button = new QPushButton(centralwidget);
        left_button->setObjectName(QString::fromUtf8("left_button"));
        left_button->setGeometry(QRect(110, 250, 121, 111));
        left_button->setStyleSheet(QString::fromUtf8("font: 56pt \"Ubuntu\";"));
        right_button = new QPushButton(centralwidget);
        right_button->setObjectName(QString::fromUtf8("right_button"));
        right_button->setGeometry(QRect(370, 250, 121, 111));
        right_button->setStyleSheet(QString::fromUtf8("font: 56pt \"Ubuntu\";"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        up_button->setText(QCoreApplication::translate("MainWindow", "\342\254\206", nullptr));
        down_button->setText(QCoreApplication::translate("MainWindow", "\342\254\207", nullptr));
        left_button->setText(QCoreApplication::translate("MainWindow", "\342\254\205", nullptr));
        right_button->setText(QCoreApplication::translate("MainWindow", "\342\256\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
