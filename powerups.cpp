#include "powerups.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

powerups::powerups(QGraphicsItem *parent)
{

    int number = 17;
    int randomValue = qrand() % number;

    if(!(randomValue % 3==0)){
    setPixmap(QPixmap(":/images/img/firepowerup.jpg"));
    this->redni_broj_powerupa=1;
    }
    else {
    setPixmap(QPixmap(":/images/img/bombpowerup.png"));
    this->redni_broj_powerupa=2;
    }
}
