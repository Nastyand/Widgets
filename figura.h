#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>
class Figura
{
protected:
    int x,y,halflen,dx,dy;
    virtual void draw(QPainter *Painter)=0;//функция рисования фигуры
public:
    Figura(int X,int Y,int Halflen): x(X),y(Y),halflen(Halflen){}//конструктор
    void move(float Alpha,QPainter *Painter);//функция поворота
    virtual ~Figura(){}
};

class MyLine:public Figura//класс, рисующий линию
{
protected:
    void draw(QPainter *Painter);//функция рисования фигуры
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор
};

class MyRect:public Figura//класс, рисующий квадрат
{
protected:
    void draw(QPainter *Painter);//функция рисования фигуры
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор
};

#endif // FIGURA_H
