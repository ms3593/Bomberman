#include "game.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include <QKeyEvent>
#include <stdlib.h>
#include <QApplication>
#include <QPushButton>
#include <QMediaPlayer>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/img/back.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,700);

    // create the players

    player1 = new Player(1);
    player2 = new Player(2);
    player1->setPos(750, 550);
    player2->setPos(0,0);
    // add the players to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    // add fixed walls (walls that can't be destroyed)
    for(int i=50; i<=350; i+=100){
        for(int j=50; j<=250; j+=100){
            if(i==350 && j==250)
                continue;
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);

        }
    }
    for(int i=400; i<=750; i+=100){
        for(int j=50; j<=250; j+=100){
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);
        }
    }
    for(int i=50; i<=350; i+=100){
        for(int j=300; j<=550; j+=100){
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);
        }
    }
    for(int i=400; i<=750; i+=100){
        for(int j=300; j<=550; j+=100){
            if(i==400 && j==300)
                continue;
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);
        }
    }

    // normal walls
    for(int i=0;i<16;i++){
        for(int j=0;j<12;j++){
            if(!(scene->itemAt(i*50+25,j*50+25, QTransform()))){
            int r=rand() % 10 + 1;
                if(r!=1){
                    nwall = new normalWall();
                    nwall->setPos(i*50,j*50);
                    scene->addItem(nwall);
                }
            }
        }
    }


    // border
    for(int i=-50; i<=800; i+=50){
        for(int j=-50; j<=600; j+=650){
            wall = new fixedWall();
            wall->setPos(i,j);
            scene->addItem(wall);
        }
    }
    for(int i=-50; i<=600; i+=50){
        for(int j=-50; j<=800; j+=850){
            wall = new fixedWall();
            wall->setPos(j,i);
            scene->addItem(wall);
        }
    }


    //clean walls around the player on the begining
    if(scene->itemAt(50, 0, QTransform()))
        scene->removeItem((scene->itemAt(50,0, QTransform())));
    if(scene->itemAt(100, 0, QTransform()))
        scene->removeItem((scene->itemAt(100,0, QTransform())));
    if(scene->itemAt(0, 50, QTransform()))
        scene->removeItem((scene->itemAt(0,50, QTransform())));
    if(scene->itemAt(0, 100, QTransform()))
        scene->removeItem((scene->itemAt(0,100, QTransform())));
    if(scene->itemAt(650, 550, QTransform()))
        scene->removeItem((scene->itemAt(650,550, QTransform())));
    if(scene->itemAt(700, 550, QTransform()))
        scene->removeItem((scene->itemAt(700,550, QTransform())));
    if(scene->itemAt(750, 500, QTransform()))
        scene->removeItem((scene->itemAt(750,500, QTransform())));
    if(scene->itemAt(750, 450, QTransform()))
        scene->removeItem((scene->itemAt(750,450, QTransform())));

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();
}

void Game::keyPressEvent(QKeyEvent *event){
    if(!event->isAutoRepeat()){
        if (event->key() == Qt::Key_Left)
            this->player1->move(1);
        else if (event->key() == Qt::Key_Right)
            this->player1->move(2);
        else if (event->key() == Qt::Key_Up)
            this->player1->move(3);
        else if (event->key() == Qt::Key_Down)
            this->player1->move(4);

        else if (event->key() == Qt::Key_A)
            this->player2->move(1);
        else if (event->key() == Qt::Key_D)
            this->player2->move(2);
        else if (event->key() == Qt::Key_W)
            this->player2->move(3);
        else if (event->key() == Qt::Key_S)
            this->player2->move(4);

        else if (event->key() == Qt::Key_Enter)
            this->player1->move(5);
        else if (event->key() == Qt::Key_G)
            this->player2->move(5);
    }
}

// game is over
void Game::gameOver(QString textToDisplay){

    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setFlag(QGraphicsItem::ItemIsFocusable,false);
    }
    QFont* font = new QFont("Courier New");
    font->setItalic(true);
    font->setPixelSize(20);

    QGraphicsRectItem* panel1 = new QGraphicsRectItem(-50,-50,900,700);
    QBrush *brush= new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(Qt::black);
    panel1->setBrush(*brush);
    panel1->setOpacity(0.85);
    scene->addItem(panel1);

    QGraphicsRectItem* panel2 = new QGraphicsRectItem(100,100,600,400);
    QBrush *brush1 = new QBrush();
    brush1->setStyle(Qt::SolidPattern);
    brush1->setColor(Qt::lightGray);
    panel2->setBrush(*brush1);
    panel2->setOpacity(0.95);
    scene->addItem(panel2);

    QPushButton* kraj = new QPushButton(QString("Kraj"));
    kraj->setGeometry(350,400,100,30);
    scene->addWidget(kraj);
    connect(kraj,SIGNAL(clicked(bool)),qApp,SLOT(quit()));

    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(250,200);
    overText->setFont(*font);
    scene->addItem(overText);
}
