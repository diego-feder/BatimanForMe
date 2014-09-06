#include<QtCore/QCoreApplication>
#include<QDebug>
#include<QIcon>

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

#include "mysettingsdialog.h"
#include "ui_mysettingsdialog.h"


MySettingsDialog::MySettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MySettingsDialog)
{
    ui->setupUi(this);
    setWindowTitle("Settings");
    //ui->horizontalSlider->setValue(100);
    //ui->horizontalSlider_2->setValue(100);
    getSettings();
}

MySettingsDialog::~MySettingsDialog()
{
    delete ui;
}


void MySettingsDialog::getSettings()
{
    int value = 0;
    std::string line;
    ifstream myfile("files/settings.txt");

    if(myfile.is_open())
    {
            getline (myfile, line);
            value = atoi(line.c_str());
            ui->horizontalSlider->setValue(value);
            getline (myfile, line);
            value = atoi(line.c_str());
            ui->horizontalSlider_2->setValue(value);
    }

    else qDebug() << "Unable to open file.";

}

void MySettingsDialog::saveSettings()
{

    ofstream myfile("files/settings.txt");

    if(myfile.is_open())
    {
        myfile << ui->horizontalSlider->value();
        myfile << endl;
        myfile << ui->horizontalSlider_2->value();
    }

    else qDebug() << "Unable to open file.";

}

void MySettingsDialog::on_pushButton_clicked()
{
   saveSettings();
   this->accept();
}

void MySettingsDialog::on_pushButton_2_clicked()
{
    this->close();
}

void MySettingsDialog::on_horizontalSlider_valueChanged(int value)
{
    ui->horizontalSlider->setValue(value);
    //qDebug() << "Slider_1 Value: " << ui->horizontalSlider->value();
}

void MySettingsDialog::on_horizontalSlider_2_valueChanged(int value)
{
    ui->horizontalSlider_2->setValue(value);
    //qDebug() << "Slider_2 Value : " << ui->horizontalSlider_2->value();
}
