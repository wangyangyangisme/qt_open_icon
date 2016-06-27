#include "buttontest.h"
#include "animationtest.h"
#include "dialogtest.h"
#include "baselabel.h"
#include "headutils.h"

#define TIMESETTEST


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
    HeadUtils *w = new HeadUtils;
    w->show();
#endif

    return a.exec();
}
