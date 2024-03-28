#include "bullet.h"
#include "score.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <QMediaPlayer>
#include <QSoundEffect>

Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

        // *******  Setting the bullets' size ********
    //setRect(0,0,10,50);
        QPixmap bullet("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT CHICKEN INVADERS/Session 05 Game Template (2)/Session 05 Game Template/laser.png");
        setPixmap(bullet.scaled(100, 100));

        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

    sound=new QMediaPlayer;
    audio=new QAudioOutput;
    sound->setAudioOutput(audio);
    sound->setSource(QUrl::fromLocalFile("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT MULTIMEDIA CI/chickensoundfinal.wav"));
    audio->setVolume(50);
}

void Bullet::increaseScore(int scoreCounter)
{
    scoreCounter++;
    scoreText->setPlainText("Score: " + QString::number(scoreCounter));
}

void Bullet::decreaseHealth(int health)
{
    healthCounter--;
    healthText->setPlainText("Health: " + QString::number(healthCounter));

    if (health <= 0) {
        GameOver();
    }
}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
        // *******  Getting the colliding items with the Bullet ********
    QList<QGraphicsItem*> colliding_items = collidingItems();
        for(int i=0;i<colliding_items.size();i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
            {
                sound->play();
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                increaseScore(scoreCounter);
                delete colliding_items[i];
                delete this;
                return;
            }
    }

        // *******  Moving the bullets upward ********

    setPos(x(),y()-10);
    if(pos().y()+100<0){
        scene()->removeItem(this);
        delete this;
    }

}

