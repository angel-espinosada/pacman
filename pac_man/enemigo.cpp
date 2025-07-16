#include "enemigo.h"

#include <QDebug>

Enemigo::Enemigo(Elementos* elementos, QGraphicsScene* scene, int x, int y)
    : QObject(), m_item(nullptr), m_x(x), m_y(y), m_tileSize(35) // Ajusta según el tamaño del bloque
{
    // Cargar los sprites del fantasma rojo (fila 2)
    m_sprites = elementos->getRowSprites(2); // Fila 2 contiene los fantasmas rojos
    if (m_sprites.isEmpty()) {
        qDebug() << "No se cargaron los sprites del enemigo.";
        return;
    }
    // Tamaño del sprite del fantasma (ajustar según tu sprite sheet)
    int spriteWidth = 32;
    int spriteHeight = 32;
    // Calcular posición centrada dentro del bloque
    int centerX = x * m_tileSize + m_tileSize / 2;
    int centerY = y * m_tileSize + m_tileSize / 2;
    // Ajustar posición para centrar el sprite
    int posX = centerX - spriteWidth / 2;
    int posY = centerY - spriteHeight / 2;

    // Crear el item gráfico para el fantasma
    m_item = new QGraphicsPixmapItem(m_sprites[0]); // Primer sprite por defecto
    m_item->setPos(centerX, centerY);
    scene->addItem(m_item);
}

Enemigo::~Enemigo() {
    delete m_item;
}

void Enemigo::dibujar() {
    // Ya está dibujado al crear el objeto
}

void Enemigo::mover(int dx, int dy) {
    m_x += dx;
    m_y += dy;
    actualizarPosicion();
}

void Enemigo::actualizarPosicion() {
    // Actualizar la posición del enemigo en la escena (centrada)
    int centerX = m_x * m_tileSize + m_tileSize / 2;
    int centerY = m_y * m_tileSize + m_tileSize / 2;

    if (m_item) {
        m_item->setPos(centerX, centerY);
    }
}
