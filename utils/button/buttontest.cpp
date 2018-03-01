#include "buttontest.h"

//渐变样式示例
#define SWITCH_BUTTON_STYLE "\
QPushButton{\
    color:QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #CC00CC, stop:1 #CCFF99);\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background: QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #0066FF, stop:1 #33FFFF);\
}\
QPushButton:pressed{\
    color:QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #CCEEFF, stop:1 #F0BBFF);\
    background: QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #FF8800, stop:1 #FFFF77);\
}\
"

#define DEFULT_LABEL_STYLE "\
QLabel{\
    color:#000000;\
    font:40px;\
    border:0px;\
    background-color:rgb(0,0,0,0);\
}\
"


ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle(QString("基础按钮测试"));
    //BaseButton
    QLabel *baseButtonLab = new QLabel("BaseButton:");
    BaseButton *baseButton = new BaseButton(MuiFont(), MuiFont::ICON_WEINXIN);
    baseButton->resize(200, 100);
    baseButton->setFontSize(80);

    //batteryButtonLab
    QLabel *batteryButtonLab = new QLabel("BatteryButton:");
    BatteryButton *batteryButton = new BatteryButton;
    batteryButton->resize(200, 100);

    //switchbutton
    QLabel *switchButtonLab = new QLabel("SwitchButton:");
    SwitchButton *switchButton = new SwitchButton;
    switchButton->resize(200, 100);
    switchButton->setStyleSheet(SWITCH_BUTTON_STYLE);
    switchButton->setFontSize(80);

    //groupbutton
    QLabel *gourpButtonLab = new QLabel("GourpButton:");
    GroupButton *groupButton = new GroupButton(MuiFont(), \
                                                  MuiFont::ICON_WEINXIN,
                                               200, 100, "微信", "", "");

    lay = new QGridLayout(this);
    lay->addWidget(baseButtonLab, 0, 0);
    lay->addWidget(baseButton, 0, 1);
    lay->addWidget(batteryButtonLab, 0, 2);
    lay->addWidget(batteryButton, 0, 3);
    lay->addWidget(switchButtonLab, 1, 0);
    lay->addWidget(switchButton, 1, 1);
    lay->addWidget(gourpButtonLab, 1, 2);
    lay->addWidget(groupButton, 1, 3);
}
