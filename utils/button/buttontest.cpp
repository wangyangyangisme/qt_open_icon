#include "buttontest.h"

ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent)
{
    //BaseButton
    QLabel *baseButtonLab = new QLabel("basebutton:");
    BaseButton *baseButton = new BaseButton(MuiFont(), MuiFont::ICON_WEINXIN, 200, 100);

    //switchbutton
    QLabel *switchButtonLab = new QLabel("switchButtonLab:");
    SwitchButton *switchButton = new SwitchButton(FontawesomeWebfont(), \
                                                  FontawesomeWebfont::ICON_UNLOCK,
                                                  FontawesomeWebfont::ICON_UNLOCK,
                                                  1, 200, 100);


    lay = new QGridLayout(this);
    lay->addWidget(baseButtonLab, 0, 0);
    lay->addWidget(baseButton, 0, 1);
    lay->addWidget(switchButtonLab, 1, 0);
    lay->addWidget(switchButton, 1, 1);
}
