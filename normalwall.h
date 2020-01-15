#ifndef NORMALWALL_H
#define NORMALWALL_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class normalWall:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    normalWall(QGraphicsItem * parent=0);
};



#endif // NORMALWALL_H
