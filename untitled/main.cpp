
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
#include "game.h"
#include "mainwindow.h"
GameOver* go;
Game* g;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    go = new GameOver;
    g = new Game;
    g->show();

    return a.exec();
}
