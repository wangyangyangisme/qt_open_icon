#include "switchbutton.h"

SwitchButton::SwitchButton(const AbstractFont &fontLib, int iconIndex1, int iconIndex2, int w, int h, const QString &style):
    BaseButton(fontLib, iconIndex1, w, h, style),
    flag(true)
{
    index1 = iconIndex1;
    index2 = iconIndex2;
    connect(this,SIGNAL(released()),this,SLOT(releaseSlot()));
}

void SwitchButton::releaseSlot()
{
    IconHelper::Instance()->setNewIcon(AbstractFont(fontName));
    if(flag){
        iconhelp::setIcon(this,index1);
        flag = false;
    }else{
        iconhelp::setIcon(this,index2);
        flag = true;
    }
}
