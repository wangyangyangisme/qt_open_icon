#ifndef DATABASEWIG_H
#define DATABASEWIG_H

#include <QtWidgets>
#include "studentdaoimpl.h"

namespace Ui {
class DataBaseWig;
}

class DataBaseWig : public QWidget
{
    Q_OBJECT

public:
    explicit DataBaseWig(QWidget *parent = 0);
    ~DataBaseWig();

private slots:
    void on_addBtn_clicked();

private:
    Ui::DataBaseWig *ui;
    StudentDaoImpl dao;
};

#endif // DATABASEWIG_H
