#include "basemessagebox.h"

BaseMessageBox::BaseMessageBox(BaseLabel *titleLab, const QString &title, \
                               const QString &text, int w, int h, \
                               QMessageBox::StandardButtons buttons)
{
    //标题栏部件
    QWidget *titleWig = new QWidget;
    QLabel *titleStrLab;
    titleWig->setFixedWidth(w);
    titleWig->setMaximumHeight(20);
    QHBoxLayout *titleLay = new QHBoxLayout(titleWig);
    titleLay->setMargin(0);
    titleLay->setSpacing(0);
    if(titleLab != NULL){
        titleLay->addWidget(titleLab);
    }

    titleStrLab = new QLabel(title);
    titleLay->addWidget(titleStrLab);

    //messagebox
    messageBox = new QMessageBox(QMessageBox::NoIcon, "", text, buttons);
    messageBox->setFixedWidth(w);

    //总布局
    QVBoxLayout *totalLay = new QVBoxLayout(this);
    totalLay->setMargin(0);
    totalLay->setSpacing(0);
    totalLay->addWidget(titleWig);
    totalLay->addWidget(messageBox);

    setFixedSize(w, h);
}
