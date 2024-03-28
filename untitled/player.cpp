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
#include <QMessageBox>

Player& player = Player::getScore();


Player::Player() {

    sound=new QMediaPlayer;
    audio=new QAudioOutput;
    sound->setAudioOutput(audio);
    sound->setSource(QUrl::fromLocalFile("C:/Users/dalia/Desktop/Spring 2024 semester/CS2 lab/Assignments/Assignment 2 QT MULTIMEDIA CI/Pewpewpewfinal.wav"));
    audio->setVolume(50);
    health = 3;
    score = 0;


}
void Player::decrease(int health)
{
    health--;
    healthscore->setPlainText("Health: " + QString::number(health));

    if (health <= 0) {
        gameOver();
    }
}

void Player::increase(int score)
{
    score++;
    scorenum->setPlainText("Score: " + QString::number(score));
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

Player& Player::getScore()
{
    static Player currentscore;
    return currentscore;
}


// CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

}
