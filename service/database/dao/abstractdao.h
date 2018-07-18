/**
 ** @author:	    浓咖啡
 ** @date:            2016.10.21
 ** @brief:          dao层抽象接口
 */

#ifndef ABSTRACTDAO_H
#define ABSTRACTDAO_H

#include "connectionpool.h"

class AbstractDao : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDao();
    bool getConn(QSqlDatabase &db);
    void putConn(const QSqlDatabase &db);

    bool initTable();

    bool executeSql(const QString &sql);

protected:
    bool getConn(QSqlDatabase &db);  //获取数据库连接
    virtual bool createTable() = 0;  //产生表的接口
    virtual void __viewTable() = 0;  //select * from table封装

    //下面都是子类必须提供接口，但是由于参数不定，模板方式又会增加代码复杂度
    //virtual bool insertObj(ObjType &obj) = 0;
    //virtual bool insertObjList(QList<ObjType> &objList) = 0;

    QSqlDatabase db;
};

#endif // ABSTRACTDAO_H
