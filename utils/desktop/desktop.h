/**
 ** @author:	   焦岳
 ** @date:	   2016.7.7
 ** @brief:      桌面组件
 */

#ifndef DESKTOP_H
#define DESKTOP_H

#include "procedurehead.h"

class Desktop : public QWidget
{
    Q_OBJECT
public:
    explicit Desktop(QWidget *parent = 0);

signals:

public slots:
    void laterShowDesk();

private slots:
    void startSlot(bool);
    void enterProSlot();
    void handleCmd(u_int);

private:
    void returnDesktop();
    QQProcedure *qqProcedure;  //qq
    Procedure *procedure;
};

#endif // DESKTOP_H
