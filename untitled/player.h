#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsTextItem>
#include <QMessageBox>

class Player: public QObject, public QGraphicsPixmapItem
{
 Q_OBJECT    
private:
    int health;
    int score;
    
public:
    Player();

    QMediaPlayer *sound;
    QAudioOutput *audio;

public:
    void keyPressEvent(QKeyEvent * event);
    
    void displayHealth() {
        // Update health display
        // Example: setPlainText(QString("Health: ") + QString::number(health));
    }
    
    void displayScore(const QString& color) {
        // Update score display with specified color
        // Example: setPlainText(QString("Score: ") + QString::number(score)).setDefaultTextColor(Qt::blue);
    }
    
    void gameOver() {
        QMessageBox* msg = new QMessageBox;
        msg->setText("Game Over! Score: " + QString::number(score));
        msg->setWindowTitle("Game Over");
        msg->exec();
        // Handle game over logic here, like resetting the game.
    }
    
public slots:
    void createEnemy();
    void decrease();
    void increase();
    
signals:
    void healthChanged(int newHealth);
    void scoreChanged(int newScore);
    void gameOver(int finalScore);
};

#endif // PLAYER_H
