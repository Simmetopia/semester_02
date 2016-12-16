#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T19:53:23
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    opretscenarie.cpp \
    additem.cpp \
    scenarielist.cpp \
    aktion.cpp \
    protocol.cpp \
    scenarier.cpp \
    enheder.cpp \
    tilfoejenhed.cpp

HEADERS  += mainwindow.h \
    opretscenarie.h \
    additem.h \
    scenarielist.h \
    aktion.h \
    protocol.h \
    scenarier.h \
    enheder.h \
    tilfoejenhed.h

FORMS    += mainwindow.ui \
    opretscenarie.ui \
    additem.ui \
    enheder.ui \
    tilfoejenhed.ui
