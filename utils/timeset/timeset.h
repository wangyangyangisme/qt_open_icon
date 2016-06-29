#ifndef TIMESET_H
#define TIMESET_H

#include "headutils.h"

class TimeSet : public QWidget
{
    Q_OBJECT
public:
    explicit TimeSet(QWidget *parent = 0);

signals:
    void backDisp();

private:
    HeadUtils *head;
};

#endif // TIMESET_H
