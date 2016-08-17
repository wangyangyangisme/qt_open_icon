#include "procedure.h"

#define PROCEDURE_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    font:100px;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#EEE685;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

#define PROCEDURE_RUN_STYLE "\
QPushButton{\
    color:#000000;\
    font:100px;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#9ACD32;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

Procedure::Procedure(const QString &_socketname, const QString &_proName, \
                     const QStringList &_arguments):
    socketName(_socketname),
    proName(_proName),
    arguments(_arguments),
    client(NULL),
    proIcon(NULL),
    isRun(false)
{
}

/**
 * @brief 把所有虚函数初始化放到这个里边
 * @return
 */
void Procedure::init()
{
    //初始化图标
    proIcon = createIcon();
    proIcon->setStyleSheet(PROCEDURE_BUTTON_STYLE);
    connect(proIcon, SIGNAL(btnReleased()), this, SLOT(startProSlot()));
}

void Procedure::startProSlot()
{
    if(isRun){
        qDebug()<<proName<<" has run";
        sendCmd(10);
    }else{
        bool startRet = (startSocketServer() && startProcedure());
        if(startRet){
            isRun = true;
            proIcon->setStyleSheet(PROCEDURE_RUN_STYLE);
            emit startResult(true);
        }else{
            emit startResult(false);
        }
    }
}

bool Procedure::startSocketServer()
{
    //初始化服务端
#ifdef Q_OS_LINUX
    //linux下有些特殊，详情参考listen函数帮助文档
    QString socketTmp = QString("/tmp/") + socketName;
    QFile file(socketTmp);
    if(file.exists()){
        file.remove();
    }
#elif defined Q_OS_WIN
#elif defined Q_OS_MAC
#endif
    server = new QLocalServer();
    if (!server->listen(socketName)) {
        qDebug()<<"server listen err";
        return false;
    }else{
        qDebug()<<socketName<<" is listening";
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(connectionSlot()));
    return true;
}


/**
 * @brief 启动进程
 * @return 成功返回true，失败返回false
 */
bool Procedure::startProcedure()
{
    process = new QProcess;
    process->start(proName, arguments);
    if (!process->waitForStarted())
    {
        qDebug()<<proName<<" process start err";
        return false;
    }else{
        qDebug()<<proName<<" process start success";
        connect(process, SIGNAL(finished(int,QProcess::ExitStatus)),\
                this, SLOT(proExitHandler(int,QProcess::ExitStatus)));
        return true;
    }
}

void Procedure::connectionSlot()
{
    qDebug()<<proName<<" socket connect";
    client = server->nextPendingConnection();
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnectSlot()));
}


bool Procedure::sendCmd(int cmd)
{
    if(client != NULL){
        QString cmdStr = cmdStr.number(cmd);
        QByteArray cmdStream;
        QDataStream out(&cmdStream, QIODevice::WriteOnly);
        out << cmdStr.toLatin1().data();

        if(client->write(cmdStream) == -1){
            return false;
        }else{
            return true;
        }
    }else{
        qDebug()<<socketName<<" client is null";
        return false;
    }
}


void Procedure::proExitHandler(int code, QProcess::ExitStatus status)
{
    qDebug()<<proName<<" exit code = "<<code;
    closeHandler();
}

/**
 * @brief 如果子进程和桌面程序断开连接，那么就杀死子进程
 * 因为此时桌面已经控制不了子进程了
 */
void Procedure::disconnectSlot()
{
    qDebug()<<proName<<" socket disconnect";
    //这里处理失败，子程序结束后首先调用这里一次，然后清理掉各个变量
    //然后杀掉process时候又执行一次，加锁无效
//    closeHandler();
}

/**
 * @brief 关闭子进程一些处理
 */
void Procedure::closeHandler()
{
//    QMutexLocker locker(&mutex);
    if(isRun){
        isRun = false;
        process->close();
        server->close();
        delete server;
        server = NULL;
        delete process;
        process = NULL;
        proIcon->setStyleSheet(PROCEDURE_BUTTON_STYLE);
    }
}
