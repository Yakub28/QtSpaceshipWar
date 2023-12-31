#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QFile>
#include <QAudioOutput>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QImage>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/images/star_galaxy_glow_95414_800x600.jpg")));


    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(400,500);
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health=new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //play background music
    QMediaPlayer* music=new QMediaPlayer();
    auto audio=new QAudioOutput;
    music->setAudioOutput(audio);
    music->setSource(QUrl::fromLocalFile("C:/Users/User/Downloads/space-120280 - Copy.mp3"));
    audio->setVolume(50);
    music->play();

    show();
}
