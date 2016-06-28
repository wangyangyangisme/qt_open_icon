#ifndef TIMEDISPLAY_H
#define TIMEDISPLAY_H

#include "headutils.h"

class TimeDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit TimeDisplay(QWidget *parent = 0);

signals:

public slots:

private:
    HeadUtils *head;
};

#endif // TIMEDISPLAY_H
