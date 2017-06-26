/**
 ** @file:	   toast.cpp
 ** @author:	   浓咖啡
 ** @date:	   2016.6.23
 ** @brief:      自动消失提示框
 */

#ifndef TOAST_H
#define TOAST_H

#include <QObject>
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWidgets>
#else
#include <QtGui>
#endif

#define DEFULT_TOAST_STYLE "\
QLabel{\
    color:#FFFFFF;\
    font:15px;\
    font-weight:500;\
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

private slots:
    void animationFinished();
    void delSelf();

private:
    int startx;
    int starty;
    int endy;
};

#endif // TOAST_H
