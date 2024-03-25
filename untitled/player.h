#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    QMediaPlayer *sound;
    QAudioOutput *audio;

public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();

};

#endif // PLAYER_H
