#ifndef TITLEBAR_H
#define TITLEBAR_H

#include "basebutton.h"
#include "baselabel.h"

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

    //这里必须传递父部件指针
    explicit TitleBar(QWidget *parent);

signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QLabel* m_pIcon;                    // 标题栏图标;
    QLabel* m_pTitleContent;            // 标题栏内容;
    QPushButton* m_pButtonMin;          // 最小化按钮;
    QPushButton* m_pButtonRestore;      // 最大化还原按钮;
    QPushButton* m_pButtonMax;          // 最大化按钮;
    QPushButton* m_pButtonClose;        // 关闭按钮;

    BaseLabel *iconLab;
    QLabel *titleLab;
    BaseButton *minBtn;
    BaseButton *maxBtn;
    BaseButton *closeBtn;
};

#endif // TITLEBAR_H
