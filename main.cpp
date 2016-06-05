#include "buttontest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    ButtonTest *w = new ButtonTest;
//    w->show();

    IconHelper::Instance()->setNewIcon(MuiFont());  //选择含有微信图标的字体库
    QPushButton *btn = new QPushButton;
    iconhelp::setIcon(btn,MuiFont::ICON_WEINXIN);
    btn->setStyleSheet("font:100px;color:red");
    btn->show();

    return a.exec();
}
