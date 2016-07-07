#include "dialogtest.h"
#include "utilscommon.h"

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
    utilscommon::setShadow(toastBtn);

    //messagebox
    QMessageBox *messageBox = new QMessageBox(QMessageBox::NoIcon,\
                "title", "content", QMessageBox::Ok|QMessageBox::Cancel);
    messageBox->setStyleSheet(QMESSAGEBOX_STYLE);

    lay->addWidget(toastBtn);
    lay->addWidget(messageBox);
//    setFixedSize(300, 300);

    connect(toastBtn,SIGNAL(released()),this,SLOT(toastSlot()));
}


void DialogTest::toastSlot()
{
    Toast *w = new Toast(this, "这是一个好的组件库");
    w->toast();
}
