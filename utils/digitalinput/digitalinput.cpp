#include "digitalinput.h"

#define LEFT_STYLE "\
QPushButton{\
color:#000000;\
font:50px;\
border:1px solid #AAAAAA;\
    border-top-left-radius:5;\
    border-bottom-left-radius:5;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

#define RIGHT_STYLE "\
QPushButton{\
color:#000000;\
font:50px;\
border:1px solid #AAAAAA;\
    border-top-right-radius:5;\
    border-bottom-right-radius:5;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"


#define EDIT_STYLE "\
QLineEdit{\
    border-top-width:1px;\
    border-bottom-width:1px;\
    border-color:#AAAAAA;\
    background-color:#FFFFFF;\
}\
QLineEdit:focus {\
    border-top-width:1px;\
    border-bottom-width:1px;\
    border-color:#AAAAAA;\
    background-color:#FFFFFF;\
}\
"


DigitalInput::DigitalInput(int w, int h)
{
    add = new BaseButton(MuiFont(), MuiFont::ICON_MINUS, w, h, LEFT_STYLE);
    down = new BaseButton(MuiFont(), MuiFont::ICON_PLUS, w, h, RIGHT_STYLE);
    textEdit = new QLineEdit();
    textEdit->setMinimumSize(50, 52);
    textEdit->setStyleSheet(EDIT_STYLE);

    QHBoxLayout *lay = new QHBoxLayout(this);
    lay->setSpacing(0);
    lay->setMargin(0);
    lay->addWidget(add);
    lay->addWidget(textEdit);
    lay->addWidget(down);
}
