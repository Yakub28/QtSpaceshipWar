#include <QTimer>
#include <QGraphicsScene>
#include "Enemy.h"
#include <stdlib.h> //rand()->really large int
#include "Game.h"
extern Game* game;

Enemy::Enemy()
{
    int random_number=rand()%700;
    //set random position
    setPos(random_number,0);

    setRect(0,0,100,100);

    //connect
    QTimer*timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);
    if(pos().y()+rect().height()>550)
    {
        //decrease health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
