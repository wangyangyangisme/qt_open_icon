#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QString>

class StudentData
{
public:
    StudentData();

public:
    int num;  //学号
    QString name;  //姓名
    bool sex;
    int age;
};

#endif // STUDENTDATA_H
