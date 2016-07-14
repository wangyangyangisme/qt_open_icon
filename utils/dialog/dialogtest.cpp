#include "dialogtest.h"

#define QMESSAGEBOX_STYLE "\
QMessageBox{\
    color:#000000;\
    font:10px;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#FFFFFF;\
}\
QMessageBox QPushButton{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

DialogTest::DialogTest()
{
    QVBoxLayout *lay = new QVBoxLayout(this);

    //toast演示
    QPushButton *toastBtn = new QPushButton("toast");
    toastBtn->setFixedWidth(50);
    QPushButton *waningBtn = new QPushButton("警告演示");
    waningBtn->setFixedWidth(50);

    lay->addWidget(toastBtn);
    lay->addWidget(waningBtn);

    connect(toastBtn,SIGNAL(released()),this,SLOT(toastSlot()));
    connect(waningBtn,SIGNAL(released()),this,SLOT(warningSlot()));

    setFixedSize(300, 300);
}


void DialogTest::toastSlot()
{
    Toast *w = new Toast(this, "这是一个好的组件库");
    w->toast();
}

void DialogTest::warningSlot()
{
    BaseLabel *labIcon = new BaseLabel(FontawesomeWebfont(), FontawesomeWebfont::ICON_WAINING, 20, 20);
    BaseMessageBox *w = new BaseMessageBox(labIcon, "警告", "确定删除？");
    switch (w->exec()) {
    case BaseMessageBox::OK:
        qDebug()<<"ok";
        break;
    default:
        qDebug()<<"cancel";
        break;
    }
}
