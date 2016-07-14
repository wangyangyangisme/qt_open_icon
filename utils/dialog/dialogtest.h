#ifndef DIALOGTEST_H
#define DIALOGTEST_H

#include "toast.h"
#include "basemessagebox.h"

class DialogTest : public QWidget
{
    Q_OBJECT
public:
    explicit DialogTest();

signals:

public slots:

private slots:
    void toastSlot();
    void warningSlot();

private:

};

#endif // DIALOGTEST_H
