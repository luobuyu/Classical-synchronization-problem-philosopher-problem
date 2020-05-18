#ifndef PEOPLE_H
#define PEOPLE_H
#include <QThread>
#include <QPainter>
#include "const.h"
#include "chopstick.h"
#include <QSemaphore>
#include <QRandomGenerator>
#include <QWidget>

class People : public QThread
{
    Q_OBJECT
public:
    int x, y;
    int id;
    int status;
    double rotate;
    QWidget *father;
    ChopStick** chopsticks;
    QSemaphore** sem;
    void run();
    People(int id, int x, int y, int rotate, QWidget* fa, QSemaphore** sem, ChopStick** chopsticks);
    void draw(QPainter *);
    ~People();
};

#endif // PEOPLE_H
