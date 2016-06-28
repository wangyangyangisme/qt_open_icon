#include "timedisplay.h"

//显示界面
TimeDisplay::TimeDisplay(QWidget *parent) :
    QWidget(parent)
{
    head = new HeadUtils("显示", this);
    setFixedSize(355, 200);
}
