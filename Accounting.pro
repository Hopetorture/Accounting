#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T21:29:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Accounting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    numbers_to_words.cpp

HEADERS  += mainwindow.h \
    numbers_to_words.h

FORMS    += mainwindow.ui
