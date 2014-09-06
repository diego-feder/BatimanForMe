/********************************************************************************
** Form generated from reading UI file 'mysettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSETTINGSDIALOG_H
#define UI_MYSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySettingsDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *MySettingsDialog)
    {
        if (MySettingsDialog->objectName().isEmpty())
            MySettingsDialog->setObjectName(QStringLiteral("MySettingsDialog"));
        MySettingsDialog->resize(291, 192);
        layoutWidget = new QWidget(MySettingsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 254, 150));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalSlider_2 = new QSlider(layoutWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(88, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MySettingsDialog);

        QMetaObject::connectSlotsByName(MySettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *MySettingsDialog)
    {
        MySettingsDialog->setWindowTitle(QApplication::translate("MySettingsDialog", "Dialog", 0));
        label->setText(QApplication::translate("MySettingsDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">Sound FX</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MySettingsDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">Game Music</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MySettingsDialog", "Ok", 0));
        pushButton_2->setText(QApplication::translate("MySettingsDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class MySettingsDialog: public Ui_MySettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSETTINGSDIALOG_H
