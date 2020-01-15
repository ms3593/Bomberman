#include "normalwall.h"
#include <QGraphicsScene>

normalWall::normalWall(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/img/normalwall.jpg"));
}
