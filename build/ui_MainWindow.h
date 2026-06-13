/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/RenderWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *m_central_widget;
    QHBoxLayout *horizontalLayout;
    QFrame *_frame;
    QVBoxLayout *verticalLayout_2;
    ui::RenderWidget *m_render_widget;
    QMenuBar *m_menu_bar;
    QStatusBar *m_status_bar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        m_central_widget = new QWidget(MainWindow);
        m_central_widget->setObjectName("m_central_widget");
        horizontalLayout = new QHBoxLayout(m_central_widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(9, 9, 9, 9);
        _frame = new QFrame(m_central_widget);
        _frame->setObjectName("_frame");
        _frame->setFrameShape(QFrame::Shape::StyledPanel);
        _frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(_frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_render_widget = new ui::RenderWidget(_frame);
        m_render_widget->setObjectName("m_render_widget");

        verticalLayout_2->addWidget(m_render_widget);


        horizontalLayout->addWidget(_frame);

        MainWindow->setCentralWidget(m_central_widget);
        m_menu_bar = new QMenuBar(MainWindow);
        m_menu_bar->setObjectName("m_menu_bar");
        m_menu_bar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(m_menu_bar);
        m_status_bar = new QStatusBar(MainWindow);
        m_status_bar->setObjectName("m_status_bar");
        MainWindow->setStatusBar(m_status_bar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
