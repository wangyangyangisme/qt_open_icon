#include "toast.h"

#define DEFULT_TOAST_STYLE "\
QLabel{\
    color:#FFFFFF;\
    font:15px bold;\
    background-color:rgb(0,0,0,90);\
    padding:3px;\
    border-radius:5;\
}\
"

Toast::Toast(QWidget *parent, int w, int h, const QString &message):
    QLabel(parent)
{
    setText(message);
//    adjustSize();
    setFixedSize(200, 25);
    setAlignment(Qt::AlignCenter);
    startx = (parent->width()-width()) / 2;
    starty = parent->height();
    endy = parent->height() / 2;
    setStyleSheet(DEFULT_TOAST_STYLE);

    QGraphicsDropShadowEffect *wndShadow = new QGraphicsDropShadowEffect;
    wndShadow->setBlurRadius(9.0);
    wndShadow->setColor(QColor(0, 0, 0, 160));
    wndShadow->setOffset(5);
    setGraphicsEffect(wndShadow);
}

void Toast::toast()
{
    QPropertyAnimation *animal= new QPropertyAnimation(this,"pos");
    animal->setDuration(500);
    animal->setStartValue(QPoint(startx,starty));
    animal->setEndValue(QPoint(startx,endy));
    animal->setEasingCurve(QEasingCurve::OutCubic);
    connect(animal, SIGNAL(finished()), this, SLOT(animationFinished()));
    animal->start();
}

void Toast::animationFinished()
{
    QTimer::singleShot(400, this, SLOT(delSelf()));
}

void Toast::delSelf()
{
    delete this;
}
