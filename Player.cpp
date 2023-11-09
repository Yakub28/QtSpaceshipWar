#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QAudioOutput>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    bulletsound = new QMediaPlayer();
    auto audioOutput=new QAudioOutput;
    bulletsound->setAudioOutput(audioOutput);
    bulletsound->setSource(QUrl::fromLocalFile("C:/Users/User/Downloads/shotgun-firing-4-6746 - Copy.mp3"));
    audioOutput->setVolume(50);

    setPixmap(QPixmap(":/images/images/download-removebg-preview (1).png"));
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        if(pos().x()>0)
            setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right){
        if(pos().x()+100<800)
            setPos(x()+10,y());
    }
    /*else if(event->key()==Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if(event->key()==Qt::Key_Down){
        setPos(x(),y()+10);
    }*/
    else if(event->key()==Qt::Key_Space){
        Bullet *bullet=new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        //play bulletsound
        if(bulletsound->playbackState() == QMediaPlayer::PlayingState)
            bulletsound->setPosition(0);
        else if(bulletsound->playbackState() == QMediaPlayer::StoppedState)
            bulletsound->play();
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy=new Enemy();
    scene()->addItem(enemy);
}


