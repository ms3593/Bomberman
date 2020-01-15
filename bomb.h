#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "powerups.h"
#include <QTimer>

class Bomb: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb(QGraphicsItem * parent=0);
    powerups * powerup;
    QTimer *timer;
    int duzina_eksplozije = 2;
    int what_player;
public slots:
    void explode();
    void StopTimer();

};

#endif // BOMB_H
