/********************************************************************************
** Form generated from reading UI file 'mycreditsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCREDITSDIALOG_H
#define UI_MYCREDITSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCreditsDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *MyCreditsDialog)
    {
        if (MyCreditsDialog->objectName().isEmpty())
            MyCreditsDialog->setObjectName(QStringLiteral("MyCreditsDialog"));
        MyCreditsDialog->resize(400, 300);
        widget = new QWidget(MyCreditsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 389, 249));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 31, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        pushButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label->raise();

        retranslateUi(MyCreditsDialog);

        QMetaObject::connectSlotsByName(MyCreditsDialog);
    } // setupUi

    void retranslateUi(QDialog *MyCreditsDialog)
    {
        MyCreditsDialog->setWindowTitle(QApplication::translate("MyCreditsDialog", "Dialog", 0));
        label->setText(QApplication::translate("MyCreditsDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">This game was performed in the context of the class Fundamentals</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MyCreditsDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">of Programming 2, and aims to bring the knowledge of software</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MyCreditsDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">engineering to the practice.</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("MyCreditsDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Professor: Dr. Jean Simao</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("MyCreditsDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Developers: Diego Feder and Murilo Gabardo</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MyCreditsDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-style:italic; text-decoration: underline;\">We Hope you Enjoy! :)</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MyCreditsDialog", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class MyCreditsDialog: public Ui_MyCreditsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCREDITSDIALOG_H
