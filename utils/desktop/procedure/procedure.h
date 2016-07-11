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
    explicit Procedure(const QString &_socketname, const QString &_proName, \
                       const QStringList &_arguments = QStringList());
    bool sendCmd(int cmd);
    bool startProcedure();
    void init();  //执行一些初始化工作

signals:
    void startResult(bool);

protected slots:
    void connectionSlot();
    void startProSlot();
    virtual void proExitHandler(int code, QProcess::ExitStatus status);
    void disconnectSlot();

protected:
    virtual BaseButton *createIcon() = 0;
    bool startSocketServer();

public:
    BaseButton *proIcon;  //应用图标
    void closeHandler();  //关闭子进程一些处理

private:
    QLocalServer *server;  //本地socket服务端
    QLocalSocket *client;  //本地socket客户端
    QProcess *process;  //进程
    QString socketName;  //socket监听名称
    QString proName;  //可执行程序名称
    QStringList arguments;  //可执行程序需要参数
    bool isRun;  //程序是否已经运行
    QMutex mutex;
};

#endif // PROCEDURE_H
