#include "navbartest.h"
#include "ui_navbartest.h"

NavbarTest::NavbarTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavbarTest)
{
    ui->setupUi(this);

    //仅有标题
    ui->onlyTitle->hideLBtn();
    ui->onlyTitle->hideRBtn();
    ui->onlyTitle->setTitle("仅标题");

    //没有返回
    ui->noBack->hideLBtn();
    ui->noBack->setTitle("无返回按钮");

    //没有功能按钮
    ui->noFunc->hideRBtn();
    ui->noFunc->setTitle("无功能按钮");

    //自定义按钮和样式


    connect(ui->total, SIGNAL(lBtnSig()),
                     this, SLOT(lBtnSlot()));
    connect(ui->total, SIGNAL(rBtnSig()),
                     this, SLOT(rBtnSlot()));
}

void NavbarTest::lBtnSlot()
{
    qDebug()<<"lBtnSlot";
}

void NavbarTest::rBtnSlot()
{
    qDebug()<<"rBtnSlot";
}

NavbarTest::~NavbarTest()
{
    delete ui;
}
