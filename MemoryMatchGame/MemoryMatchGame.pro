#-------------------------------------------------
#
# Project created by QtCreator 2019-05-11T02:53:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MemoryMatchGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myitem.cpp \
    myscence.cpp

HEADERS  += mainwindow.h \
    myitem.h \
    myScence.h

FORMS    += mainwindow.ui

RESOURCES += \
    hi.qrc
