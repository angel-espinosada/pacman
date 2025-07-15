#ifndef BLOQUE_H
#define BLOQUE_H

#include <QGraphicsRectItem>
#include <QBrush>

class Bloque : public QGraphicsRectItem {
public:
    Bloque(int tipo, int x, int y, int size);
};

#endif // BLOQUE_H
