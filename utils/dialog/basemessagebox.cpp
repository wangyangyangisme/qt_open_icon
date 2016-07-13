#include "basemessagebox.h"

#define LABEL_STYLE "\
QLabel{\
    color:#000000;\
    font:20px;\
    border:1px solid #AAAAAA;\
    background-color:rgb(0,0,0,0);\
}\
"

#define BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    font:20px;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

BaseMessageBox::BaseMessageBox()
{
    labIcon = new BaseLabel(FontawesomeWebfont(), FontawesomeWebfont::ICON_CHECK, 30, 30);
    labIcon->setStyleSheet(LABEL_STYLE);
    labTitle = new QLabel("labTitle");

    //标题栏
    titleWig = new QWidget;
    titleWig->setStyleSheet("background-color:#000000;");
    titleWig->setFixedSize(400, 30);
    QSpacerItem* tSpacer = new QSpacerItem(300, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    closeBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_UNLOCK, 30, 30);
    closeBtn->setStyleSheet(BUTTON_STYLE);
    QHBoxLayout *titleLay = new QHBoxLayout(titleWig);
    titleLay->addWidget(labIcon);
    titleLay->addWidget(labTitle);
    titleLay->addSpacerItem(tSpacer);
    titleLay->addWidget(closeBtn);
    titleLay->setMargin(0);
    titleLay->setSpacing(0);

    //提示信息
    labInfo = new QLabel;
    labInfo->setFixedSize(400, 120);
    labInfo->setText("abcd");

    //按钮部分
    QWidget *btnWig = new QWidget;
    btnWig->setFixedSize(400, 40);
    okBtn = new QPushButton("okBtn");
    okBtn->setFixedSize(80, 30);
    cancelBtn = new QPushButton("cancelBtn");
    cancelBtn->setFixedSize(80, 30);
    QSpacerItem* spacer = new QSpacerItem(200, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QHBoxLayout *btnLay = new QHBoxLayout(btnWig);
    btnLay->addSpacerItem(spacer);
    btnLay->addWidget(okBtn);
    btnLay->addWidget(cancelBtn);
    btnLay->setMargin(10);

    //主布局
    mainWig = new QWidget;
    mainWig->setFixedSize(400, 170);
    QVBoxLayout *mainLay = new QVBoxLayout(mainWig);
    mainLay->setMargin(10);
    mainLay->setSpacing(0);
    mainLay->addWidget(labInfo);
    mainLay->addWidget(btnWig);

    //总布局
    QVBoxLayout *totalLay = new QVBoxLayout(this);
    totalLay->addWidget(titleWig);
    totalLay->addWidget(mainWig);
    totalLay->setMargin(0);
    totalLay->setSpacing(0);

    setFixedSize(400, 200);
}
