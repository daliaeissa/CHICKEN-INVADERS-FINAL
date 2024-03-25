#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include<QLabel>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "gameover.h"
#include "background.h"

class Game : public QGraphicsView
{
public:
    Game();
    Player* player;
    QGraphicsScene* scene;
    QTimer * time;
public slots:
    void deleteall();
    void setplay();

};

#endif // GAME_H
