#include "buttontest.h"
#include "animationtest.h"
#include "dialogtest.h"
#include "baselabel.h"
#include "headutils.h"
#include "timetotal.h"
#include "switchwidget.h"

#define TIMESETTEST


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

#ifdef LABELTEST
    BaseLabel *w = new BaseLabel(TimeFont(), TimeFont::ICON_BACK, 200, 100);
    w->show();
#elif defined ANIMATIONTEST
    ButtonTest *w = new ButtonTest;
    w->show();
#elif defined ANIMATIONTEST
    AnimationTest *w = new AnimationTest;
    w->show();
#elif defined DIALOGTEST
    DialogTest *w = new DialogTest;
    w->show();
#elif defined TIMESETTEST
    CSwitchWidget *w = new CSwitchWidget;
    w->setFixedSize(100,50);
    w->show();
#endif

    return a.exec();
}
