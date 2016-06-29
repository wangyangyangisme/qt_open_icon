#include "zoneset.h"

ZoneSet::ZoneSet(QWidget *parent) :
    QWidget(parent)
{
    head = new HeadUtils("设置时区", this);
    setFixedSize(355, 200);
    setStyleSheet("background-color:#EEB422;");
    connect(head, SIGNAL(backSignal()), this, SIGNAL(backDisp()));
}
