#include "qqprocedure.h"

#define QQSTYLE   QString("background-image: url(:/image/qq.png)")

QQProcedure::QQProcedure(QWidget *parent) :
    QWidget(parent)
{
    //增加qq的截图
    QLabel *label = new QLabel(this);
    label->setStyleSheet(QQSTYLE);
    label->setFixedSize(432, 301);
    setFixedSize(432, 301);

    //核心部分，建立本地socket和桌面进程通信
    qqsocket = new QLocalSocket(this);
    qqsocket->setServerName("qq");
    qqsocket->connectToServer("qq"); //和桌面程序做连接
    connect(qqsocket, SIGNAL(readyRead()), this, SLOT(parseCmd()));
}

void QQProcedure::parseCmd()
{
    qDebug()<<"parseCmd";
    QDataStream in(qqsocket);
    QString cmdStr;
    in >> cmdStr;
    qDebug()<<"recv ="<<cmdStr;
}
