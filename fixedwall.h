#ifndef FIXEDWALL_H
#define FIXEDWALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class fixedWall:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    fixedWall(QGraphicsItem * parent=0);


};

#endif // FIXEDWALL_H
