#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include "elementos.h"

class Enemigo : public QObject {
    Q_OBJECT
public:
    Enemigo(Elementos* elementos, QGraphicsScene* scene, int x, int y);
    ~Enemigo();

    void dibujar();
    void mover(int dx, int dy);

private:
    QGraphicsPixmapItem* m_item; // Representa al fantasma en la escena
    QList<QPixmap> m_sprites;   // Sprites del fantasma
    int m_x, m_y;               // Posición actual
    int m_tileSize;             // Tamaño del bloque del laberinto

    void actualizarPosicion();
};

#endif // ENEMIGO_H
