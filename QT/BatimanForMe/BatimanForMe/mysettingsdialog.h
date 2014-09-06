#ifndef MYSETTINGSDIALOG_H
#define MYSETTINGSDIALOG_H

#include <QDialog>
#include<QtCore/QCoreApplication>
#include<QDebug>
#include<QIcon>

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

namespace Ui {
class MySettingsDialog;
}

class MySettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MySettingsDialog(QWidget *parent = 0);
    ~MySettingsDialog();
    void getSettings();
    void saveSettings();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::MySettingsDialog *ui;
};

#endif // MYSETTINGSDIALOG_H
