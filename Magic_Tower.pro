#-------------------------------------------------
#
# Project created by QtCreator 2017-09-26T12:38:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Magic_Tower
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    background.cpp \
    unit.cpp \
    player.cpp \
    empty.cpp \
    slime_green.cpp \
    slime_blue.cpp \
    key_yellow.cpp \
    key_blue.cpp \
    key_red.cpp \
    door_yellow.cpp \
    door_blue.cpp \
    door_red.cpp \
    gem_blue.cpp \
    gem_red.cpp \
    potion_blue.cpp \
    potion_red.cpp \
    slime_red.cpp \
    key_godly.cpp \
    door_godly.cpp

HEADERS  += mainwindow.h \
    background.h \
    unit.h \
    player.h \
    empty.h \
    slime_green.h \
    slime_blue.h \
    key_yellow.h \
    key_blue.h \
    key_red.h \
    door_yellow.h \
    door_blue.h \
    door_red.h \
    gem_blue.h \
    gem_red.h \
    potion_blue.h \
    potion_red.h \
    slime_red.h \
    key_godly.h \
    door_godly.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES +=
