/**
 ** @author:	   浓咖啡
 ** @date:	   2016.5.23
 ** @brief:      图标基类
 */
#include "baselabel.h"

#define DEFULT_LABEL_STYLE "\
QLabel{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    background-color:rgb(255,255,255);\
}\
"

BaseLabel::BaseLabel(QWidget *parent):QLabel(parent)
{
    //默认是mui字体
    fontName = MuiFont().getIconName();
    iconhelp::setIcon(this, MuiFont::ICON_WEINXIN);

    //字体大小需要单独设置
    QString finalStyle = DEFULT_LABEL_STYLE + \
            QString("QLabel{font:%1pt;}").arg(this->font().pointSize());

    setStyleSheet(finalStyle);
}

/**
 * @brief label基类
 * @param fontLib 选择字体库
 * @param iconIndex 选择字体库图标索引
 * @param w 长
 * @param h 宽
 * @param style 样式
 */
BaseLabel::BaseLabel(const AbstractFont &fontLib, int iconIndex, \
                     const QString &style, QWidget *parent)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
    iconhelp::setIcon(this,iconIndex);
    if(style != QString()){
        setStyleSheet(style);
    }else{
        QString finalStyle = DEFULT_LABEL_STYLE + \
                QString("QLabel{font:%1pt;}").arg(this->font().pointSize());
        setStyleSheet(finalStyle);
    }
}

void BaseLabel::setIcon(int index)
{
    iconhelp::setIcon(this, index);
}

void BaseLabel::setFontSize(int ptSize)
{
    QString finalStyle = this->styleSheet() + \
            QString("QLabel{font:%1pt;}").arg(ptSize);

    setStyleSheet(finalStyle);
}

void BaseLabel::setNewFont(const AbstractFont &fontLib)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
}

/**
 * @brief BaseLabel::setNewIcon
 * @param iconIndex 新字体库图标索引
 * @param style 新样式
 */
void BaseLabel::setNewIcon(int iconIndex,const QString &style)
{
    //恢复字体库，防止别的组件更改字体库
    IconHelper::Instance()->setNewIcon(AbstractFont(fontName));
    iconhelp::setIcon(this,iconIndex);
    if(style != QString()){
        setStyleSheet(style);
    }
}
