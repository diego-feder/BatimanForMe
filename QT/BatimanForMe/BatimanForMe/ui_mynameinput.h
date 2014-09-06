/********************************************************************************
** Form generated from reading UI file 'mynameinput.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYNAMEINPUT_H
#define UI_MYNAMEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyNameInput
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *MyNameInput)
    {
        if (MyNameInput->objectName().isEmpty())
            MyNameInput->setObjectName(QStringLiteral("MyNameInput"));
        MyNameInput->resize(329, 164);
        lineEdit = new QLineEdit(MyNameInput);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 40, 231, 31));
        lineEdit->setMaxLength(20);
        label = new QLabel(MyNameInput);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 111, 21));
        pushButton = new QPushButton(MyNameInput);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 80, 75, 23));

        retranslateUi(MyNameInput);

        QMetaObject::connectSlotsByName(MyNameInput);
    } // setupUi

    void retranslateUi(QDialog *MyNameInput)
    {
        MyNameInput->setWindowTitle(QApplication::translate("MyNameInput", "Dialog", 0));
        label->setText(QApplication::translate("MyNameInput", "Enter Name:", 0));
        pushButton->setText(QApplication::translate("MyNameInput", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class MyNameInput: public Ui_MyNameInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYNAMEINPUT_H
