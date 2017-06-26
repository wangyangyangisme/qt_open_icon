#ifndef ABSTRACTFONT_H
#define ABSTRACTFONT_H

#include <QObject>
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWidgets>
#else
#include <QtGui>
#endif

/**
 * @brief 抽象字体库基类
 */
class AbstractFont
{
public:
    explicit AbstractFont(const QString &_name);
    QFont getIconFont()const{return iconFont;}
    QString getIconName()const{return name;}

private:
    QFont iconFont;
    QString name; //字体库的名称  比如：mui/fontawesome-webfont
};

#endif // ABSTRACTFONT_H
