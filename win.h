#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Counter:public QLineEdit//класс counter
{
Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):
    QLineEdit(contents,parent){}//конструктор
signals:
    void tick_signal();// сигнал
public slots:
    void add_one()//слот
    {
        QString str=text();//получение текста
        int r=str.toInt();//преобразование строки в целое число
        if (r!=0 && r%5 ==0) emit tick_signal();//если число не равно 0 и кратно 5 имитируем сигнал
        r++;
        str.setNum(r);//преобразование числа в строку
        setText(str);//установка нового значения
    }
};

class Win: public QWidget//класс окна
{
Q_OBJECT
protected:
    QTextCodec *codec;//для русификации интерфейса
    QLabel *label1,*label2;// метки
    Counter *edit1,*edit2;//объекты класса счетчик
    QPushButton *calcbutton;//кнопка +1
    QPushButton *exitbutton;//кнопка выход
public:
    Win(QWidget *parent = 0);//конструктор
};
#endif // WIN_H
