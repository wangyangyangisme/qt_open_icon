#include "desktop.h"

Desktop::Desktop(QWidget *parent) :
    QWidget(parent)
{
    procedure = new Procedure("image", "ipc_client.exe");
    procedure->proIcon->setParent(this);
    setFixedSize(200,200);
}
