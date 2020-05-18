#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QVector>
#include <QtMath>
#include "chopstick.h"
#include <QSemaphore>
#include "const.h"
#include "people.h"

namespace Ui {
class Widget;

}

class Widget : public QWidget
{
    Q_OBJECT

public:
    int timerID;
    People* peoples[MAXN];
    ChopStick* chopsticks[MAXN];
    QSemaphore* sem[5];
    QSemaphore* full;
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
