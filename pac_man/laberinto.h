#ifndef LABERINTO_H
#define LABERINTO_H

#include <QGraphicsScene>
#include <QVector>
#include <bloque.h>

class Laberinto {
public:
    Laberinto(QGraphicsScene* scene, int cellSize);
    void dibujarLaberinto(const QVector<QVector<int>>& mapa);

private:
    QGraphicsScene* scene;
    int cellSize;
    QVector<QVector<int>> mapa;
};

#endif // LABERINTO_H
