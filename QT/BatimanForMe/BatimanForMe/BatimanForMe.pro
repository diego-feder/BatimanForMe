#-------------------------------------------------
#
# Project created by QtCreator 2014-02-12T17:10:07
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BatimanForMe
TEMPLATE = app
CONFIG += static


SOURCES += main.cpp\
        mainwindow.cpp \
    mycreditsdialog.cpp \
    mysettingsdialog.cpp \
    myrankingdialog.cpp \
    play.cpp \
    mynameinput.cpp

HEADERS  += mainwindow.h \
    mycreditsdialog.h \
    mysettingsdialog.h \
    myrankingdialog.h \
    play.h \
    mynameinput.h

FORMS    += mainwindow.ui \
    mycreditsdialog.ui \
    mysettingsdialog.ui \
    myrankingdialog.ui \
    play.ui \
    mynameinput.ui
