
/**
 ** @file:	   basebutton.h
 ** @author:	   浓咖啡
 ** @date:	   2016.6.4
 ** @brief:      按钮基类
 */

#ifndef BASEBUTTON_H
#define BASEBUTTON_H

#include <iconhelper.h>

class BaseButton : public QPushButton
{
    Q_OBJECT
public:
    explicit BaseButton(const AbstractFont &fontLib, int iconIndex, \
                        int w, int h, const QString &style = QString());

private slots:
    virtual void pressSlot(){}  //按下后需要扩展的功能
    virtual void releaseSlot(){}  //松开后需要扩展的功能

private:

};

#endif // BASEBUTTON_H
