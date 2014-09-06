#include "nameinput.h"
#include "ui_nameinput.h"

NameInput::NameInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NameInput)
{
    ui->setupUi(this);
}

NameInput::~NameInput()
{
    delete ui;
}
