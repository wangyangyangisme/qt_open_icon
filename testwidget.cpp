#include "testwidget.h"

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    isLock(true)
{
    //默认使用MUI库
    lab = new QLabel;
    lab->setAlignment(Qt::AlignCenter);
    iconhelp::setIcon(lab,MuiFont::ICON_WEINXIN);
    lab->setStyleSheet("\
                       QLabel{\
                           color:red;\
                           font:100px;\
                           border-radius:10;\
                           background-color:yellow;\
                       }\
                       ");
    IconHelper::Instance()->setNewIcon(FontawesomeWebfont());  //使用新的图标库
    lock = new QPushButton;
    iconhelp::setIcon(lock,FontawesomeWebfont::ICON_LOCK);
    connect(lock,SIGNAL(released()),this,SLOT(btnStateChange()));
    lock->setStyleSheet("\
                       QPushButton{\
                           color:#DDDDDD;\
                           font:100px;\
                           border-radius:10;\
                           background-color:black;\
                       }\
                       QPushButton:pressed{\
                           color:palegreen;\
                           background-color:#FFAA33;\
                       }\
                       ");

    IconHelper::Instance()->setNewIcon(MuiFont());  //使用自定义图标库
    btn = new QPushButton;
    iconhelp::setIcon(btn,MuiFont::ICON_PENGYOUQUAN);
    btn->setStyleSheet("\
                       QPushButton{\
                           color:red;\
                           font:100px;\
                           border-radius:10;\
                           background-color:yellow;\
                       }\
                       QPushButton:hover{\
                           color:blue;\
                           background-color:black;\
                       }\
                       QPushButton:pressed{\
                           color:palegreen;\
                       }\
                       ");

    lay = new QVBoxLayout(this);
    lay->addWidget(btn);
    lay->addWidget(lock);
    lay->addWidget(lab);

    setFixedSize(200, 300);
}

void TestWidget::btnStateChange()
{
    //最后一个按钮已经替换了图标库
    IconHelper::Instance()->setNewIcon(FontawesomeWebfont());
    if(isLock){
        iconhelp::setIcon(lock,FontawesomeWebfont::ICON_UNLOCK);
        isLock = false;
    }else{
        iconhelp::setIcon(lock,FontawesomeWebfont::ICON_LOCK);
        isLock = true;
    }

}
