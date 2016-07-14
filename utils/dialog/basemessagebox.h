#ifndef BASEMESSAGEBOX_H
#define BASEMESSAGEBOX_H

#include "baselabel.h"
#include "basebutton.h"
#include "utilscommon.h"

class BaseMessageBox : public QWidget
{
    Q_OBJECT
public:
    explicit BaseMessageBox(int w, int h, const QString &info);

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

    void setStyle();
};

#endif // BASEMESSAGEBOX_H
