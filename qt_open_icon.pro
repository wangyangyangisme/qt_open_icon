#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T09:56:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_open_icon
TEMPLATE = app

INCLUDEPATH += font core utils utils/button
SOURCES += main.cpp\
    core/iconhelper.cpp \
    font/abstractfont.cpp \
    font/fontawesomewebfont.cpp \
    font/muifont.cpp \
    utils/button/basebutton.cpp \
    utils/button/buttontest.cpp \
    utils/button/switchbutton.cpp

HEADERS  += \
    core/iconhelper.h \
    font/abstractfont.h \
    font/fontawesomewebfont.h \
    font/muifont.h \
    font/fonts.h \
    utils/button/basebutton.h \
    utils/button/buttontest.h \
    utils/button/switchbutton.h

OTHER_FILES += \
    utils/abc.txt
