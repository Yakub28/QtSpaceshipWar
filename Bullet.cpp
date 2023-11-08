#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"

extern Game *game;

Bullet::Bullet()
{
    setRect(0,0,10,50);

    //connect
    QTimer*timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //bullet collision with the enemy
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(auto i:colliding_items){
        if(typeid(*(i))==typeid(Enemy)){
            //increase the score
            game->score->increase();

            //remove both and delete
            scene()->removeItem(i);
            scene()->removeItem(this);
            delete i;
            delete this;
            return;
        }
    }
    // move bullet up
    setPos(x(),y()-10);
    if(pos().y()+rect().height()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
