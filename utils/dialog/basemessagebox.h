#ifndef BASEMESSAGEBOX_H
#define BASEMESSAGEBOX_H

#include "baselabel.h"
#include "basebutton.h"

class BaseMessageBox : public QWidget
{
    Q_OBJECT
public:
    explicit BaseMessageBox();

private:
    QWidget *titleWig;
    BaseLabel *labIcon;
    QLabel *labTitle;
    BaseButton *closeBtn;

    QWidget *mainWig;
    QGroupBox *groupBox;
    QLabel *labInfo;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // BASEMESSAGEBOX_H
