#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include "elementos.h"
#include <QTimer>
#include <QPainter>

class Enemigo : public QObject,public QGraphicsItem  {
    Q_OBJECT
public:
    Enemigo(Elementos* elementos, QGraphicsScene* scene, int x, int y);
    ~Enemigo();

    void dibujar();
    void mover(int dx, int dy);
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private slots:
    void actualizarSprite();

private:
         // Representa al fantasma en la escena
    QList<QPixmap> m_sprites;   // Sprites del fantasma
    int m_x, m_y;               // Posición actual
    int m_tileSize;
    int m_columna_actual;
    QTimer* m_timer;
        // Tamaño del bloque del laberinto

    void actualizarPosicion();
};

#endif // ENEMIGO_H
