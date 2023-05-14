#include "win.h"
#include <QVBoxLayout>

Win::Win()
{
    codec = QTextCodec::codecForName("utf-8");//для русификации интерфейса
    this->setWindowTitle(codec->toUnicode("Обработка событий"));//установка заголовка

    area = new Area( this );//создание объекта класса Area
    btn = new QPushButton(codec->toUnicode("Завершить"),this );//кнопка завершить

    QVBoxLayout *layout = new QVBoxLayout(this);//выравнивание по вертикали
    layout->addWidget(area);
    layout->addWidget(btn);

    //подключение сигналов к слотам
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};
