#include "timeset.h"

TimeSet::TimeSet(QWidget *parent) :
    QWidget(parent)
{
    head = new HeadUtils("设置时间", this);
    setFixedSize(355, 200);
    setStyleSheet("background-color:#FF1493;");

    connect(head, SIGNAL(backSignal()), this, SIGNAL(backDisp()));
}
