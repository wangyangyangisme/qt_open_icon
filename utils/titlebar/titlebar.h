#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    enum ButtonType
    {
        MIN_BUTTON = 0,         // 最小化和关闭按钮;
        MIN_MAX_BUTTON ,        // 最小化、最大化和关闭按钮;
        ONLY_CLOSE_BUTTON       // 只有关闭按钮;
    };
    explicit TitleBar(QWidget *parent);

signals:

public slots:

};

#endif // TITLEBAR_H
