#include "buttontest.h"

ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent)
{
    //BaseButton
    QLabel *baseButtonLab = new QLabel("BaseButton:");
    BaseButton *baseButton = new BaseButton(MuiFont(), MuiFont::ICON_WEINXIN, 200, 100);

    //switchbutton
    QLabel *switchButtonLab = new QLabel("SwitchButton:");
    SwitchButton *switchButton = new SwitchButton(FontawesomeWebfont(), \
                                                  FontawesomeWebfont::ICON_UNLOCK,
                                                  FontawesomeWebfont::ICON_LOCK,
                                                  200, 100);
    //loopbutton
//    QList<int> list;
//    list.append(1);
//    QLabel *loopButtonLab = new QLabel("loopButton:");
//    LoopButton *loopButton = new LoopButton(FontawesomeWebfont(), list,\
//                                                  200, 100);

    lay = new QGridLayout(this);
    lay->addWidget(baseButtonLab, 0, 0);
    lay->addWidget(baseButton, 0, 1);
    lay->addWidget(switchButtonLab, 1, 0);
    lay->addWidget(switchButton, 1, 1);
//    lay->addWidget(loopButtonLab, 2, 0);
//    lay->addWidget(loopButton, 2, 1);
}
