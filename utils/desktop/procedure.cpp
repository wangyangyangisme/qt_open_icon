#include "procedure.h"

Procedure::Procedure(const QString &_name):
    name(_name),
    client(NULL)
{
    //初始化服务端
    server = new QLocalServer();
    if (!server->listen(name)) {
        qDebug()<<"server listen err";
        return;
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(connectionSlot()));
}

void Procedure::connectionSlot()
{
    client = server->nextPendingConnection();
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), client, SLOT(deleteLater()));

}

bool Procedure::sendCmd(int cmd)
{
    if(client != NULL){
        QString cmdStr = cmdStr.number(cmd);
        QByteArray cmdStream;
        QDataStream out(&cmdStream, QIODevice::WriteOnly);
        out << cmdStr;

        if(client->write(cmdStream) == -1){
            return false;
        }else{
            return true;
        }
    }else{
        return false;
    }
}
