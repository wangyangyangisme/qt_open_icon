#include "qqprocedure.h"

QQProcedure::QQProcedure(const QString &_socketname, const QString &_proName, \
                         const QStringList &_arguments)\
    :Procedure(_socketname, _proName, _arguments)
{

}

BaseButton *QQProcedure::createIcon()
{
    BaseButton *iconBtn = new BaseButton(MuiFont(), MuiFont::ICON_QQ, 100, 100);
    return iconBtn;
}
