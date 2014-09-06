#include "mynameinput.h"
#include "ui_mynameinput.h"

MyNameInput::MyNameInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyNameInput)
{
    ui->setupUi(this);
}

MyNameInput::~MyNameInput()
{
    delete ui;
}

void MyNameInput::on_pushButton_clicked()
{
    string str;
    QString qstr;
    qstr = ui->lineEdit->text();
    str = qstr.toStdString();

    ofstream myfile("files/player.txt");

    if(myfile.is_open())
    {
        myfile << str;
        myfile << endl;
    }

    else qDebug() << "Unable to open file.";

    this->close();
}
