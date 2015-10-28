#-------------------------------------------------
#
# Project created by QtCreator 2015-09-28T14:18:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kolkata
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Player.cpp \
    Board.cpp \
    Game.cpp \
    clickablelabel.cpp \
    Card.cpp

HEADERS  += mainwindow.h \
    Player.h \
    Board.h \
    Card.h \
    Game.h \
    goods_t.h \
    clickablelabel.h \
    debug.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
