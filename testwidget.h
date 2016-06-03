#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include "iconhelper.h"

class TestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TestWidget(QWidget *parent = 0);

signals:

private slots:
    void btnStateChange();

private:
    QLabel *lab;
    QPushButton *btn;
    QPushButton *lock;
    QVBoxLayout *lay;
    bool isLock;
};

#endif // TESTWIDGET_H
