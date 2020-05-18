#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->timerID = startTimer(50);

    this->resize(600, 600);
    for(int i = 0; i < MAXN; i++)
    {
        sem[i] = new QSemaphore(1);
    }
    full = new QSemaphore(4);   // 最多四个人同时拿起左筷
    peoples[0] = new People(0, 265, 60, 0, this, this->sem, this->chopsticks, this->full);
    peoples[1] = new People(1, 540, 200, 72, this, this->sem, this->chopsticks, this->full);
    peoples[2] = new People(2, 480, 510, 144, this, this->sem, this->chopsticks, this->full);
    peoples[3] = new People(3, 165, 550, 216, this, this->sem, this->chopsticks, this->full);
    peoples[4] = new People(4, 40, 265, 288, this, this->sem, this->chopsticks, this->full);
    chopsticks[0] = new ChopStick(0, 390, 170, 36, this);
    chopsticks[1] = new ChopStick(1, 460, 370, 108, this);
    chopsticks[2] = new ChopStick(2, 295, 500, 180, this);
    chopsticks[3] = new ChopStick(3, 140, 365, 252, this);
    chopsticks[4] = new ChopStick(4, 190, 190, 324, this);
    for(int i = 0; i < MAXN; i++)
    {
        this->peoples[i]->start();
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter pen(this);
    QPixmap img;
    img.load(":/new/prefix1/pic/table.jpg");
    pen.drawPixmap(0, 0, 600, 600, img);
    for(int i = 0; i < MAXN; i++)
    {
        peoples[i]->draw(&pen);
        chopsticks[i]->draw(&pen);
    }
}

void Widget::timerEvent(QTimerEvent *)
{
    repaint();
}
