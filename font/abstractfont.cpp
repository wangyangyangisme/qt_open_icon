#include "abstractfont.h"
#include "assert.h"

/**
 * @brief 一点小技巧，防止子类用默认的构造函数
 */
AbstractFont::AbstractFont()
{
    int *p = NULL;
    qDebug("can't use this constructed function");
    assert(p != NULL);  //防止子类使用默认构造
}

AbstractFont::AbstractFont(const QString &_name)
{
    name = _name;
    int fontId=QFontDatabase::addApplicationFont(_name + QString(".ttf"));
    QString fontName=QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont=QFont(fontName);
}
