#ifndef QQPROCEDURE_H
#define QQPROCEDURE_H

#include "procedure.h"

class QQProcedure : public Procedure
{
    Q_OBJECT
public:
    QQProcedure();

private:
    virtual BaseButton *createIcon();
};

#endif // QQPROCEDURE_H
