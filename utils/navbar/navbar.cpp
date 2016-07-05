#include "navbar.h"

Navbar::Navbar(QPushButton *bnt)
{
    bnt->setParent(this);
    BaseButton *btn1 = qobject_cast<BaseButton*>(bnt);
    connect(btn1, SIGNAL(btnReleased()), this, SLOT(test()));
}

void Navbar::test()
{
    qDebug()<<"test";
}
