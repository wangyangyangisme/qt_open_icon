#include "qqprocedure.h"

QQProcedure::QQProcedure():Procedure("qq", "qqproce.exe")
{
//    setArgQWS();
}

BaseButton *QQProcedure::createIcon()
{
    BaseButton *iconBtn = new BaseButton(MuiFont(), MuiFont::ICON_QQ, 100, 100);
    return iconBtn;
}
