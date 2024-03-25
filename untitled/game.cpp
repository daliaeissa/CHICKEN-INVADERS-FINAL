#include "game.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>

Game::Game() {

    // *******  Create the View ********
    setFixedSize(800, 600);

    // *******  Create the Player ********
    player = new Player();
    QPixmap spaceship("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT CHICKEN INVADERS/Session 05 Game Template (2)/Session 05 Game Template/spaceship2.png");
    player->setPixmap(spaceship.scaled(100,100));

    // ******* Create the Scene ********
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 800, 600);

    //background = new background();
    QGraphicsPixmapItem *background = new class background();
    QPixmap space("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT CHICKEN INVADERS/Session 05 Game Template (2)/Session 05 Game Template/spacepic.jpg");
    background->setPixmap(space);

    // QPixmap space("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT CHICKEN INVADERS/Session 05 Game Template (2)/Session 05 Game Template/spacefinal.jpg");
    // QGraphicsPixmapItem *background = new QGraphicsPixmapItem;
    // background->setPixmap(space.scaled(1000,1000));
    background->setPos(0, 0); // Set the position of the background image
    // background->setZValue(-1);
    scene->addItem(background);

    scene->addItem(player);
    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(width()/2-100, height()-100);

    // *******   Assign scene to the view   ***************
    setScene(scene);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    // *******  Create the Enemies automatically ********
    time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

}

void Game::deleteall() {
    scene->clear();
}

void Game::setplay() {
    player = new Player();
    QPixmap spaceship("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT CHICKEN INVADERS/Session 05 Game Template (2)/Session 05 Game Template/spaceship2.png");
    player->setPixmap(spaceship.scaled(100,100));
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(width()/2-100, height()-100);
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

}