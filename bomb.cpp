#include "bomb.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QPixmap>
#include <QLabel>
#include "game.h"
#include "fire.h"
#include "fixedwall.h"
#include "normalwall.h"
#include <typeinfo>
#include <QMediaPlayer>

extern Game * game;

Bomb::Bomb(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // draw the bomb
    setPixmap(QPixmap(":/images/img/bomb.png"));
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(explode()));
    timer->start(2000);
}

void Bomb::StopTimer(){
   timer->stop();
   explode();
}

void Bomb::explode(){

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/boom.mp3"));
    music->play();

    // igrac umire ako je na istom mestu gde i bomba
    setPixmap(QPixmap());
    if((scene()->itemAt(x()+25,y()+25, QTransform())))
        if((typeid(*(scene()->itemAt(x()+25,y()+25, QTransform())))) == typeid(Player)){
         Player *player= (Player*)(scene()->itemAt(x()+25,y()+25, QTransform()));
            player->dead();
        }
    Fire * fire = new Fire();
    fire->setPos(x(),y());
    scene()->addItem(fire);

    // crtanje eksplozije & kolizija
    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x()+i*50+25,y()+25, QTransform())){
            Fire * fire = new Fire();
            fire->setPos(x()+i*50,y());
            scene()->addItem(fire);
      }
      else if((typeid(*(scene()->itemAt(x()+i*50+25,y()+25, QTransform())))) == typeid(fixedWall)){
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+i*50+25,y()+25, QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x()+i*50+25,y()+25, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x()+i*50,y());
          scene()->addItem(fire);
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+i*50+25,y()+25, QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
              scene()->removeItem((scene()->itemAt(x()+i*50+25,y()+25, QTransform())));
              Fire * fire = new Fire();
              fire->setPos(x()+i*50,y());
              scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x()+i*50+25,y()+25, QTransform())));
          powerups * powerup = new powerups();
          powerup->setPos(x()+i*50,y());
          scene()->addItem(powerup);
          }
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+i*50+25,y()+25, QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x()+i*50+25,y()+25, QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()+i*50+25,y()+25, QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x()+i*50+25,y()+25, QTransform()));
          player->dead();
          Fire * fire = new Fire();
          fire->setPos(x()+i*50,y());
          scene()->addItem(fire);
          break;
      }
    }

    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x()-i*50+25,y()+25, QTransform())){
            Fire * fire = new Fire();
            fire->setPos(x()-i*50,y());
            scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x()-i*50+25,y()+25, QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x()-i*50+25,y()+25, QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x()-i*50+25,y()+25, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x()-i*50,y());
          scene()->addItem(fire);
          break;
      }
      else if((typeid(*(scene()->itemAt(x()-i*50+25,y()+25, QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
          scene()->removeItem((scene()->itemAt(x()-i*50+25,y()+25, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x()-i*50,y());
          scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x()-i*50+25,y()+25, QTransform())));
          powerups * powerup = new powerups();
          powerup->setPos(x()-i*50,y());
          scene()->addItem(powerup);
          }
          break;
      }
      else if((typeid(*(scene()->itemAt(x()-i*50+25,y()+25, QTransform())))) == typeid(this)){
           scene()->removeItem((scene()->itemAt(x()-i*50+25,y()+25, QTransform())));
      }
      else if((typeid(*(scene()->itemAt(x()-i*50+25,y()+25, QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x()-i*50+25,y()+25, QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()-i*50+25,y()+25, QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x()-i*50+25,y()+25, QTransform()));
          player->dead();
          Fire * fire = new Fire();
          fire->setPos(x()-i*50,y());
          scene()->addItem(fire);
          break;
      }
    }

    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x()+25,y()+i*50+25, QTransform())){
            Fire * fire = new Fire();
            fire->setPos(x(),y()+i*50);
            scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x()+25,y()+i*50+25, QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x()+25,y()+i*50+25, QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x()+25,y()+i*50+25, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()+i*50);
          scene()->addItem(fire);
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+25,y()+i*50+25, QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
          scene()->removeItem((scene()->itemAt(x()+25,y()+i*50+25, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()+i*50);
          scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x()+25,y()+i*50+25, QTransform())));
          powerups * powerup = new powerups();
          powerup->setPos(x(),y()+i*50);
          scene()->addItem(powerup);
          }
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+25,y()+i*50+25, QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x()+25,y()+i*50+25, QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()+25,y()+i*50+25, QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x()+25,y()+i*50+25, QTransform()));
          player->dead();
          Fire * fire = new Fire();
          fire->setPos(x(),y()+i*50);
          scene()->addItem(fire);
          break;
      }
    }

    for (int i=1; i<this->duzina_eksplozije; i++){
      if(!scene()->itemAt(x()+25,y()-i*50+25, QTransform())){
            Fire * fire = new Fire();
            fire->setPos(x(),y()-i*50);
            scene()->addItem(fire);
       }
      else if((typeid(*(scene()->itemAt(x()+25,y()-i*50+25, QTransform())))) == typeid(fixedWall)){
        break;
      }
      else if((typeid(*(scene()->itemAt(x()+25,y()-i*50+25, QTransform())))) == typeid(powerups)){
          scene()->removeItem((scene()->itemAt(x()+25,y()-i*50+25, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()-i*50);
          scene()->addItem(fire);
          break;
      }
      else if((typeid(*(scene()->itemAt(x()+25,y()-i*50+25, QTransform())))) == typeid(normalWall)){
          int number = 17;
          int randomValue = qrand() % number;
          if(!(randomValue % 3==0)){
          scene()->removeItem((scene()->itemAt(x()+25,y()-i*50+25, QTransform())));
          Fire * fire = new Fire();
          fire->setPos(x(),y()-i*50);
          scene()->addItem(fire);
          }
          else{
          scene()->removeItem((scene()->itemAt(x()+25,y()-i*50+25, QTransform())));
          powerups * powerup = new powerups();
          powerup->setPos(x(),y()-i*50);
          scene()->addItem(powerup);
          }

          break;
      }
      else if((typeid(*(scene()->itemAt(x()+25,y()-i*50+25, QTransform())))) == typeid(Bomb)){
        Bomb *bomb = (Bomb*)(scene()->itemAt(x()+25,y()-i*50+25, QTransform()));
        bomb->StopTimer();
      }
      // game over
      else if((typeid(*(scene()->itemAt(x()+25,y()-i*50+25, QTransform())))) == typeid(Player)){
          Player *player= (Player*)(scene()->itemAt(x()+25,y()-i*50+25, QTransform()));
          player->dead();
          Fire * fire = new Fire();
          fire->setPos(x(),y()-i*50);
          scene()->addItem(fire);
          break;
      }
    }

    if(this->what_player==1)
        game->player1->curr_bombs--;
    else if(this->what_player==2)
        game->player2->curr_bombs--;

    scene()->removeItem(this);
}
