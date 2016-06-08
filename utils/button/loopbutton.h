
/**
 ** @file:	   loopbutton.h
 ** @author:	   浓咖啡
 ** @date:	   2016.6.8
 ** @brief:      适用于多个图标切换的按钮
 */

#ifndef LOOPBUTTON_H
#define LOOPBUTTON_H

#include "basebutton.h"

class LoopButton : public BaseButton
{
    Q_OBJECT
public:
    LoopButton(const AbstractFont &fontLib, QList<int> iconList, int w, int h, const QString &style);
signals:

protected slots:
    virtual void releaseSlot();  //松开后需要扩展的功能

protected:
    void switchIndex(int index);
    QList<int> iconList;
    int curIndex;
};

#endif // LOOPBUTTON_H
