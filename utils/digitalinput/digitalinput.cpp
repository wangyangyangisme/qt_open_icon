#include "digitalinput.h"

#define DIGITALINPUT_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    font:50px;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

DigitalInput::DigitalInput(int w, int h)
{
    add = new BaseButton(MuiFont(), MuiFont::ICON_WEINXIN, w, h, DIGITALINPUT_BUTTON_STYLE);
    down = new BaseButton(MuiFont(), MuiFont::ICON_QQ, w, h, DIGITALINPUT_BUTTON_STYLE);
    textEdit = new QLineEdit();
    textEdit->setMinimumSize(50, 50);

    QHBoxLayout *lay = new QHBoxLayout(this);
    lay->addWidget(add);
    lay->addWidget(textEdit);
    lay->addWidget(down);
}
