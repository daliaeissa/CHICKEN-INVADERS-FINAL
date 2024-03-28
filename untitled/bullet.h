#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "gameover.h"

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int scoreCounter = 0;
    int healthCounter = 3;
    QGraphicsTextItem * scoreText = new QGraphicsTextItem;
    QGraphicsTextItem * healthText = new QGraphicsTextItem;
public:
    Bullet();
    QMediaPlayer *sound;
    QAudioOutput *audio;


public slots:
    void move();
    void increaseScore(int scoreCounter);
    void decreaseHealth(int healthcount);

};

#endif // BULLET_H
