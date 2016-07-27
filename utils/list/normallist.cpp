#include "normallist.h"

NormalList::NormalList(const QStringList &list)
{
    setRowCount(list.length());
    setColumnCount(1);
    for(int i=0; i<list.length(); i++){
        QTableWidgetItem *item = new QTableWidgetItem(list.at(i));
        setItem(i,1,item);
    }
}
