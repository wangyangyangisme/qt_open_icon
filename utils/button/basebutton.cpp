#include "basebutton.h"

#define DEFULT_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    font:100px;\
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
 * @brief 按钮基类
 * @param fontLib 选择字体库
 * @param iconIndex 选择字体库图标
 * @param w 长
 * @param h 宽
 * @param style 样式
 */
BaseButton::BaseButton(const AbstractFont &fontLib, int iconIndex, \
                       int w, int h, const QString &style)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
    iconhelp::setIcon(this,iconIndex);  //正好跟button类的命名冲突
    setFixedSize(w, h);
    if(style != QString()){
        setStyleSheet(style);
    }else{
        //如果用户提供按钮大小不足以装下字体大小，那么提示一下就好
        if(std::min(w, h) < 100){
            qDebug()<<"default font is bigger than button";
        }
        setStyleSheet(DEFULT_BUTTON_STYLE);
    }

    connect(this,SIGNAL(released()),this,SLOT(releaseSlot()));
}

/**
 * @brief 恢复字体库，防止别的组件更改字体库
 */
void BaseButton::restoreFont()
{
    IconHelper::Instance()->setNewIcon(AbstractFont(fontName));
}
