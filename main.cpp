#include <QApplication>
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene= new QGraphicsScene();

    MyRect *rect=new MyRect();
    rect->setRect(0,0,100,100);

    //add item to the scene
    scene->addItem(rect);

    //make an item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add a view
    QGraphicsView *view=new QGraphicsView(scene);

    view->show();

    return a.exec();
}
