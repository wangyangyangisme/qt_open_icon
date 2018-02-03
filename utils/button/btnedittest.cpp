#include "btnedittest.h"
#include "ui_btnedittest.h"

#define BUTTON_STYLE "\
QPushButton{\
    color:red;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

BtnEditTest::BtnEditTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BtnEditTest)
{
    ui->setupUi(this);
    ui->baseBtn->setNewFont(FontawesomeWebfont());
    ui->baseBtn->setIcon(FontawesomeWebfont::ICON_CHECK);
    ui->baseBtn->setStyleSheet(BUTTON_STYLE);
    ui->baseBtn->setFontSize(45);
}

BtnEditTest::~BtnEditTest()
{
    delete ui;
}
