#ifndef NAVBAR_H
#define NAVBAR_H

#include <QtWidgets>
#include "basebutton.h"

class Navbar : public QWidget
{
    Q_OBJECT
public:
    explicit Navbar(QPushButton *bnt);

signals:

public slots:
    void test();

private:
    QLabel *leftLab;
    QLabel *centerLab;
    QLabel *rightLab;
};

#endif // NAVBAR_H
