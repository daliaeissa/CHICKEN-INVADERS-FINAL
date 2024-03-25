#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    QMediaPlayer *sound;
    QAudioOutput *audio;

public slots:
    void move();
};

#endif // BULLET_H
