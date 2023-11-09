#include <QTimer>
#include <QGraphicsScene>
#include "Enemy.h"
#include <stdlib.h> //rand()->really large int
#include "Game.h"
extern Game* game;


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    int random_number=rand()%700;
    //set random position
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/images/download__1_-removebg-preview (2).png"));

    //connect
    QTimer*timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);
    if(pos().y()>500)
    {
        //decrease health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
