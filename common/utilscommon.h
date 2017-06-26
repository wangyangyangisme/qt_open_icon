#ifndef UTILSCOMMON_H
#define UTILSCOMMON_H

#include <QObject>
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWidgets>
#else
#include <QtGui>
#endif

namespace utilscommon {

//设置阴影
void setShadow(QWidget *w, qreal blurRadius=10, qreal dx=5, qreal dy=5);

//从文件读出内容并转为QString
QString readFile(const QString &path);

//设置自启动
void autoRunWithSystem(QString AppName, QString AppPath);
}


#endif // UTILSCOMMON_H
