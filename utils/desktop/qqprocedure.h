#ifndef QQPROCEDURE_H
#define QQPROCEDURE_H

#include "procedure.h"

class QQProcedure : public Procedure
{
    Q_OBJECT
public:
    QQProcedure(const QString &_socketname, const QString &_proName, \
                const QStringList &_arguments = QStringList());

private:
    virtual BaseButton *createIcon();
};

#endif // QQPROCEDURE_H
