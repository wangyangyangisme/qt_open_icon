#include "timetotal.h"

#define BACK_GROUND QString("background-image: url(:/images/resourse/images/animation/")

//总的界面
TimeTotal::TimeTotal(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(w, h);

    timeDisplay = new TimeDisplay;
    timeSet = new TimeSet;
    zoneSet = new ZoneSet;

    list.append(timeDisplay);
    list.append(timeSet);
    list.append(zoneSet);

    total = new AnimationWidget(list, "cover", 200, QEasingCurve::OutQuad);
    total->setParent(this);
    total->raise(0);

    connect(timeDisplay, SIGNAL(showZoneWig()), this, SLOT(showZoneWigSlot()));
    connect(timeDisplay, SIGNAL(showTimeSetWig()), this, SLOT(showTimeSetWigSlot()));
    connect(timeSet, SIGNAL(backDisp()), this, SLOT(backSlot()));
    connect(zoneSet, SIGNAL(backDisp()), this, SLOT(backSlot()));

    setStyleSheet("background-color:#FFFFFF;");
}

void TimeTotal::showZoneWigSlot()
{
    total->animationShow(1, AnimationWidget::ANIMATION_LEFT);
}

void TimeTotal::showTimeSetWigSlot()
{
    total->animationShow(2, AnimationWidget::ANIMATION_LEFT);
}

void TimeTotal::backSlot()
{
    total->animationShow(0, AnimationWidget::ANIMATION_RIGHT);
}
