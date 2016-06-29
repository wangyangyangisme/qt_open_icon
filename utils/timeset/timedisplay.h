#ifndef TIMEDISPLAY_H
#define TIMEDISPLAY_H

#include "headutils.h"
#include "switchwidget.h"

class TimeDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit TimeDisplay(QWidget *parent = 0);

private slots:
    void syncTime(int);
    void timeFmtChange(int);
    void showZoneWigSlot();
    void showTimeSetWigSlot();
    void updateTime();

signals:
    void showZoneWig();
    void showTimeSetWig();

private:
    void updateDispTime(const QDateTime&);

    HeadUtils *head;
    CSwitchWidget *hourFormatBtn;
    CSwitchWidget *autoTimeBtn;
    QLabel *hourFormatLab;
    QLabel *autoTimeLab;
    QLabel *zoneLab;
    QPushButton *zoneDispBtn;
    QLabel *dateTimeLab;
    QPushButton *dateTimeDispBtn;

    bool is24Fmt;  //是否是24小时制式
    bool isAuto;  //是否自动获取时间

    QDateTime curTime;  //存储当前时间
    QTimer *updateTimer;
};

#endif // TIMEDISPLAY_H
