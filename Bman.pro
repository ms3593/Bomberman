#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T11:31:23
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bman
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    bomb.cpp \
    fixedwall.cpp \
    fire.cpp \
    normalwall.cpp \
    powerups.cpp

HEADERS  += \
    game.h \
    player.h \
    bomb.h \
    fixedwall.h \
    fire.h \
    normalwall.h \
    powerups.h

RESOURCES += \
    res.qrc

DISTFILES +=
