/*#include <iostream>
#include <fstream>
#include<string>
using namespace std;*/

#include "play.h"
#include "ui_play.h"

#include<QDir>
#include<QProcess>

Play::Play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
    setWindowTitle("Play");
    //QDir findDir("../../BatimanForMe/");
    //qDebug() << "Directory Status:" << findDir.exists() << endl
                //<< findDir.AllEntries;
}

Play::~Play()
{
    delete ui;
}

void Play::savePlayState(string str)
{

    //ofstream myfile("C:/Users/user/Dropbox/Batiman for me/theRealGame/QT/BatimanForMe/play.txt");



    ofstream myfile("files/play.txt");
    if(myfile.is_open())
    {
        myfile << str;
    }

    else qDebug() << "Unable to open file.";

}

void Play::on_pushButton_2_clicked() // Open New Game
{
    savePlayState("New");

    //Needs to fix it Path.
    //system("C:/Users/user/Dropbox/Batiman^ for^ me/theRealGame/BatimanForMe/bin/Debug/BatimanForMe.exe");

    MyNameInput NameInput;
    NameInput.setModal(true);
    NameInput.exec();


    /*QDir findDir("../../../BatimanForMe/bin/Release/Game.exe");
    qDebug() << "Directory State: " << findDir.exists() << endl
             << "Number of Entries: "   << findDir.AllEntries;*/


    QString program = "Game.exe";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, 0);
}

void Play::on_pushButton_3_clicked()  //Open Last Game
{
    savePlayState("Load");

    //Needs to fix it Path.
    //system("C:/Users/user/Dropbox/Batiman^ for^ me/theRealGame/BatimanForMe/bin/Debug/Game.exe");

    QString program = "Game.exe";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);

}

