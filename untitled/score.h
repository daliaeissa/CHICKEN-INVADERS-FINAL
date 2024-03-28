#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QString>

class Score
{
private:
    int scoreCounter = 0;
    int healthCounter = 3;
    QGraphicsTextItem * scoreText = new QGraphicsTextItem;
    QGraphicsTextItem * healthText = new QGraphicsTextItem;
public:
    Score();
public slots:
    void increaseScore(int scoreCounter);
    void decreaseHealth(int healthcount);
};

#endif // SCORE_H
