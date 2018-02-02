/**
 ** @author:	   浓咖啡
 ** @date:	   2017.9.26
 ** @brief:      仅做颜色测试使用
 */

#include "colortest.h"
#include "ui_colortest.h"

ColorTest::ColorTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorTest)
{
    ui->setupUi(this);
    ui->pushButton->setIcon(MuiFont::ICON_WEINXIN);
    ui->pushButton->resize(100, 100);
    ui->pushButton->setFontSize(50);
    ui->pushButton->setNewFont(FontawesomeWebfont());
    ui->pushButton->setIcon(FontawesomeWebfont::BATTERY_0);

//    BaseButton *btn = new BaseButton(this);
//    btn->move(100, 100);
//    btn->setFontSize(80);
//    btn->resize(100, 100);
}

ColorTest::~ColorTest()
{
    delete ui;
}
