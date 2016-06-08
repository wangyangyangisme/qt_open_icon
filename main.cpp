#include "buttontest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ButtonTest *w = new ButtonTest;
    w->show();

    return a.exec();
}
