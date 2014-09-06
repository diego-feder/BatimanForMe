#ifndef PLAY_H
#define PLAY_H

#include <QDialog>
#include<QDebug>
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

#include "mynameinput.h"

namespace Ui {
class Play;
}

class Play : public QDialog
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = 0);
    ~Play();
    void savePlayState(string str);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Play *ui;
};

#endif // PLAY_H
