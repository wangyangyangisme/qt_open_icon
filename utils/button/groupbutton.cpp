/**
 ** @author:    浓咖啡
 ** @date:      2017.6.4
 ** @brief:     上下结构的组合按钮，上面是图标，下面是文字
 */

#include "groupbutton.h"

#define DEFULT_STYLE1 "\
QLabel{\
    font:50px;\
    color:rgb(44, 134, 0);\
}\
"

#define DEFULT_STYLE2 "\
QLabel{\
    font:20px;\
    color:rgb(44, 134, 0);\
}\
"
#define DEFULT_BUTTON_STYLE "\
QPushButton{\
    border:1px solid rgb(44, 134, 0);\
    border-radius:5;\
    background: QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(255, 255, 255), stop:1 rgb(199, 255, 235));\
}\
QPushButton:pressed{\
    background-color:#AAAAAA;\
}\
"

/**
 * @brief GroupButton::GroupButton
 * @param fontLib 使用的图标库
 * @param iconIndex 上方图标索引
 * @param w 总宽度
 * @param h 总高度，图标占2/3,文字占1/3
 * @param text 文字内容
 * @param style1 图标样式
 * @param style2 文字样式
 */
GroupButton::GroupButton(const AbstractFont &fontLib, int iconIndex, \
                         int w, int h, const QString &text, const QString &style1, const QString &style2)
{
    //初始化第一个label
    if(!style1.isEmpty()){
        label1 = new BaseLabel(fontLib, iconIndex, style1);
        label1->setFixedSize(w, h*2/3);
    }else{
        label1 = new BaseLabel(fontLib, iconIndex, DEFULT_STYLE1);
        label1->setFixedSize(w, h*2/3);
    }
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    //初始化第二个label
    label2 = new QLabel(text);
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    label2->setFixedSize(w, h*1/3);
    if(!style2.isEmpty()){
        label2->setStyleSheet(style2);
    }else{
        label2->setStyleSheet(DEFULT_STYLE2);
    }

    QVBoxLayout *vlay = new QVBoxLayout(this);
    vlay->setMargin(0);
    vlay->setSpacing(0);

    vlay->addWidget(label1);
    vlay->addWidget(label2);

    this->setFocusPolicy(Qt::NoFocus);
    this->setFixedSize(w, h);
    this->setStyleSheet(DEFULT_BUTTON_STYLE);
}
