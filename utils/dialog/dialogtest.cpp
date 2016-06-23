#include "dialogtest.h"
#include "common/common.h"

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
    Toast *w = new Toast(this, "我们");
    w->show();
    w->toast();
}
