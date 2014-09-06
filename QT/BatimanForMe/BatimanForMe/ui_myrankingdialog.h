/********************************************************************************
** Form generated from reading UI file 'myrankingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYRANKINGDIALOG_H
#define UI_MYRANKINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MyRankingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *MyRankingDialog)
    {
        if (MyRankingDialog->objectName().isEmpty())
            MyRankingDialog->setObjectName(QStringLiteral("MyRankingDialog"));
        MyRankingDialog->resize(400, 300);
        MyRankingDialog->setModal(true);
        verticalLayout = new QVBoxLayout(MyRankingDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(MyRankingDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(MyRankingDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MyRankingDialog);

        QMetaObject::connectSlotsByName(MyRankingDialog);
    } // setupUi

    void retranslateUi(QDialog *MyRankingDialog)
    {
        MyRankingDialog->setWindowTitle(QApplication::translate("MyRankingDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("MyRankingDialog", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class MyRankingDialog: public Ui_MyRankingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYRANKINGDIALOG_H
