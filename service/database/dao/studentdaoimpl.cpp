/**
 ** @author:	    浓咖啡
 ** @date:            2016.10.23
 ** @brief:          学生信息dao层演示示例
 */

#include "studentdaoimpl.h"

#define STUDENT_TABLE QString("STUDENT_TABLE")

#define CREATE_STUDENT_TABLE_CMD "CREATE TABLE "+STUDENT_TABLE+"(\
NUM INT PRIMARY KEY,   \
NAME TEXT NOT NULL,\
SEX BOOLEAN NOT NULL,\
AGE INT NOT NULL,\
)"

#define INSERT_STUDENT_CMD "INSERT INTO "+STUDENT_TABLE+\
    " VALUES(?, ?, ?, ?)"

/**
 * @brief 构造函数
 * @param db 数据库连接
 */
StudentDaoImpl::StudentDaoImpl() : AbstractDao()
{
}

/**
 * @brief 产生所需的表
 * @return
 */
bool StudentDaoImpl::createTable()
{
    return executeSql(CREATE_STUDENT_TABLE_CMD);
}

/**
 * @brief 插入数据
 * @param obj 学生实体信息
 * @return
 */
bool StudentDaoImpl::insert(const StudentData &obj)
{
    QList<QVariant> list;
    list.append(obj.num);
    list.append(obj.name);
    list.append(obj.sex);
    list.append(obj.age);
    return executeSql(CREATE_STUDENT_TABLE_CMD);
}

/**
 * @brief 查看表的内容
 */
void StudentDaoImpl::__viewTable()
{
    QString cmd = "SELECT * FROM " + STUDENT_TABLE;

    QSqlDatabase db;
    if(!getConn(db)){
        return;
    }

    QSqlQuery query(db);
    query.exec(cmd);

    //输出到控制台，这个格式不好控制，如果数据多，可以去文件查看
    qDebug()<<\
               "id"<<\
               "name"<<\
               "score";

    //输出到文件
    out<<\
          "id"<<\
          "name"<<\
          "score"<<qSetFieldWidth(0)<<endl;

    //输出数据
    while (query.next()) {
        //输出到控制台
        qDebug()<<\
                   query.value(0).toInt()<<\
                   query.value(1).toString()<<\
                   query.value(2).toBool()<<\
                   query.value(3).toInt();
        //输出到文件
        out<<left<<qSetFieldWidth(20)<<\
             query.value(1).toString()<<\
             query.value(2).toBool()<<\
             query.value(3).toInt()\
          <<qSetFieldWidth(0)<<endl;
    }

    putConn(db);
}
