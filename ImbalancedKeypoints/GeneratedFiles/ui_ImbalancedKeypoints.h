/********************************************************************************
** Form generated from reading UI file 'ImbalancedKeypoints.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMBALANCEDKEYPOINTS_H
#define UI_IMBALANCEDKEYPOINTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ImbalancedKeypointsClass
{
public:
    QAction *actionTest;
    QWidget *centralWidget;
    QGridLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVTKWidget *qvtkWidget_2;
    QVBoxLayout *verticalLayout_1;
    QVTKWidget *qvtkWidget_1;
    QVBoxLayout *verticalLayout_3;
    QVTKWidget *qvtkWidget_3;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImbalancedKeypointsClass)
    {
        if (ImbalancedKeypointsClass->objectName().isEmpty())
            ImbalancedKeypointsClass->setObjectName(QStringLiteral("ImbalancedKeypointsClass"));
        ImbalancedKeypointsClass->resize(1126, 746);
        QFont font;
        font.setPointSize(5);
        ImbalancedKeypointsClass->setFont(font);
        actionTest = new QAction(ImbalancedKeypointsClass);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        centralWidget = new QWidget(ImbalancedKeypointsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QGridLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        qvtkWidget_2 = new QVTKWidget(centralWidget);
        qvtkWidget_2->setObjectName(QStringLiteral("qvtkWidget_2"));

        verticalLayout_2->addWidget(qvtkWidget_2);


        horizontalLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        qvtkWidget_1 = new QVTKWidget(centralWidget);
        qvtkWidget_1->setObjectName(QStringLiteral("qvtkWidget_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkWidget_1->sizePolicy().hasHeightForWidth());
        qvtkWidget_1->setSizePolicy(sizePolicy);

        verticalLayout_1->addWidget(qvtkWidget_1);


        horizontalLayout->addLayout(verticalLayout_1, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        qvtkWidget_3 = new QVTKWidget(centralWidget);
        qvtkWidget_3->setObjectName(QStringLiteral("qvtkWidget_3"));

        verticalLayout_3->addWidget(qvtkWidget_3);


        horizontalLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(9);
        textEdit->setFont(font1);
        textEdit->setReadOnly(false);

        verticalLayout_4->addWidget(textEdit);


        horizontalLayout->addLayout(verticalLayout_4, 1, 2, 1, 1);

        ImbalancedKeypointsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImbalancedKeypointsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1126, 23));
        ImbalancedKeypointsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImbalancedKeypointsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImbalancedKeypointsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImbalancedKeypointsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImbalancedKeypointsClass->setStatusBar(statusBar);

        retranslateUi(ImbalancedKeypointsClass);

        QMetaObject::connectSlotsByName(ImbalancedKeypointsClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImbalancedKeypointsClass)
    {
        ImbalancedKeypointsClass->setWindowTitle(QApplication::translate("ImbalancedKeypointsClass", "ImbalancedKeypoints", 0));
        actionTest->setText(QApplication::translate("ImbalancedKeypointsClass", "test", 0));
    } // retranslateUi

};

namespace Ui {
    class ImbalancedKeypointsClass: public Ui_ImbalancedKeypointsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMBALANCEDKEYPOINTS_H
