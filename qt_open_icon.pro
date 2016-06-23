#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T09:56:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_open_icon
TEMPLATE = app

INCLUDEPATH += font core utils utils/button utils/animation utils/dialog
SOURCES += main.cpp\
    core/iconhelper.cpp \
    font/abstractfont.cpp \
    font/fontawesomewebfont.cpp \
    font/muifont.cpp \
    utils/button/basebutton.cpp \
    utils/button/buttontest.cpp \
    utils/button/switchbutton.cpp \
    utils/button/loopbutton.cpp \
    utils/button/batterybutton.cpp \
    utils/animation/abstractanimation.cpp \
    utils/animation/animationcenter.cpp \
    utils/animation/animationcover.cpp \
    utils/animation/animationfly.cpp \
    utils/animation/animationsharp.cpp \
    utils/animation/animationslide.cpp \
    utils/animation/animationtest.cpp \
    utils/animation/animationwidget.cpp \
    utils/dialog/toast.cpp \
    utils/dialog/dialogtest.cpp

HEADERS  += \
    core/iconhelper.h \
    font/abstractfont.h \
    font/fontawesomewebfont.h \
    font/muifont.h \
    font/fonts.h \
    utils/button/basebutton.h \
    utils/button/buttontest.h \
    utils/button/switchbutton.h \
    utils/button/loopbutton.h \
    utils/button/batterybutton.h \
    utils/animations/animation/abstractanimation.h \
    utils/animations/animation/animation.h \
    utils/animations/animation/animationcenter.h \
    utils/animations/animation/animationcover.h \
    utils/animations/animation/animationfly.h \
    utils/animations/animation/animationsharp.h \
    utils/animations/animation/animationslide.h \
    utils/animations/animation/animationwidget.h \
    utils/animations/mainwindow.h \
    utils/animation/abstractanimation.h \
    utils/animation/animation.h \
    utils/animation/animationcenter.h \
    utils/animation/animationcover.h \
    utils/animation/animationfly.h \
    utils/animation/animationsharp.h \
    utils/animation/animationslide.h \
    utils/animation/animationtest.h \
    utils/animation/animationwidget.h \
    utils/dialog/toast.h \
    utils/dialog/dialogtest.h

OTHER_FILES += \
    utils/abc.txt
