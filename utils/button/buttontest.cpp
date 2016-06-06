#include "buttontest.h"

ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent)
{
    QLabel baseButtonLab("basebutton:");
    baseButton = new BaseButton(MuiFont(), MuiFont::ICON_WEINXIN, 200, 100);

    lay = new QGridLayout(this);
    lay->addWidget(&baseButtonLab, 0, 0);
    lay->addWidget(baseButton, 0, 1);
}
