#ifndef NORMALLIST_H
#define NORMALLIST_H

#include "baselist.h"

class NormalList : public BaseList
{
    Q_OBJECT
public:
    NormalList(const QStringList &list);
};

#endif // NORMALLIST_H
