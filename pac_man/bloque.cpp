#include "bloque.h"

Bloque::Bloque(int tipo, int x, int y, int size) {
    setRect(x, y, size, size);

    // Color según el tipo
    switch (tipo) {
    case 1:  // Pared
        setBrush(Qt::blue);
        break;
    case 0:  // Camino
        setBrush(Qt::black);
        break;
    case 2:  // Punto
        setBrush(Qt::yellow);
        break;
    default:
        setBrush(Qt::gray);
    }
}
