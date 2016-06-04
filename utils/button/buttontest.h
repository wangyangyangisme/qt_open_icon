#ifndef BUTTONTEST_H
#define BUTTONTEST_H

#include <basebutton.h>

class ButtonTest : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonTest(QWidget *parent = 0);

signals:

private slots:

private:
    QLabel *lab;
    BaseButton *btn;
    QPushButton *lock;
    QVBoxLayout *lay;

};

#endif // BUTTONTEST_H
