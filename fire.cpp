#include "fire.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QList>
#include "game.h"
#include "bomb.h"


extern Game * game;

Fire::Fire(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/img/fire.jpg"));


    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(extinguish()));
    timer->start(500);
}

void Fire::extinguish(){
    scene()->removeItem(this);
}
