#include <math.h>
#include "figura.h"

void Figura::move(float Alpha,QPainter *Painter)
{
    dx=halflen*cos(Alpha);//пересчитываем сдвиги
    dy=halflen*sin(Alpha);
    draw(Painter);//рисуем фигуру
}

void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//рисуем линию
}

void MyRect::draw(QPainter *Painter)
{
    //рисуем каждую из сторон квадрата последовательно
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
