#include "chopstick.h"
#include "const.h"
ChopStick::ChopStick(int id, int x, int y, double rotate, QWidget* father)
{
    this->x = x;
    this->y = y;
    this->rotate = rotate;
    this->status = INIT;
    this->father = father;
    this->id = id;
}

void ChopStick::draw(QPainter *)
{
    QPainter pen(this->father);
    QPixmap img;
    img.load(":/new/prefix1/pic/chopstick.png");
    pen.translate(this->x, this->y);
    pen.rotate(this->rotate);
    pen.drawPixmap(0, 0, 10, 60, img);
}

void ChopStick::initPos(int id)
{
    this->x = INIT_POS[id][0];
    this->y = INIT_POS[id][1];
    this->rotate = INIT_POS[id][2];
}

void ChopStick::setPos(int id, int dir)
{
    int index = (dir & 1) ^ 1;
    this->x = SET_POS[index][id][0];
    this->y = SET_POS[index][id][1];
    this->rotate = SET_POS[index][id][2];
}
