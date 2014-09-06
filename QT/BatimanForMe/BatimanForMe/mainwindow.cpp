#include"mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Batiman For Me :: MENU");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Play PlayDialog;
    PlayDialog.setModal(true);
    PlayDialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    MySettingsDialog SettingsDialog;
    SettingsDialog.setModal(true);
    SettingsDialog.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    MyRankingDialog RankingDialog;
    RankingDialog.setModal(true);
    RankingDialog.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    MyCreditsDialog CreditsDialog;
    CreditsDialog.setModal(true);
    CreditsDialog.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}


