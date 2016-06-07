#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include "basebutton.h"

class SwitchButton : public BaseButton
{
    Q_OBJECT
public:
    explicit SwitchButton(const AbstractFont &fontLib, int iconIndex1, int iconIndex2, \
                          int w, int h, const QString &style = QString());

signals:

public slots:

};

#endif // SWITCHBUTTON_H
