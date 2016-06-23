#include "buttontest.h"
#include "animationtest.h"
#include "dialogtest.h"


#define DIALOGTEST

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef BUTTONTEST
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
