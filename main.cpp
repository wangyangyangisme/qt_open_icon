#include "buttontest.h"
#include "animationtest.h"

#define ANIMATIONTEST

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef BUTTONTEST
    ButtonTest *w = new ButtonTest;
    w->show();
#elif defined ANIMATIONTEST
    AnimationTest *w = new AnimationTest;
    w->show();
#endif

    return a.exec();
}
