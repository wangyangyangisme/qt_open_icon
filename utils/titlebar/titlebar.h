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
    bool permitMax(){return isPermitMax;}
    void setPermitMax(bool val){isPermitMax = val;}

public slots:
    void show(){this->parentWidget()->show();}

signals:
    void minSignal();
    void maxSignal();
    void restoreSignal();
    void closeSignal();

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

private slots:
    void minSlot();
    void maxSlot();
    void restoreSlot();
    void closeSlot();

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
    BaseButton *restoreBtn;
    BaseButton *closeBtn;

    bool isMaxState;  //是否已经在最大化状态
    bool isPermitMax; //是否允许最大化窗口

    QRect storeRect;  //用来记录原始位置和大小

    void setMaxState();
    void setNormalState();
};

#endif // TITLEBAR_H
