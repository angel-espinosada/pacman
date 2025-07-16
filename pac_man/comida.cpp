#include "comida.h"

Comida::Comida(QGraphicsScene* scene, int blockSize)
    : scene(scene), blockSize(blockSize)
{}

void Comida::dibujar(const QVector<QVector<int>>& mapa) {
    for (int fila = 0; fila < mapa.size(); ++fila) {
        for (int col = 0; col < mapa[fila].size(); ++col) {
            if (mapa[fila][col] == 0) {
                int x = col * blockSize;
                int y = fila * blockSize;
                dibujarPunto(x, y);
            }
        }
    }
}

void Comida::dibujarPunto(int x, int y) {
    const int radio = 5; // Radio del punto (10x10)

    int centerX = x + blockSize / 2;
    int centerY = y + blockSize / 2;

    QGraphicsEllipseItem* punto = new QGraphicsEllipseItem(
        centerX - radio,
        centerY - radio,
        2 * radio,
        2 * radio
        );

    punto->setBrush(Qt::white);
    punto->setPen(Qt::NoPen);
    scene->addItem(punto);
}
