#include "toast.h"

Toast::Toast(QWidget *parent, const QString &message,\
             int w, int h, const QString &style):
    QLabel(parent)
{
    setText(message);
    //adjustSize();
    setFixedSize(w, h);
    setAlignment(Qt::AlignCenter);
    startx = (parent->width()-width()) / 2;
    starty = parent->height();
    endy = parent->height()*3/4;
    setStyleSheet(style);

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
