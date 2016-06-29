#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wheelwidget.h"
#include <QtWidgets>
#include <qmath.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(bool touch)
        : QMainWindow()
    {
        makeSlotMachine(touch);
        setCentralWidget(m_slotMachine);
    }

    void makeSlotMachine(bool touch)
    {
        if (QApplication::desktop()->width() > 1000) {
            QFont f = font();
            f.setPointSize(f.pointSize() * 2);
            setFont(f);
        }

        m_slotMachine = new QWidget(this);
        QGridLayout *grid = new QGridLayout(m_slotMachine);
        grid->setSpacing(0);

        QStringList dayList;

        QDate nextDay, preDay;
        QDate today = QDate::currentDate();
        dayList.append("今天");
        nextDay = today.addDays(1);
        preDay = today.addDays(-1);
        int curYear = today.year();
        while(curYear == nextDay.year()){
            dayList.append(nextDay.toString("MM-dd"));
            nextDay = nextDay.addDays(1);
        }

        int todayIndex=0;
        while(curYear == preDay.year()){
            dayList.prepend(preDay.toString("MM-dd"));
            preDay = preDay.addDays(-1);
            todayIndex++;
        }


        qDebug()<<dayList;

        m_wheel1 = new StringWheelWidget(touch);
        m_wheel1->setItems( dayList );
        m_wheel1->setCurrentIndex(todayIndex);
        grid->addWidget( m_wheel1, 0, 0 );
//        m_wheel1->setFixedSize(100,100);

        QStringList hours;
        hours << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10"<< "11"<< "12";
        m_wheel2 = new StringWheelWidget(touch);
        m_wheel2->setItems( hours );
        grid->addWidget( m_wheel2, 0, 1 );

        QStringList minites;
        minites << "00" <<"01" <<"02" <<"03" <<"04" <<"05" <<"06" <<"07" <<"08" <<\
                   "09" <<"10" <<"11" <<"12" <<"13" <<"14" <<"15" <<"16" <<"17" <<\
                   "18" <<"19" <<"20" <<"21" <<"22" <<"23" <<"24" <<"25" <<"26" <<\
                   "27" <<"28" <<"29" <<"30" <<"31" <<"32" <<"33" <<"34" <<"35" <<\
                   "36" <<"37" <<"38" <<"39" <<"40" <<"41" <<"42" <<"43" <<"44" <<\
                   "45" <<"46" <<"47" <<"48" <<"49" <<"50" <<"51" <<"52" <<"53" <<\
                   "54" <<"55" <<"56" <<"57" <<"58" <<"59";
        m_wheel3 = new StringWheelWidget(touch);
        m_wheel3->setItems( minites );
        grid->addWidget( m_wheel3, 0, 2 );

        QStringList ampm;
        ampm << "上午" << "下午";
        m_wheel4 = new StringWheelWidget(touch);
        m_wheel4->setItems( ampm );
        grid->addWidget( m_wheel4, 0, 3 );


        QPushButton *shakeButton = new QPushButton(tr("Shake"));
        connect(shakeButton, SIGNAL(clicked()), this, SLOT(rotateRandom()));

        grid->addWidget( shakeButton, 1, 0, 1, 3 );
    }

private slots:
    void rotateRandom()
    {
//        QStringList colors = m_wheel3->items();
//        colors << "abc" << "def" << "gjh";
//        m_wheel3->setItems(colors);
//        m_wheel1->scrollTo(m_wheel1->currentIndex() + (qrand() % 200));
//        m_wheel2->scrollTo(m_wheel2->currentIndex() + (qrand() % 200));
//        m_wheel3->scrollTo(m_wheel3->currentIndex() + (qrand() % 200));
        QStringList colors = m_wheel3->items();
//        colors << "abc" << "def" << "gjh";

        colors.prepend("def");
        colors.prepend("ghh");
        m_wheel3->setItems(colors);
//        int index = m_wheel3->currentIndex();
//        qDebug()<<"index="<<m_wheel3->currentContent();
    }

private:
    QWidget *m_slotMachine;

    StringWheelWidget *m_wheel1;
    StringWheelWidget *m_wheel2;
    StringWheelWidget *m_wheel3;
    StringWheelWidget *m_wheel4;
};

#endif // MAINWINDOW_H
