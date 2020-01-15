#ifndef POWERUPS_H
#define POWERUPS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class powerups:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    powerups(QGraphicsItem * parent=0);
    int redni_broj_powerupa=2;
};

#endif // POWERUPS_H

