#include "buttontest.h"
#include "animationtest.h"
#include "dialogtest.h"
#include "baselabel.h"

#define LABELTEST


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef LABELTEST
    BaseLabel *w = new BaseLabel(MuiFont(), MuiFont::ICON_PENGYOUQUAN, 200, 100);
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
#endif

    return a.exec();
}
