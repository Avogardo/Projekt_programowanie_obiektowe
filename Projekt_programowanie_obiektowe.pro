#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T20:01:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projekt_programowanie_obiektowe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character.cpp \
    hero.cpp \
    enemy.cpp \
    item.cpp \
    armoreitem.cpp \
    weaponitem.cpp

HEADERS  += mainwindow.h \
    character.h \
    hero.h \
    enemy.h \
    item.h \
    armoreitem.h \
    weaponitem.h \
    interfacewalka.h

FORMS    += mainwindow.ui
