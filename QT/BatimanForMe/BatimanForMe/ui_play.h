/********************************************************************************
** Form generated from reading UI file 'play.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_H
#define UI_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Play
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Play)
    {
        if (Play->objectName().isEmpty())
            Play->setObjectName(QStringLiteral("Play"));
        Play->resize(400, 300);
        pushButton = new QPushButton(Play);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 240, 75, 23));
        pushButton_2 = new QPushButton(Play);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 50, 121, 31));
        pushButton_3 = new QPushButton(Play);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 130, 121, 31));

        retranslateUi(Play);
        QObject::connect(pushButton, SIGNAL(clicked()), Play, SLOT(close()));

        QMetaObject::connectSlotsByName(Play);
    } // setupUi

    void retranslateUi(QDialog *Play)
    {
        Play->setWindowTitle(QApplication::translate("Play", "Dialog", 0));
        pushButton->setText(QApplication::translate("Play", "Cancel", 0));
        pushButton_2->setText(QApplication::translate("Play", "New Game", 0));
        pushButton_3->setText(QApplication::translate("Play", "Load Last Game", 0));
    } // retranslateUi

};

namespace Ui {
    class Play: public Ui_Play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_H
