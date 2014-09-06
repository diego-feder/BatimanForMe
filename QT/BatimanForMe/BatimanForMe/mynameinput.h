#ifndef MYNAMEINPUT_H
#define MYNAMEINPUT_H

#include <QDialog>
#include <QString>
#include <string>

#include <QMessageBox>
#include<QDebug>
#include<QDir>
#include<QFile>
#include<QString>
#include<QDebug>
#include<QTextStream>
#include<QFileInfo>

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

namespace Ui {
class MyNameInput;
}

class MyNameInput : public QDialog
{
    Q_OBJECT

public:
    explicit MyNameInput(QWidget *parent = 0);
    ~MyNameInput();
    void saveName();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyNameInput *ui;
};

#endif // MYNAMEINPUT_H
