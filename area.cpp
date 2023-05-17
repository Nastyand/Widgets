#include "area.h"
#include <QWidget>

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));//устонавливается размер виджета
    myline=new MyLine(80,100,50);//создается объект класса MyLine
    myrect=new MyRect(220,100,50);//создается объект класса MyRect
    alpha=0;//угол поворота равен нулю
}

void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//создается объект класса QPainter
    painter.setPen(Qt::red);//задается цвет для рисования
    if(myline!=NULL && myrect!=NULL)
    {
        myline->move(alpha,&painter);//поворачиваем линию
        myrect->move(alpha*(-0.5),&painter);//поворачиваем квадрат
    }

}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}

Area::~Area()//деструкор
{
    delete myline;
    delete myrect;
}
