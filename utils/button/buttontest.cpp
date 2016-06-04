#include "buttontest.h"

ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent)
{
    btn = new BaseButton(MuiFont(), MuiFont::ICON_WEINXIN, 200, 100);

    lay = new QVBoxLayout(this);
    lay->addWidget(btn);
}
