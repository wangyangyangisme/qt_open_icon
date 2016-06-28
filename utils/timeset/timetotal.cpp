#include "timetotal.h"

#define BACK_GROUND QString("background-image: url(:/images/resourse/images/animation/")

//总的界面
TimeTotal::TimeTotal(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(w, h);

    wig1 = new QWidget();
    wig1->setStyleSheet(BACK_GROUND + "1.PNG)");
    wig1->resize(w, h);
    wig2 = new QWidget();
    wig2->setStyleSheet(BACK_GROUND + "2.PNG)");
    wig2->resize(w, h);
    wig3 = new QWidget();
    wig3->setStyleSheet(BACK_GROUND + "3.PNG)");
    wig3->resize(w, h);

    list.append(wig1);
    list.append(wig2);
    list.append(wig3);

    total = new AnimationWidget(list, "cover");
    total->setParent(this);
    total->raise(0);

    QTimer::singleShot(400, this, SLOT(test()));

}

void TimeTotal::test()
{
    total->animationShow(2, AnimationWidget::ANIMATION_RIGHT);
}
