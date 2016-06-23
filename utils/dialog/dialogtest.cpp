#include "dialogtest.h"

DialogTest::DialogTest()
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    QPushButton *toastBtn = new QPushButton("toast");
    lay->addWidget(toastBtn);
    setFixedSize(500, 500);

    connect(toastBtn,SIGNAL(released()),this,SLOT(toastSlot()));
}


void DialogTest::toastSlot()
{
    Toast *w = new Toast(this, 1, 1, "abcdfaffgasdfsdfsfdfe");
    w->show();
    w->toast();
}
