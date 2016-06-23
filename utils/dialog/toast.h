#ifndef TOAST_H
#define TOAST_H

#include <QtWidgets>

class Toast : public QLabel
{
    Q_OBJECT
public:
    explicit Toast(QWidget *parent, int w, int h, const QString &message);
    void toast();

signals:

private slots:
    void animationFinished();
    void delSelf();

private:
    int startx;
    int starty;
    int endy;
};

#endif // TOAST_H
