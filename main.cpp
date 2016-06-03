#include "testwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestWidget *w = new TestWidget;
    w->show();

    return a.exec();
}
