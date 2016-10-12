#include "qqprocedure.h"

QQProcedure::QQProcedure():Procedure("qq", "qqproce.exe")
{
//    setArgQWS();  //嵌入式qt程序需要增加选项
}

BaseButton *QQProcedure::createIcon()
{
    BaseButton *iconBtn = new BaseButton(MuiFont(), MuiFont::ICON_QQ, 100, 100);
    return iconBtn;
}
