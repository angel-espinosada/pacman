#ifndef LABERINTO_H
#define LABERINTO_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include<QPainter>


class Pacman;



class Laberinto : public QGraphicsItem
{
public:
    Laberinto();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    uint tiles(int x, int y) const;
    bool tileBlocksEntity(int x, int y);
    bool isIntersection(int x, int y);
    bool removeDot(Pacman* pacman, int &score);

signals:
    void bigDotIsEaten();

private:
    static const int filas = 28;
    static const int columnas = 36;
    static const int tileSize = 16;

    uint m_tiles[filas][columnas];
};

#endif // LABERINTO_H
