#include "basebutton.h"

#define DEFULT_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

//background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));

/**
 * @brief 会产生示例按钮，默认使用mui字体显示微信图标
 */
BaseButton::BaseButton(QWidget *parent):QPushButton(parent)
{
    //默认是mui字体
    fontName = MuiFont().getIconName();
    iconhelp::setIcon(this, MuiFont::ICON_WEINXIN);

    //字体大小需要单独设置
    QString finalStyle = DEFULT_BUTTON_STYLE + \
            QString("QPushButton{font:%1pt;}").arg(this->font().pointSize());

    setStyleSheet(finalStyle);

    connect(this, SIGNAL(btnReleased()), this, SLOT(releaseSlot()));
}

/**
 * @brief 按钮基类
 * @param fontLib 选择字体库
 * @param iconIndex 选择字体库图标索引
 * @param w 长
 * @param h 宽
 * @param style 样式
 */
BaseButton::BaseButton(const AbstractFont &fontLib, int iconIndex, \
                       const QString &style, QWidget *parent):QPushButton(parent)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
    iconhelp::setIcon(this,iconIndex);

    if(style != QString()){
        setStyleSheet(style);
    }else{
        setStyleSheet(DEFULT_BUTTON_STYLE);
    }

    connect(this,SIGNAL(btnReleased()),this,SLOT(releaseSlot()));
}

void BaseButton::setIcon(int index)
{
    iconhelp::setIcon(this, index);
}

void BaseButton::setFontSize(int ptSize)
{
    QString finalStyle = this->styleSheet() + \
            QString("QPushButton{font:%1pt;}").arg(ptSize);

    setStyleSheet(finalStyle);
}

void BaseButton::setNewFont(const AbstractFont &fontLib)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
}

/**
 * @brief 恢复字体库，防止别的组件更改字体库
 */
void BaseButton::restoreFont()
{
    IconHelper::Instance()->setNewIcon(AbstractFont(fontName));
}

/**
 * @brief 重新定义松开事件，实现误按后滑出按钮不会触发事件效果
 * @param e
 */
void BaseButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (hitButton(e->pos())){  //松开时候光标仍在按钮区域
        emit btnReleased();
        QPushButton::mouseReleaseEvent(e); //继续默认处理
    }
}
