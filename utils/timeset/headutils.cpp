#include "headutils.h"

#define BACK_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    font:30px;\
    border:0px solid #AAAAAA;\
    border-radius:15;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

HeadUtils::HeadUtils(QWidget *parent) :
    QWidget(parent)
{
    back = new BaseButton(TimeFont(), TimeFont::ICON_BACK, 30, 30, BACK_BUTTON_STYLE);
    hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(back);
    this->setFixedSize(100, 100);
}
