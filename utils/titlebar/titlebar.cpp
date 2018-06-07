#include "titlebar.h"

#define BUTTON_HEIGHT 30        // 按钮高度;
#define BUTTON_WIDTH 30         // 按钮宽度;
#define TITLE_HEIGHT 30         // 标题栏高度;

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent)
{
    //窗体主属性
    this->setFixedHeight(TITLE_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(this->parentWidget()->width(), TITLE_HEIGHT);
    this->setStyleSheet("background-color:blue");

    //应用图标
    iconLab = new BaseLabel(FontawesomeWebfont(), FontawesomeWebfont::ICON_LOCK);
    iconLab->setIconSize(15);
    iconLab->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);

    //标题
    titleLab = new QLabel;
    titleLab->setText(QString("标题"));

    //右侧按钮
    minBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_MINIMIZE);
    minBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);

    maxBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_MAXIMIZE);
    maxBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);

    closeBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_CLOSE);
    closeBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);

    QHBoxLayout* totalLay = new QHBoxLayout(this);
    totalLay->addWidget(iconLab);
    totalLay->addWidget(titleLab);
    totalLay->addWidget(minBtn);
    totalLay->addWidget(maxBtn);
    totalLay->addWidget(closeBtn);

    totalLay->setMargin(0);
    totalLay->setSpacing(0);
    return;

    m_pIcon = new QLabel;
    m_pTitleContent = new QLabel;

    m_pButtonMin = new QPushButton;
    m_pButtonRestore = new QPushButton;
    m_pButtonMax = new QPushButton;
    m_pButtonClose = new QPushButton;

    m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    m_pTitleContent->setObjectName("TitleContent");
    m_pButtonMin->setObjectName("ButtonMin");
    m_pButtonRestore->setObjectName("ButtonRestore");
    m_pButtonMax->setObjectName("ButtonMax");
    m_pButtonClose->setObjectName("ButtonClose");

    m_pButtonMin->setToolTip(QStringLiteral("最小化"));
    m_pButtonRestore->setToolTip(QStringLiteral("还原"));
    m_pButtonMax->setToolTip(QStringLiteral("最大化"));
    m_pButtonClose->setToolTip(QStringLiteral("关闭"));

    QHBoxLayout* mylayout = new QHBoxLayout(this);
    mylayout->addWidget(m_pIcon);
    mylayout->addWidget(m_pTitleContent);

    mylayout->addWidget(m_pButtonMin);
    mylayout->addWidget(m_pButtonRestore);
    mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_pButtonClose);

    mylayout->setContentsMargins(5, 0, 0, 0);
    mylayout->setSpacing(0);

    m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_pTitleContent->setText("test");
    this->setFixedHeight(TITLE_HEIGHT);
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
