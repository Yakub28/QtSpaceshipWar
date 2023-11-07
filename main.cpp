#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene= new QGraphicsScene();

    QGraphicsRectItem *rect=new QGraphicsRectItem();
    rect->setRect(0,0,100,100);

    //add item to the scene
    scene->addItem(rect);

    //add a view
    QGraphicsView *view=new QGraphicsView(scene);

    view->show();

    return a.exec();
}
