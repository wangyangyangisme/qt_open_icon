#include "desktop.h"
#include "toast.h"

Desktop::Desktop(QWidget *parent) :
    QWidget(parent)
{
    //这里注意路径适配
    qq = new QQProcedure();
    qq->init();
    connect(qq, SIGNAL(startResult(bool)), this, SLOT(startSlot(bool)));

    //界面布局
    QGridLayout *lay = new QGridLayout(this);
    lay->addWidget(qq->proIcon, 0, 0);
    resize(QApplication::desktop()->width(), QApplication::desktop()->height());
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.7);  //透明度设置
    setStyleSheet("background-color:#EEB422");
}

/**
 * @brief 程序启动情况
 * @param ret
 */
void Desktop::startSlot(bool ret)
{
    qDebug()<<"start="<<ret;
    if(ret){  //启动成功
        Toast *w = new Toast(this, "程序启动中,请稍后...");
        w->toast();
    }else{
        Toast *w = new Toast(this, "启动失败,请检查");
        w->toast();
    }
}
