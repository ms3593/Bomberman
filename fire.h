#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Fire: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Fire(QGraphicsItem * parent=0);
public slots:
    void extinguish();
};

#endif // FIRE_H
