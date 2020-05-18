#ifndef CHOPSTICK_H
#define CHOPSTICK_H
#include <QPainter>
#include <QWidget>
class ChopStick
{
public:
    int x, y;
    double rotate;
    QWidget* father;
    int status;
    int id;
    ChopStick(int id, int x, int y, double rotate, QWidget* father);

    void draw(QPainter*);
    void initPos(int id);
    void setPos(int id, int dir);// 筷子到左侧还是右侧
};

#endif // CHOPSTICK_H
