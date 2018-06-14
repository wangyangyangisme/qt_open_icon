#include "titlebar.h"

#define BUTTON_HEIGHT 30        // 按钮高度;
#define BUTTON_WIDTH 30         // 按钮宽度;
#define TITLE_HEIGHT 30         // 标题栏高度;

#define BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
QPushButton:hover{\
    color: red;\
}\
"

#define LABEL_STYLE "\
QLabel{\
    color:#9ACD32;\
    border:0px;\
    background-color:rgb(255,255,255);\
}\
"

#define TOTAL_STYLE "\
QWidget{\
    background-color:#FFFFFF;\
}\
"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent)
{
    //窗体主属性
    this->setFixedHeight(TITLE_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(this->parentWidget()->width(), TITLE_HEIGHT);
    this->setStyleSheet(TOTAL_STYLE);

    //应用图标
    iconLab = new BaseLabel(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_SIGNAL);
    iconLab->setStyleSheet(LABEL_STYLE);
    iconLab->setIconSize(TITLE_HEIGHT/2);
    iconLab->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);

    //标题
    titleLab = new QLabel;
    titleLab->setText(QString("标题"));
    titleLab->setStyleSheet("font-weight:bold");

    //右侧按钮
    minBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_MINIMIZE);
    minBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    minBtn->setStyleSheet(BUTTON_STYLE);
    minBtn->setToolTip(QStringLiteral("最小化"));

    restoreBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_RESTORE);
    restoreBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    restoreBtn->setStyleSheet(BUTTON_STYLE);
    restoreBtn->setToolTip(QStringLiteral("还原"));

    maxBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_MAXIMIZE);
    maxBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    maxBtn->setStyleSheet(BUTTON_STYLE);
    maxBtn->setToolTip(QStringLiteral("最大化"));

    closeBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_CLOSE);
    closeBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    closeBtn->setStyleSheet(BUTTON_STYLE);
    closeBtn->setToolTip(QStringLiteral("关闭"));

    QHBoxLayout* totalLay = new QHBoxLayout(this);
    totalLay->addWidget(iconLab);
    totalLay->addWidget(titleLab);
    totalLay->addWidget(minBtn);
    totalLay->addWidget(restoreBtn);
    totalLay->addWidget(maxBtn);
    totalLay->addWidget(closeBtn);

    totalLay->setMargin(0);
    totalLay->setSpacing(0);

    //默认在还原状态:窗体显示之前，位置是在原点，需要继续找方法
    storeRect = this->parentWidget()->geometry();

    //信号与槽连接
    QObject::connect(minBtn, SIGNAL(clicked()),
                     this,  SLOT(minSlot()));
    QObject::connect(maxBtn, SIGNAL(clicked()),
                     this,  SLOT(maxSlot()));
    QObject::connect(restoreBtn, SIGNAL(clicked()),
                     this,  SLOT(restoreSlot()));
    QObject::connect(closeBtn, SIGNAL(clicked()),
                     this,  SLOT(closeSlot()));

    return;
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(this->parentWidget()->width(), TITLE_HEIGHT);
}


// 绘制标题栏背景色;
void TitleBar::paintEvent(QPaintEvent *event)
{
    if (this->width() != (this->parentWidget()->width()))
    {
        this->setFixedWidth(this->parentWidget()->width());
    }
    QWidget::paintEvent(event);
}

void TitleBar::setMaxState()
{
    maxBtn->setVisible(false);
    restoreBtn->setVisible(true);
    isMaxState = true;

    QRect desktopRect = QApplication::desktop()->availableGeometry();
    this->parentWidget()->setGeometry(desktopRect);
}

void TitleBar::setNormalState()
{
    maxBtn->setVisible(true);
    restoreBtn->setVisible(false);
    isMaxState = false;

    this->parentWidget()->setGeometry(storeRect);
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *e)
{
    //如果不允许最大化
    if(!isPermitMax){
        return;
    }

    //如果已经是在最大化状态
    if(isMaxState){
        setNormalState();
    }else{
        setMaxState();
    }

    return QWidget::mouseDoubleClickEvent(e);
}

void TitleBar::minSlot()
{
    emit minSignal();
}

void TitleBar::maxSlot()
{
    emit maxSignal();
    setMaxState();
}

void TitleBar::restoreSlot()
{
    emit restoreSignal();
    setNormalState();
}

void TitleBar::closeSlot()
{
    emit closeSignal();
}
