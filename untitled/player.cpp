#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QList>
#include<QPixmap>
#include <QGraphicsPixmapItem>
#include <QSoundEffect>


Player::Player() {

    sound=new QMediaPlayer;
    audio=new QAudioOutput;
    sound->setAudioOutput(audio);
    sound->setSource(QUrl::fromLocalFile("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT MULTIMEDIA CI/Pewpewpewfinal.wav"));
    audio->setVolume(50);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        sound->play();

    }


}


// CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

}
