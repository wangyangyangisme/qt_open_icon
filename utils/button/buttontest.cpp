#include "buttontest.h"

ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent)
{
    //BaseButton
    QLabel *baseButtonLab = new QLabel("BaseButton:");
    BaseButton *baseButton = new BaseButton(MuiFont(), MuiFont::ICON_WEINXIN, 200, 100);

    //batteryButtonLab
    QLabel *batteryButtonLab = new QLabel("BatteryButton:");
    BatteryButton *batteryButton = new BatteryButton(BatteryButton::EMPTY, EMPTY_BATTERY_STYLE);

    //switchbutton
    QLabel *switchButtonLab = new QLabel("SwitchButton:");
    SwitchButton *switchButton = new SwitchButton(FontawesomeWebfont(), \
                                                  FontawesomeWebfont::ICON_UNLOCK,
                                                  FontawesomeWebfont::ICON_LOCK,
                                                  200, 100);

    lay = new QGridLayout(this);
    lay->addWidget(baseButtonLab, 0, 0);
    lay->addWidget(baseButton, 0, 1);
    lay->addWidget(batteryButtonLab, 0, 2);
    lay->addWidget(batteryButton, 0, 3);
    lay->addWidget(switchButtonLab, 1, 0);
    lay->addWidget(switchButton, 1, 1);
}
