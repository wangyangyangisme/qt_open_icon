#ifndef HEADUTILS_H
#define HEADUTILS_H

#include "baselabel.h"
#include "basebutton.h"

class HeadUtils : public QWidget
{
    Q_OBJECT
public:
    explicit HeadUtils(const QString &title, QWidget *parent = 0);

signals:
    void backSignal();

public slots:

private:
    void paintEvent(QPaintEvent *);
    QHBoxLayout *hBoxLayout;
    BaseButton *back;
    BaseLabel *picLab;
    QLabel *titleLab;
};

#endif // HEADUTILS_H
