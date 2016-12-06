#ifndef LISTTEST_H
#define LISTTEST_H

#include "normallist.h"

class ListTest : public QWidget
{
    Q_OBJECT
public:
    explicit ListTest(QWidget *parent = 0);

signals:

public slots:

private:
    NormalList *list;
};

#endif // LISTTEST_H
