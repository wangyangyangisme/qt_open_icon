/**
 ** @author:	    浓咖啡
 ** @date:            2016.10.23
 ** @brief:          学生信息dao层演示示例
 */

#ifndef STUDENTDAOIMPL_H
#define STUDENTDAOIMPL_H

#include "studentdata.h"
#include "abstractdao.h"

class StudentDaoImpl : public AbstractDao
{
public:
    StudentDaoImpl();

    bool insert(const StudentData &obj);
    bool insertObjList(QList<StudentData> &objList);

private:
    bool createTable();
    void __viewTable();
};

#endif // STUDENTDAOIMPL_H
