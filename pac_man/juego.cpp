#include "juego.h"
#include "ui_juego.h"


Juego::Juego(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    setWindowTitle("Pac-Man");
    QGraphicsScene* escenario = new QGraphicsScene(this);

    // Creamos una vista para mostrar esa escena
    QGraphicsView* visor = new QGraphicsView(escenario, this);
    visor->setFixedSize(448, 496);
    escenario->setSceneRect(0, 0,448,496);

    Laberinto *lab = new Laberinto();
    escenario->addItem(lab);

    // Mostramos la vista
    visor->show();
}

Juego::~Juego()
{
    delete ui;
}
