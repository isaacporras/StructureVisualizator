#include "enlazadadoble.h"
#include "ui_enlazadadoble.h"

#include "QPaintEvent"
#include "QPainter"
#include "QDialog"
#include "QtGui"
#include "QtCore"
#include "QGraphicsScene"
#include <QTextEdit>

EnlazadaDoble::EnlazadaDoble(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnlazadaDoble)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    lista = new DobleLinkedList();
    int posx = 50;
}

EnlazadaDoble::~EnlazadaDoble()
{
    delete ui;
}

void EnlazadaDoble::on_addFinalButton_clicked()
{
    lista->ingresarDatoFinal(ui->LabelAddFinal->text());
    recorreDibuja(lista);
}

void EnlazadaDoble::recorreDibuja(DobleLinkedList *lista){

    std::cout << "El largo de la lista es:"<< lista->largo << std::endl;
    if(lista->largo == 0){
        return;
    }
    NodoDobleEnlazado *corredor = lista->primero;
    scene->clear();
    if (lista->primero == 0){
        std::cout << "No hay elementos en la lista" << std::endl;
        return;
    }
    else{
        while(corredor != 0){

            QFont font;
            font.setPixelSize(10);
            font.setBold(false);
            font.setFamily("Calibri");

            QBrush redBrush(Qt::red);
            QBrush blueBrush(Qt::blue);
            QPen blackpen(Qt::black);
            blackpen.setWidth(6);

            rectangle = scene->addRect(posx,0,100,100,blackpen,blueBrush);
            QPainterPath path;
            path.addText(posx+45, 50, font,  corredor->getDato());
            scene->addPath(path,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if(corredor != lista->ultimo){
            QPolygonF Triangle;
            Triangle.append(QPointF(posx+150.,30));
            Triangle.append(QPointF(posx+130., 50.));
            Triangle.append(QPointF(posx+130.,10.));
            Triangle.append(QPointF(posx+150.,30.));


            Triangle.append(QPointF(posx+100.,60));
            Triangle.append(QPointF(posx+120., 80.));
            Triangle.append(QPointF(posx+120.,40.));
            Triangle.append(QPointF(posx+100.,60.));

            scene->addLine(posx+130.,30.,posx+105.,30.,QPen(QBrush(Qt::black), 10));
            scene->addLine(posx+145.,60.,posx+120.,60.,QPen(QBrush(Qt::black), 10));
            scene->addPolygon(Triangle,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
            }

            posx = posx + 150;
            corredor = corredor->siguiente;
        }
        posx = 50;

    }
}

void EnlazadaDoble::on_addInicioButton_clicked()
{
    lista->ingresarDatoInicio(ui->LabeladdInicio->text());
    recorreDibuja(lista);
}

void EnlazadaDoble::on_ButtonInsertarporPos_clicked()
{
    QString pos = ui->labelTextoposicionInsertar->text();
    lista->insertarPorPosicion(pos.toInt(),ui->labeltextovalor->text());
    recorreDibuja(lista);
}

void EnlazadaDoble::on_EliminarInicioButton_clicked()
{
    lista->eliminarInicio();
    recorreDibuja(lista);
}

void EnlazadaDoble::on_EliminarFinalButton_clicked()
{
    lista->eliminarFinal();
    recorreDibuja(lista);
}

void EnlazadaDoble::on_EliminarPosButton_clicked()
{
    QString posicion = ui->labelEliminarPos->text();
    lista->eliminarPosicion(posicion.toInt());
    recorreDibuja(lista);
}

void EnlazadaDoble::on_EditarButton_clicked()
{
    std::cout << "ENTRO" << std::endl;
    lista->editar(ui->LabelEditarPos->text().toInt(),ui->LabelEditarVal->text());
    recorreDibuja(lista);
}

void EnlazadaDoble::on_buscarButton_clicked()
{

    {
        QString entero = ui->labelBuscar->text();
        NodoDobleEnlazado *corredor = lista->primero;
        scene->clear();
        if (lista->primero == 0){
            std::cout << "No hay elementos en la lista" << std::endl;
        }
        else{
            while(corredor != 0){

                QFont font;
                font.setPixelSize(10);
                font.setBold(false);
                font.setFamily("Calibri");

                QBrush redBrush(Qt::red);
                QBrush blueBrush(Qt::blue);
                QPen blackpen(Qt::black);
                blackpen.setWidth(6);
                if(corredor->getPos()!= entero.toInt()){
                rectangle = scene->addRect(posx,0,100,100,blackpen,blueBrush);
                }
                if(corredor->getPos()== entero.toInt()){
                rectangle = scene->addRect(posx,0,100,100,blackpen,redBrush);
                }
                QPainterPath path;
                path.addText(posx+45, 50, font,  corredor->getDato());
                scene->addPath(path,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

                if(corredor != lista->ultimo){
                QPolygonF Triangle;
                Triangle.append(QPointF(posx+150.,30));
                Triangle.append(QPointF(posx+130., 50.));
                Triangle.append(QPointF(posx+130.,10.));
                Triangle.append(QPointF(posx+150.,30.));


                Triangle.append(QPointF(posx+100.,60));
                Triangle.append(QPointF(posx+120., 80.));
                Triangle.append(QPointF(posx+120.,40.));
                Triangle.append(QPointF(posx+100.,60.));

                scene->addLine(posx+130.,30.,posx+105.,30.,QPen(QBrush(Qt::black), 10));
                scene->addLine(posx+145.,60.,posx+120.,60.,QPen(QBrush(Qt::black), 10));
                scene->addPolygon(Triangle,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

                }

                posx = posx + 150;
                corredor = corredor->siguiente;
            }
            posx = 50;

        }
    }
}
