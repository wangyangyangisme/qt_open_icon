/**
 ** @author:	   浓咖啡
 ** @date:	   2016.12.8
 ** @brief:      导航栏
 */

#include "navbar.h"

#define TOTAL_STYLE "\
QWidget{\
    background-color:#E3E3E3;\
}\
"

#define BTN_STYLE "\
QPushButton{\
    color:#3A5FCD;\
    border:0px;\
    border-radius:0;\
}\
QPushButton:pressed{\
    color:#79CDCD;\
}\
"

Navbar::Navbar(QWidget *parent, int h):QWidget(parent)
{
    int iconSize = 2*h/3;  //取总宽度的2/3作为图标大小

    //整体布局
    lay = new QHBoxLayout(this);
    lay->setMargin(0);
    lay->setSpacing(0);

    //左按钮
    leftbtn = new BaseButton(TimeFont(), TimeFont::ICON_BACK, BTN_STYLE);
    leftbtn->setIconSize(iconSize);
    leftbtn->setMinimumHeight(h);
    leftbtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //中间标题
    centerLab = new QLabel;
    centerLab->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLab->setText(QString("中间标题"));

    //右边按钮
    rightbtn = new BaseButton;
    rightbtn->setText(QString("编辑"));
    rightbtn->setMinimumHeight(h);
    rightbtn->setStyleSheet(BTN_STYLE);
    rightbtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    lay->addWidget(leftbtn, 1);
    lay->addWidget(centerLab, 10);
    lay->addWidget(rightbtn, 1);

    this->setStyleSheet(TOTAL_STYLE);

    connect(leftbtn, SIGNAL(btnReleased()),
                     this,  SIGNAL(lBtnSig()));
    connect(rightbtn, SIGNAL(btnReleased()),
                     this,  SIGNAL(rBtnSig()));
}

//下面replaceWidget接口只有5版本以上才支持
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
void Navbar::setLBtn(BaseButton *btn)
{
    lay->replaceWidget(leftbtn, btn);
    disconnect(leftbtn, SIGNAL(btnReleased()),
                     this,  SIGNAL(lBtnSig()));
    delete leftbtn;
    leftbtn = btn;
    connect(leftbtn, SIGNAL(btnReleased()),
                     this,  SIGNAL(lBtnSig()));
}

void Navbar::setRBtn(BaseButton *btn)
{
    lay->replaceWidget(rightbtn, btn);
    disconnect(rightbtn, SIGNAL(btnReleased()),
                     this,  SIGNAL(lBtnSig()));
    delete rightbtn;
    rightbtn = btn;
    connect(rightbtn, SIGNAL(btnReleased()),
                     this,  SIGNAL(lBtnSig()));
}

#endif
