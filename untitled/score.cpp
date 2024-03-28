#include "score.h"
#include "gameover.h"

Score::Score()
{
}

void Score::increaseScore(int scoreCounter)
{
    scoreCounter++;
    scoreText->setPlainText("Score: " + QString::number(scoreCounter));
}

void Score::decreaseHealth(int health)
{
    healthCounter--;
    healthText->setPlainText("Health: " + QString::number(healthCounter));

    if (health <= 0) {
        GameOver();
    }
}
