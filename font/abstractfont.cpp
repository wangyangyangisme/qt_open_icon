#include "abstractfont.h"

#define FONT_PATH ":/font/resourse/font/"

/**
 * @brief 所有子类都要调用这个构造
 * @param _name 字体库名称，也是代表ttf文件名称，会根据此名称加载字体库
 */
AbstractFont::AbstractFont(const QString &_name)
{
    name = _name;
    int fontId=QFontDatabase::addApplicationFont(FONT_PATH + _name + QString(".ttf"));
    QString fontName=QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName);
}
