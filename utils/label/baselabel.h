/**
 ** @author:	   浓咖啡
 ** @date:	   2016.5.23
 ** @brief:      图标基类
 */
#ifndef BASELABEL_H
#define BASELABEL_H

#include "iconhelper.h"


class BaseLabel : public QLabel
{
    Q_OBJECT
public:
    explicit BaseLabel(QWidget *parent = 0);
    explicit BaseLabel(const AbstractFont &fontLib, int iconIndex, \
                       const QString &style = QString(), QWidget *parent = 0);
    void setIcon(int);
    void setFontSize(int);
    void setNewFont(const AbstractFont &);
    void setNewIcon(int iconIndex, const QString &style = QString());  //设置新的图标

signals:

protected:
    void restoreFont();  //恢复字体库，防止别的组件更改字体库
    QString fontName;  //存储字体库名称

};

#endif // BASELABEL_H
