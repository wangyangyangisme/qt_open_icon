#include "navbartest.h"
#include "ui_navbartest.h"

NavbarTest::NavbarTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavbarTest)
{
    ui->setupUi(this);
}

NavbarTest::~NavbarTest()
{
    delete ui;
}
