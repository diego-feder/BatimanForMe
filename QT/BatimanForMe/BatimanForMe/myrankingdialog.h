#ifndef MYRANKINGDIALOG_H
#define MYRANKINGDIALOG_H

#include <QDialog>
#include<QDebug>
#include<QDir>
#include<QFile>
#include<QString>
#include<QDebug>
#include<QTextStream>
#include<QFileInfo>

namespace Ui {
class MyRankingDialog;
}

class MyRankingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyRankingDialog(QWidget *parent = 0);
    ~MyRankingDialog();
    void Read();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyRankingDialog *ui;
};

#endif // MYRANKINGDIALOG_H
