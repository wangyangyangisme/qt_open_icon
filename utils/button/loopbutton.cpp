#include "loopbutton.h"

LoopButton::LoopButton(const AbstractFont &fontLib, QList<int> iconList, int w, int h, const QString &style):
    BaseButton(fontLib, iconList.at(0), w, h, style),
    curIndex(0)
{
    this->iconList = iconList;
}

/**
 * @brief 切换到指定的图标
 * @param index
 */
void LoopButton::switchIndex(int index)
{
    if(index<iconList.length() && index>0){
        restoreFont();
        iconhelp::setIcon(this,index);
    }
}




