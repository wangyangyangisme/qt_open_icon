#include "headutils.h"

#define BACK_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    font:30px;\
    border:0px solid #AAAAAA;\
    border-radius:15;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#436EEE;\
    font:32px;\
}\
"

#define TITLE_LABEL_STYLE "\
QLabel{\
    color:#000000;\
    font:20px;\
}\
"

HeadUtils::HeadUtils(const QString &title, QWidget *parent) :
    QWidget(parent)
{
    //整体部件
    setFixedSize(355, 35);

    //返回按钮
    back = new BaseButton(TimeFont(), TimeFont::ICON_BACK, 30, 30, BACK_BUTTON_STYLE);
    back->setParent(this);
    back->move(5, 0);
    back->setFocusPolicy(Qt::NoFocus);

    //中间标题
    picLab = new BaseLabel(TimeFont(), TimeFont::ICON_DATE, 20, 20, TITLE_LABEL_STYLE);
    titleLab = new QLabel(title);
    picLab->adjustSize();
    titleLab->adjustSize();
    QWidget *titleWig = new QWidget(this);
    QHBoxLayout *titleLay = new QHBoxLayout(titleWig);
    titleLay->addWidget(picLab);
    titleLay->addWidget(titleLab);

    int labWidth = picLab->width() + titleLab->width();
    qDebug()<<"parent="<<width();
    qDebug()<<"lab="<<labWidth;
    titleWig->move((width()-labWidth)/2, 0);

    setStyleSheet("background-color:#FFFFFF;");

//    //最下方线条
//    QPainter painter(this);
//    painter.setPen(QPen(QBrush("#FF5500"), 3, Qt::SolidLine, Qt::FlatCap));
//    painter.drawLine(QPoint(3, height()-5), QPoint(width()-3, height()-5));  //画第一个下面线条
}
