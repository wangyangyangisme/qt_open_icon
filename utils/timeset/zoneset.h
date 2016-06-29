#ifndef ZONESET_H
#define ZONESET_H

#include "headutils.h"

class ZoneSet : public QWidget
{
    Q_OBJECT
public:
    explicit ZoneSet(QWidget *parent = 0);

signals:
    void backDisp();

private:
    HeadUtils *head;
};
#endif // ZONESET_H
