#include "mycreditsdialog.h"
#include "ui_mycreditsdialog.h"

MyCreditsDialog::MyCreditsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCreditsDialog)
{
    ui->setupUi(this);
    setWindowTitle("Credits");

}

MyCreditsDialog::~MyCreditsDialog()
{
    delete ui;
}

void MyCreditsDialog::on_pushButton_clicked()
{
    this->close();
}
