#ifndef BASEMESSAGEBOX_H
#define BASEMESSAGEBOX_H

#include "baselabel.h"

class BaseMessageBox : public QWidget
{
    Q_OBJECT
public:
    explicit BaseMessageBox(BaseLabel *titleLab, const QString & title,\
                            const QString & text, int w, int h, \
                            QMessageBox::StandardButtons buttons = QMessageBox::NoButton);

signals:

public slots:


private:
    QMessageBox *messageBox;
};

#endif // BASEMESSAGEBOX_H
