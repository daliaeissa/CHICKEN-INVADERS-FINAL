#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class background: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    background();
};

#endif // BACKGROUND_H
