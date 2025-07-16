#ifndef JUEGO_H
#define JUEGO_H

#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include "laberinto.h"
#include "comida.h"
#include "elementos.h"
#include "enemigo.h"

namespace Ui {
class Juego;
}

class Juego : public QWidget
{
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = nullptr);
    ~Juego();

private:
    Ui::Juego *ui;
    QGraphicsScene *escenario;
    QGraphicsView *visor;
};

#endif // JUEGO_H
