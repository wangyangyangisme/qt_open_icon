#include "listtest.h"

ListTest::ListTest(QWidget *parent) :
    QWidget(parent)
{
    QStringList zonelist;
    zonelist<<("北京\nGMT+8:00")<<("香港\nGMT+8:00")<<("首尔\nGMT+9:00")<<("悉尼\nGMT+10:00")<<("曼谷\nGMT+7:00");
    list  = new NormalList(zonelist);
    list->setParent(this);
}
