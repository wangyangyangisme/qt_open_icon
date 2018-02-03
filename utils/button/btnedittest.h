#ifndef BTNEDITTEST_H
#define BTNEDITTEST_H

#include <QWidget>

namespace Ui {
class BtnEditTest;
}

class BtnEditTest : public QWidget
{
    Q_OBJECT

public:
    explicit BtnEditTest(QWidget *parent = 0);
    ~BtnEditTest();

private:
    Ui::BtnEditTest *ui;
};

#endif // BTNEDITTEST_H
