#include "listtest.h"

ListTest::ListTest(QWidget *parent) :
    QWidget(parent)
{
    QStringList zonelist;
    zonelist<<("北京")<<("香港")<<("首尔")<<("悉尼")<<("曼谷");
    list  = new NormalList(zonelist);
    list->setParent(this);
}
