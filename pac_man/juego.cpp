#include "juego.h"
#include "ui_juego.h"
#include "comida.h"
#include "elementos.h"
#include "enemigo.h"


Juego::Juego(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    setWindowTitle("Pac-Man");
    QGraphicsScene* escenario = new QGraphicsScene(this);

    // Creamos una vista para mostrar esa escena


    escenario->setSceneRect(0, 0,448,496);

    Laberinto *lab = new Laberinto(escenario, 35);
    ui->graphicsView->setScene(escenario);;
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFrameShape(QFrame::NoFrame);
    QVector<QVector<int>> mapa = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,0,1},
        {1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1},
        {1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
        {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1},
        {1,0,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    lab->dibujarLaberinto(mapa);
    // Creamos y dibujamos los puntos/comida
    Comida* comida = new Comida(escenario, 35);
    comida->dibujar(mapa);

    // Cargar el sprite sheet
    Elementos* elementos = new Elementos(":/sprites/elementos.png", 30,12);

    // Agregar un fantasma rojo
    Enemigo* fantasmaRojo = new Enemigo(elementos, escenario, 5, 5); // Posición inicial (5, 5)

    // Mostramos la vista
    QRectF contenido = escenario->itemsBoundingRect();
    escenario->setSceneRect(contenido);

}

Juego::~Juego()
{
    delete ui;
}
