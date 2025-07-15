#include "laberinto.h"
#include "bloque.h"
#include <QDebug>

Laberinto::Laberinto(QGraphicsScene* scene, int cellSize)
    : scene(scene), cellSize(cellSize) {}

void Laberinto::dibujarLaberinto(const QVector<QVector<int>>& mapa) {
    this->mapa = mapa;

    for (int fila = 0; fila < mapa.size(); ++fila) {
        for (int columna = 0; columna < mapa[fila].size(); ++columna) {
            int tipo = mapa[fila][columna];
            Bloque* bloque = new Bloque(tipo, columna * cellSize, fila * cellSize, cellSize);
            scene->addItem(bloque);
        }
    }
}
