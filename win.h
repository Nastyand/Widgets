#ifndef WIN_H
#define WIN_H

#include <QWidget>

namespace Ui {
class Win;
}

class Win : public QWidget
{
    Q_OBJECT

public:
    explicit Win(QWidget *parent = 0);
    ~Win();

private:
    Ui::Win *ui;
};

#endif // WIN_H
