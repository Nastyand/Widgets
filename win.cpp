#include "win.h"
#include "ui_win.h"
#include <QBoxLayout>

Win::Win(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("utf-8");//объект для русификации интерфейса
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));//установка заголовка

    frame = new QFrame(this);//создание рамки
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel(codec->toUnicode("Введите число:"),this);//метка для ввода числа
    inputEdit = new QLineEdit("",this);//редактор ввода

    StrValidator *v=new StrValidator(inputEdit);//объект для проверки ввода
    inputEdit->setValidator(v);

    outputLabel = new QLabel(codec->toUnicode("Результат:"),this);//метка для вывода результата
    outputEdit = new QLineEdit("",this);//редактор вывода

    nextButton = new QPushButton(codec->toUnicode("Следующее"),this);//кнопка следующее
    exitButton = new QPushButton(codec->toUnicode("Выход"),this);//кнопка выход

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);//выравнивание по вертикали
    //задание порядка следования элементов
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();//добавление пружины

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);//выравнивание по горизонтали
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();// метод начальной настройки интерфейса
    //подключение сигналов к слотам
    connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)),this,SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()),this,SLOT(calc()));
}
void Win::begin()
{
    inputEdit->clear();//очистка поля ввода
    nextButton->setEnabled(false);//кнопка следующее недоступна
    nextButton->setDefault(false);//кнопка следующее не является кнопкой по умолчанию
    inputEdit->setEnabled(true);//поле ввода доступно
    outputLabel->setVisible(false);//метка для вывода результата невидна
    outputEdit->setVisible(false);//поле вывода невидно
    outputEdit->setEnabled(false);//поле вывода недоступно
    inputEdit->setFocus();//фокус на поле ввода
}
void Win::calc()
{
    bool Ok=true;//флаг
    float r,a;
    QString str=inputEdit->text();//считываем текст из поля ввода
    a=str.toDouble(&Ok);//преобразуем строку в число
    if (Ok)//преобразование выполнилось
    {
        r=a*a;//находим квадрат числа
        str.setNum(r);//преобразуем число в строку
        outputEdit->setText(str);//выводим результат
        inputEdit->setEnabled(false);//поле ввода недоступно
        outputLabel->setVisible(true);//метка результата видима
        outputEdit->setVisible(true);//поле вывода видимо
        nextButton->setDefault(true);//кнопка следующее является кнопкой по умолчанию
        nextButton->setEnabled(true);//кнопка следующее доступна
        nextButton->setFocus();//фокус на кнопке следующее
    }
    else if (!str.isEmpty())//если поле ввода не пусто
    {
        //сообщение об ошибке
        QMessageBox msgBox(QMessageBox::Information,
        codec->toUnicode("Возведение в квадрат."),
        codec->toUnicode("Введено неверное значение."),
        QMessageBox::Ok);
        msgBox.exec();
    }
}
