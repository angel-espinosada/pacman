#include "elementos.h"

#include <QDebug>

Elementos::Elementos(const QString& filePath, int tileSize,int numColumns)
    : m_tileSize(tileSize)
{
    m_spriteSheet.load(filePath);
    if (m_spriteSheet.isNull()) {
        qDebug() << "Error al cargar el sprite sheet:" << filePath;
    }
}

Elementos::~Elementos() {}

// Obtener un sprite específico por fila y columna
QPixmap Elementos::getSprite(int row, int col) const {
    QRect rect(col * m_tileSize, row * m_tileSize, m_tileSize, m_tileSize);
    return m_spriteSheet.copy(rect);
}

// Obtener todos los sprites de una fila
QList<QPixmap> Elementos::getRowSprites(int row) const {
    QList<QPixmap> sprites;

    // Calcular automáticamente el número de columnas
    int numColumns = m_spriteSheet.width() / m_tileSize;

    for (int col = 0; col < numColumns; ++col) {
        QRect rect(col * m_tileSize, row * m_tileSize, m_tileSize, m_tileSize);
        QPixmap sprite = m_spriteSheet.copy(rect);
        sprite = sprite.scaled(32, 32);
        sprites.append(sprite);
    }

    return sprites;
}
