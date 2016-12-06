#include "normallist.h"

NormalList::NormalList(const QStringList &list)
{
    setRowCount(list.length());
    setColumnCount(2);

    for(int i=0; i<list.length(); i++){
        QTableWidgetItem *item = new QTableWidgetItem(list.at(i));
//        item->setTextAlignment(Qt::AlignCenter);
        setItem(i,0,item);
    }
}
