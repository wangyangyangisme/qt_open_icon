#include "buttontest.h"
#include "animationtest.h"
#include "dialogtest.h"
#include "baselabel.h"
#include "timetotal.h"
#include "wheeltest.h"
#include "navbar.h"
#include "dialogtest.h"
#include "desktop.h"
#include "listtest.h"

#define LIST

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif

#ifdef LABELTEST
    BaseLabel *w = new BaseLabel(TimeFont(), TimeFont::ICON_BACK, 200, 100);
    w->show();
#elif defined BUTTONTEST
    ButtonTest *w = new ButtonTest;
    w->show();
#elif defined ANIMATIONTEST
    AnimationTest *w = new AnimationTest;
    w->show();
#elif defined DIALOGTEST
    DialogTest *w = new DialogTest;
    w->show();
#elif defined WHEELWIDGET
    bool touch = a.arguments().contains(QLatin1String("--touch"));
    WheelTest *w = new WheelTest(touch);
    w->show();
#elif defined TIMESET
    TimeTotal *w = new TimeTotal;
    w->show();
#elif defined NAVBAR
    BaseButton *btn = new BaseButton(TimeFont(), TimeFont::ICON_BACK, 200, 100);
    Navbar *w = new Navbar(btn);
    w->show();
#elif defined DESKTOP
    Desktop *desk = new Desktop;
    desk->show();
#elif defined LIST
    ListTest *w = new ListTest;
    w->show();
#endif

    return a.exec();
}
