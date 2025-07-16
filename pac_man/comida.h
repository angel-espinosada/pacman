#ifndef COMIDA_H
#define COMIDA_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QVector>

class Comida {
public:
    Comida(QGraphicsScene* scene, int blockSize);

    void dibujar(const QVector<QVector<int>>& mapa);

private:
    QGraphicsScene* scene;
    int blockSize;

    void dibujarPunto(int x, int y);
};

#endif // COMIDA_H
