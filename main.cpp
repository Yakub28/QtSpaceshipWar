#include <QApplication>
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene= new QGraphicsScene();

    MyRect *player=new MyRect();
    player->setRect(0,0,100,100);

    //add item to the scene
    scene->addItem(player);

    //make an item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView *view=new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    view->show();
    view->setFixedSize(600,400);
    scene->setSceneRect(0,0,600,400);

    player->setPos(view->width()/2,view->height()-player->rect().height());


    return a.exec();
}
