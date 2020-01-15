#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

extern int tip_powerupa;

class Player:public QObject, public QGraphicsPixmapItem{
public:
    Player(int x,QGraphicsItem * parent=0);
    void dead();
    void move(int s);
    int curr_bombs=0;
    int br;
    int broj_bombi=1;
    int duzina_vatre=2;
};

#endif // PLAYER_H
