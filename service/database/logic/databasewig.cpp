#include "databasewig.h"
#include "ui_databasewig.h"
//https://blog.csdn.net/linan_pin/article/details/70158259

DataBaseWig::DataBaseWig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBaseWig)
{
    ui->setupUi(this);
    dao.initTable();
}

DataBaseWig::~DataBaseWig()
{
    delete ui;
}

void DataBaseWig::on_addBtn_clicked()
{
    StudentData stu;
//    stu.num = ui->addStuWig->item(0,0)->text().toInt();
//    stu.name = ui->addStuWig->item(0,1)->text();
//    stu.sex = true;
//    stu.age = ui->addStuWig->item(0,3)->text().toInt();

//    dao.insert(stu);

    qDebug()<<dao.querryObj(stu, 2010414586);
    qDebug()<<stu.name;

}
