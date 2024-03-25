#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>


class Enemy: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT
public:
    Enemy();
    QMediaPlayer *sound;
    QAudioOutput *audio;

public slots:
    void move();
};

#endif // ENEMY_H
