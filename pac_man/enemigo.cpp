#include "enemigo.h"

#include <QDebug>

Enemigo::Enemigo(Elementos* elementos, QGraphicsScene* scene, int x, int y)
    :  QObject(), m_x(x), m_y(y), m_tileSize(35), m_columna_actual(0)
// Ajusta según el tamaño del bloque
{
    // Cargar los sprites del fantasma rojo (fila 2)
    m_sprites = elementos->getRowSprites(2,2); // Fila 2 contiene los fantasmas rojos
    if (m_sprites.isEmpty()) {
        qDebug() << "No se cargaron los sprites del enemigo.";
        return;
    }

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Enemigo::actualizarSprite);
    m_timer->start(100);

    scene->addItem(this);
    actualizarPosicion();
}

Enemigo::~Enemigo() {
}

void Enemigo::dibujar() {
    // Ya está dibujado al crear el objeto
}

void Enemigo::mover(int dx, int dy) {
    m_x += dx;
    m_y += dy;
    actualizarPosicion();
}

QRectF Enemigo::boundingRect() const
{
    return QRectF(-16, -16, 28, 30); // Asumiendo sprites de 32x32
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!m_sprites.isEmpty()) {
        painter->drawPixmap(-15, -15, m_sprites[m_columna_actual]);
    }
}

void Enemigo::actualizarSprite()
{
    m_columna_actual = (m_columna_actual + 1) % m_sprites.size();
    update();
}

void Enemigo::actualizarPosicion() {
    // Actualizar la posición del enemigo en la escena (centrada)
    int centerX = m_x * m_tileSize + m_tileSize / 2;
    int centerY = m_y * m_tileSize + m_tileSize / 2;
    setPos(centerX, centerY);}
