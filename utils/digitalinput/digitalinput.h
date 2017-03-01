#ifndef DIGITALINPUT_H
#define DIGITALINPUT_H

#include "basebutton.h"

class DigitalInput : public QWidget
{
    Q_OBJECT
public:
    explicit DigitalInput(int w, int h);

signals:

public slots:

private:
    BaseButton *add;
    BaseButton *down;
    QLineEdit *textEdit;
};

#endif // DIGITALINPUT_H
