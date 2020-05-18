#include "people.h"
#include <QDebug>
People::People(int id, int x, int y, int roate, QWidget* fa, QSemaphore** sem, ChopStick** chopstcks)
{
    this->x = x;
    this->y = y;
    this->rotate = roate;
    this->status = REST;
    this->father = fa;
    this->sem = sem;
    this->id = id;
    this->chopsticks = chopstcks;
}

void People::draw(QPainter *)
{
    QPainter pen(this->father);
    pen.setPen(Qt::red);
    pen.setFont(QFont("宋体", 16));
    pen.translate(this->x, this->y);
    pen.rotate(this->rotate);
    pen.drawText(0, 0, STATUS_NAME[this->status]);
}

void People::run()
{
    int timeOfThink = QRandomGenerator::global()->bounded(1000) + 1000;
    int timeOfRest = QRandomGenerator::global()->bounded(1000) + 1000;
    int timeOfEat = QRandomGenerator::global()->bounded(1000) + 1000;
    while(true)
    {

        // 休息
        this->status = REST;
        QThread::msleep(timeOfRest);
        // 思考
        this->status = THINK;
        QThread::msleep(timeOfThink);


        if(this->id == 0)
        {
            // 拿右侧筷子
            QThread::msleep(1000);
            this->sem[(this->id + 4) % MAXN]->acquire();
            this->status = FULL;
            this->chopsticks[(this->id + 4) % MAXN]->setPos(this->id, RIGHT);    // 修改坐标
            // 吃饭
            // 拿左侧筷子
            this->sem[this->id]->acquire();
            this->status = LEFT;
            this->chopsticks[this->id]->setPos(this->id, LEFT); // 修改坐标
        }
        else
        {
            // 吃饭
            // 拿左侧筷子
            this->sem[this->id]->acquire();
            this->status = LEFT;
            this->chopsticks[this->id]->setPos(this->id, LEFT); // 修改坐标
            // 拿右侧筷子
            QThread::msleep(1000);
            this->sem[(this->id + 4) % MAXN]->acquire();
            this->status = FULL;
            this->chopsticks[(this->id + 4) % MAXN]->setPos(this->id, RIGHT);    // 修改坐标
        }
        QThread::msleep(timeOfEat);
        // 释放筷子
        this->sem[this->id]->release();
        this->sem[(this->id + 4) % MAXN]->release();
        this->chopsticks[this->id]->initPos(this->id);  // 恢复左侧坐标
        this->chopsticks[(this->id + 4) % MAXN]->initPos((this->id + 4) % MAXN);    // 恢复右侧坐标


    }
}

People::~People()
{

}
