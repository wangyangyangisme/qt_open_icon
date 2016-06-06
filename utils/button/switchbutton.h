
/**
 ** @file:	   basebutton.h
 ** @author:	   浓咖啡
 ** @date:	   2016.6.6
 ** @brief:      开关按钮：支持两种图标的按钮变化
 */
#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include "basebutton.h"

class SwitchButton : public BaseButton
{
    Q_OBJECT
public:
    SwitchButton(const AbstractFont &fontLib, int iconIndex1, int iconIndex2,\
                 int w, int h, const QString &style = QString());

protected:
    AbstractFont _fontLib;
    int index1;
    int index2;
};

#endif // SWITCHBUTTON_H
