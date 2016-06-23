#ifndef DIALOGTEST_H
#define DIALOGTEST_H

#include "toast.h"

class DialogTest : public QWidget
{
    Q_OBJECT
public:
    explicit DialogTest();

signals:

public slots:

private slots:
    void toastSlot();
};

#endif // DIALOGTEST_H
