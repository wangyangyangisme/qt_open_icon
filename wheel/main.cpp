#include "mainwindow.h"


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    bool touch = a.arguments().contains(QLatin1String("--touch"));
    MainWindow mw(touch);
#ifdef Q_WS_S60
    mw.showMaximized();
#else
    mw.show();
#endif
#ifdef Q_WS_MAC
    mw.raise();
#endif
    QDateTime timeOfSystem = QDateTime::currentDateTime();
    QString str = timeOfSystem.toString("yyyy-MM-dd hh:mm:ss dddd");
    qDebug()<<str;
    return a.exec();
}

//#include "main.moc"
