#include "dialogtest.h"
#include "common.h"

DialogTest::DialogTest()
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    QPushButton *toastBtn = new QPushButton("toast");
    toastBtn->setFixedWidth(50);
    utilscommon::setShadow(toastBtn);
    lay->addWidget(toastBtn);
    setFixedSize(300, 300);

    connect(toastBtn,SIGNAL(released()),this,SLOT(toastSlot()));
}


void DialogTest::toastSlot()
{
    Toast *w = new Toast(this, "这是一个好的组件库");
    w->toast();
}
