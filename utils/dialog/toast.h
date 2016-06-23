#ifndef TOAST_H
#define TOAST_H

#include <QtWidgets>

#define DEFULT_TOAST_STYLE "\
QLabel{\
    color:#FFFFFF;\
    font:15px bold;\
    background-color:rgb(0,0,0,90);\
    padding:3px;\
    border-radius:5;\
}\
"

class Toast : public QLabel
{
    Q_OBJECT
public:
    explicit Toast(QWidget *parent, const QString &message = QString(),\
                   int w = 200, int h = 25, const QString &style = DEFULT_TOAST_STYLE);
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
