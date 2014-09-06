#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include<QMessageBox>

#include "myrankingdialog.h"
#include "ui_myrankingdialog.h"




MyRankingDialog::MyRankingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyRankingDialog)
{
    ui->setupUi(this);
    setWindowTitle("Ranking");

    Read();

}

MyRankingDialog::~MyRankingDialog()
{
    delete ui;
}


void MyRankingDialog::Read()
{
    int i = 0;
    std::string line;
    QString aline;
    QString bline;
    ifstream myfile("files/highscores.txt");

    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            //Name
            i++;
            getline (myfile, line);
            aline = line.c_str();

            //Score
            i++;
            getline (myfile, line);
            bline = line.c_str();

            ui->listWidget->addItem(aline + "  " + bline);

        }
    }

    else qDebug() << "Unable to open file.";

}

void MyRankingDialog::on_pushButton_clicked()
{
    this->close();
}
