#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T09:56:02
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = qt_open_icon
TEMPLATE = app

INCLUDEPATH += font core utils common \
utils/label utils/button utils/animation utils/dialog utils/timeset \
utils/wheel utils/navbar utils/list \
utils/desktop utils/desktop/procedure \
service service/database service/database\connectionpool service/database\dao service/database\entity

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
    utils/dialog/dialogtest.cpp \
    utils/label/baselabel.cpp \
    utils/timeset/headutils.cpp \
    font/timefont.cpp \
    utils/timeset/timetotal.cpp \
    utils/timeset/timedisplay.cpp \
    utils/timeset/switchwidget.cpp \
    utils/timeset/timeset.cpp \
    utils/timeset/zoneset.cpp \
    utils/wheel/wheelwidget.cpp \
    utils/wheel/stringwheelwidget.cpp \
    utils/wheel/wheeltest.cpp \
    utils/timeset/zonetable.cpp \
    utils/qcustomplot/qcustomplot.cpp \
    utils/navbar/navbar.cpp \
    utils/navbar/test.cpp \
    utils/dialog/basemessagebox.cpp \
    common/utilscommon.cpp \
    utils/desktop/desktop.cpp \
    utils/desktop/procedure/qqprocedure.cpp \
    utils/desktop/procedure/procedure.cpp \
    utils/list/baselist.cpp \
    utils/list/listtest.cpp \
    utils/list/normallist.cpp \
    service/database/connectionpool/connectionpool.cpp \
    service/database/dao/abstractdao.cpp \
    service/database/dao/studentdaoimpl.cpp \
    service/database/entity/studentdata.cpp \
    service/database/databasetest.cpp


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
    utils/dialog/dialogtest.h \
    utils/label/baselabel.h \
    utils/timeset/headutils.h \
    font/timefont.h \
    utils/timeset/timetotal.h \
    utils/timeset/timedisplay.h \
    utils/timeset/switchwidget.h \
    utils/timeset/timeset.h \
    utils/timeset/zoneset.h \
    utils/wheel/wheelwidget.h \
    utils/wheel/stringwheelwidget.h \
    utils/wheel/wheeltest.h \
    utils/timeset/zonetable.h \
    utils/qcustomplot/qcustomplot.h \
    utils/navbar/navbar.h \
    utils/navbar/test.h \
    utils/dialog/basemessagebox.h \
    common/utilscommon.h \
    utils/desktop/desktop.h \
    utils/desktop/procedure/qqprocedure.h \
    utils/desktop/procedure/procedure.h \
    utils/list/baselist.h \
    utils/list/listtest.h \
    utils/list/normallist.h \
    utils/desktop/desktopcmd.h \
    utils/desktop/procedure/procedurehead.h \
    service/database/connectionpool/connectionpool.h \
    service/database/dao/abstractdao.h \
    service/database/dao/studentdaoimpl.h \
    service/database/entity/studentdata.h \
    service/database/databasetest.h



RESOURCES += \
    resource.qrc

#message(parse over)
