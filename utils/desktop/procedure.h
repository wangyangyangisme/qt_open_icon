/**
 ** @author:	   浓咖啡
 ** @date:	   2016.7.7
 ** @brief:      对单个程序封装
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H

#include "basebutton.h"
#include <QLocalServer>
#include <QLocalSocket>

class Procedure : public QObject
{
    Q_OBJECT
public:
    explicit Procedure(const QString &name);
    bool sendCmd(int cmd);

signals:

public slots:

public:
    BaseButton *proIcon;  //应用图标
    QLocalServer *server;  //本地socket服务端
    QLocalSocket *client;  //本地socket客户端
    QProcess *process;  //进程
    QString name;  //程序名称
    QTimer *timer;

protected:
    void connectionSlot();
};

#endif // PROCEDURE_H
