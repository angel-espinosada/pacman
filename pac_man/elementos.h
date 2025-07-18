#ifndef ELEMENTOS_H
#define ELEMENTOS_H

#include <QPixmap>
#include <QRect>
#include <QList>

class Elementos {
public:
    explicit Elementos(const QString &filePath, int tileSize,int numColumns);
    ~Elementos();

    // Obtener un sprite específico por fila y columna
    QPixmap getSprite(int row, int col) const;

    // Obtener todos los sprites de una fila
    QList<QPixmap> getRowSprites(int row,int maxColumns) const;

private:
    QPixmap m_spriteSheet; // El sprite sheet completo
    int m_tileSize;        // Tamaño de cada sprite
    int m_numColumns; // Guardamos numColumns como miembro de la clase
    int m_verticalOffset;
};

#endif // ELEMENTOS_H
