#include "basemessagebox.h"

BaseMessageBox::BaseMessageBox(int w, int h, const QString &info)
{
    labIcon = new BaseLabel(FontawesomeWebfont(), FontawesomeWebfont::ICON_WAINING, 20, 20);
    labIcon->setObjectName("labIcon");
    labTitle = new QLabel("警告");
    labTitle->setObjectName("labTitle");

    //标题栏
    titleWig = new QWidget;
    titleWig->setObjectName("titleWig");
    titleWig->setFixedHeight(30);

    closeBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_CLOSE, 40, 30);
    closeBtn->setObjectName("closeBtn");
    QHBoxLayout *titleLay = new QHBoxLayout(titleWig);
    titleLay->addSpacing(10);
    titleLay->addWidget(labIcon);
    titleLay->addWidget(labTitle);
    titleLay->addStretch(1);
    titleLay->addWidget(closeBtn);
    titleLay->setMargin(0);
    titleLay->setSpacing(0);

    //提示信息
    labInfo = new QLabel;
    labInfo->setObjectName("labInfo");
    labInfo->setMinimumHeight(100);
    labInfo->setWordWrap(true);
    labInfo->setText(info);

    //按钮部分
    QWidget *btnWig = new QWidget;
    btnWig->setMinimumSize(200, 60);
    okBtn = new QPushButton("确定");
    okBtn->setMinimumSize(60, 30);
    cancelBtn = new QPushButton("取消");
    cancelBtn->setMinimumSize(60, 30);
    okBtn->setFocusPolicy(Qt::NoFocus);
    cancelBtn->setFocusPolicy(Qt::NoFocus);
    utilscommon::setShadow(okBtn);
    utilscommon::setShadow(cancelBtn);
    QHBoxLayout *btnLay = new QHBoxLayout(btnWig);
    btnLay->addStretch(1);
    btnLay->addWidget(cancelBtn);
    btnLay->addSpacing(10);
    btnLay->addWidget(okBtn);
    btnLay->setMargin(20);

    //主布局
    QVBoxLayout *mainLay = new QVBoxLayout;
    mainLay->setMargin(0);
    mainLay->setSpacing(0);
    mainLay->addWidget(labInfo, 1);
    mainLay->addWidget(btnWig);

    //总布局
    QVBoxLayout *totalLay = new QVBoxLayout(this);
    totalLay->addWidget(titleWig);
    totalLay->addLayout(mainLay);
    totalLay->setMargin(0);
    totalLay->setSpacing(0);

    setStyle();
    setMinimumSize(250, 150);
    resize(w, h);
    setWindowFlags(Qt::FramelessWindowHint);
}

void BaseMessageBox::setStyle()
{
    QFile file(QString(":/qss/resourse/qss/dialog/default.qss"));
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"read err";
        return;
    }

    QString qss = QLatin1String(file.readAll());
    this->setStyleSheet(qss);
    labIcon->setStyleSheet(qss);
    closeBtn->setStyleSheet(qss);
}
