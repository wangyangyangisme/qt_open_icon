#include "widgetanimation.h"

namespace desktopAnimation {

void animationShow(QWidget *wig, int x, int y)
{
    int w = wig->width();
    int h = wig->height();
    QPropertyAnimation *animal= new QPropertyAnimation(wig,"geometry");
    animal->setDuration(1000);
    animal->setStartValue(QRect(0, 0, w, h));
    animal->setEndValue(QRect(x,y, 0, 0));
//    animal->setEasingCurve(easing);
//    connect(animal, SIGNAL(finished()), this, SIGNAL(animationFinished()));
//    wig->raise();
    animal->start();
}

}
