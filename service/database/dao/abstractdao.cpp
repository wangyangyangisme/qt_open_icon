/**
 ** @author:	     浓咖啡
 ** @date:           2016.10.21
 ** @brief:          dao层抽象接口
 ** @update:         增加多表处理，重写设计数据库操作框架 2018.7.18 浓咖啡
 */

#include "abstractdao.h"


AbstractDao::AbstractDao()
{
}

bool AbstractDao::getConn(QSqlDatabase &db)
{
    db = ConnectionPool::openConnection();
    if(db.isValid()){
        return true;
    }else{
        qDebug()<<"getConn failed";
        return false;  //达到最大连接数
    }
}

void AbstractDao::putConn(const QSqlDatabase &db)
{
    ConnectionPool::closeConnection(db);
}

bool AbstractDao::initTable()
{
    if(createTable()){
        return true;
    }else{
        return false;
    }
}

bool AbstractDao::executeSql(const QString &sql,const QList<QVariant> &list)
{
    QSqlDatabase db;
    if(!getConn(db)){
        return false;
    }

    QSqlQuery query(db);
    query.prepare(sql);

    if(!list.isEmpty()){
        for(int i=0; i<list.length(); i++){
            query.bindValue(i, list.at(i));
        }
    }

    if(!query.exec(cmd)){
        qDebug()<<query.lastError();
        return false;
    }else{
        return true;
    }
}

/**
 * @brief 调试使用，显示表的所有信息:select * from table
 * @param tableName
 */
void AbstractDao::viewTable(const QString &tableName)
{
    QFile file(tableName + ".log");
    file.open(QIODevice::Text | QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<left<<qSetFieldWidth(20);

    qDebug()<<endl;
    qDebug()<<"SELECT * FROM "<<tableName;
    __viewTable();
    qDebug()<<endl;

    file.close();
}

