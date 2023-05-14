#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QPushButton>
#include <QtGui>
#include "area.h"

class Win : public QWidget
{
protected:
    QTextCodec *codec;//для русификации интерфейса
    Area * area; // область отображения рисунка
    QPushButton * btn;//кнопка
public:
    Win();//конструктор
};

#endif // WIN_H
