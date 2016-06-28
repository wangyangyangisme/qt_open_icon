#ifndef TIMETOTAL_H
#define TIMETOTAL_H

#include "headutils.h"
#include "animationwidget.h"

class TimeTotal : public QWidget
{
    Q_OBJECT
public:
    explicit TimeTotal(QWidget *parent = 0);

signals:

public slots:
    void test();

private:
    AnimationWidget *total;
    QList<QWidget *> list;
    QWidget *wig1;
    QWidget *wig2;
    QWidget *wig3;
    int curWig;
    static const int w=355;
    static const int h=200;
};

#endif // TIMETOTAL_H
