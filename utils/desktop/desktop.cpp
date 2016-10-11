#include "desktop.h"

#include "toast.h"

Desktop::Desktop(QWidget *parent) :
    QWidget(parent)
{
    //启动按键服务
//    keyDetect = new KeyDetect;
//    keyDetect->start();
//    connect(keyDetect, SIGNAL(submitKeyVal(int)), this, SLOT(keyHandler(int)));

    //总体布局
    QGridLayout *lay = new QGridLayout(this);

    //qq示例程序
    qqProcedure = new QQProcedure;
    qqProcedure->init();
    lay->addWidget(qqProcedure->proIcon, 2, 1);
    connect(qqProcedure, SIGNAL(startResult(bool)), this, SLOT(startSlot(bool)));
    connect(qqProcedure, SIGNAL(enterPro()), this, SLOT(enterProSlot()));

    setWindowOpacity(0.9);  //透明度设置
    setStyleSheet("background-color:#CDC9C9");
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(800, 480);
}

/**
 * @brief 返回桌面
 */
void Desktop::returnDesktop()
{
    qDebug()<<"returnDesktop";
    //先发出命令让窗口隐藏
    if(qqProcedure->getState()){
        qqProcedure->sendCmd(PROCEDURE_HIDE);
    }
    QTimer::singleShot(100, this, SLOT(laterShowDesk()));
}

void Desktop::laterShowDesk()
{
    this->show();
}

/**
 * @brief 程序启动情况
 * @param ret
 */
void Desktop::startSlot(bool ret)
{
    qDebug()<<"start="<<ret;
    if(ret){  //启动成功
        Toast *w = new Toast(this, "procedure starting, wait...");
        w->toast();
        this->hide();  //启动成功后隐藏桌面
    }else{
        Toast *w = new Toast(this, "start err, please check");
        w->toast();
    }
}

/**
 * @brief 程序从后台转到前台
 */
void Desktop::enterProSlot()
{
    //1.桌面要隐藏
    this->hide();
    //2.子进程界面要显示,这个Procedure里已经处理
}

