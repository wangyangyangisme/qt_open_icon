#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T09:56:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_open_icon
TEMPLATE = app

INCLUDEPATH += font
SOURCES += main.cpp\
    font/abstractfont.cpp \
    font/fontawesomewebfont.cpp \
    font/muifont.cpp \
    iconhelper.cpp \
    testwidget.cpp

HEADERS  += \
    iconhelper.h \
    font/abstractfont.h \
    font/fontawesomewebfont.h \
    font/muifont.h \
    font/fonts.h \
    testwidget.h
