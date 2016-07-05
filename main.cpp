#include "buttontest.h"
#include "animationtest.h"
#include "dialogtest.h"
#include "baselabel.h"
#include "headutils.h"
#include "timetotal.h"
#include "switchwidget.h"
#include "timedisplay.h"
#include "wheeltest.h"
#include "zonetable.h"
#include "navbar.h"

#define NAVBAR

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

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
#elif defined HEADUTILS
    HeadUtils *w = new HeadUtils("abc");
    w->show();
#elif defined NAVBAR
    BaseButton *btn = new BaseButton(TimeFont(), TimeFont::ICON_BACK, 200, 100);
    Navbar *w = new Navbar(btn);
    w->show();
#endif

    return a.exec();
}
