#include "win.h"
#include "ui_win.h"

#include <QPushButton>
#include <QBoxLayout>


Win::Win(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("utf-8");//объект для русификации интерфейса
    this->setWindowTitle(codec->toUnicode("Счетчик"));//установка заголовка

    label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);//метка счтечика 1
    label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);//метка счетчика 5

    edit1 = new Counter("0",this);//счетчик по 1
    edit2 = new Counter("0",this);//счетчик по 5

    calcbutton=new QPushButton("+1",this);//кнопка +1
    exitbutton=new QPushButton(codec->toUnicode("Выход"),this);//кнопка выход

    QHBoxLayout *layout1 = new QHBoxLayout();//выравнивание по горизонтали
    layout1->addWidget(label1);
    layout1->addWidget(label2);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);

    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);

    QVBoxLayout *layout4 = new QVBoxLayout(this);//выравнивание по вертикали
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    //подключение сигналов к слотам
    connect(calcbutton,SIGNAL(clicked(bool)),edit1,SLOT(add_one()));
    connect(edit1,SIGNAL(tick_signal()),edit2,SLOT(add_one()));
    connect(exitbutton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

