#include "viewcircularlist.h"
#include "ui_viewcircularlist.h"

#include "QPaintEvent"
#include "QPainter"
#include "QDialog"
#include "QtGui"
#include "QtCore"
#include "QGraphicsScene"
#include <QTextEdit>
#include "circularlist.h"

ViewCircularList::ViewCircularList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCircularList)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    lista = new CircularList();
    int posx = 50;
}

ViewCircularList::~ViewCircularList()
{
    delete ui;
}

void ViewCircularList::on_addButton_clicked()
{
 lista->ingresarDatoFinal(ui->addText->text());
 recorreDibuja(lista);
}

void ViewCircularList::recorreDibuja(CircularList *lista){


    if(lista->largo == 0){
        return;
    }
    bool yasedibujoprimero = false;
    NodoListaCircular *corredor = lista->primero;
    scene->clear();
    if (lista->primero == 0){
        std::cout << "No hay elementos en la lista" << std::endl;
        return;
    }
    else{
        while(corredor != lista->primero || yasedibujoprimero == false){

            yasedibujoprimero = true;
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

            if(corredor->siguiente != lista->primero){

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
            if(corredor->siguiente == lista->primero){
                scene->addLine(posx+105.,45.,posx+130.,45.,QPen(QBrush(Qt::black), 10));
                scene->addLine(posx+130.,45.,posx+130.,-20.,QPen(QBrush(Qt::black), 10));
                scene->addLine(posx+130.,-20.,-25.,-20.,QPen(QBrush(Qt::black), 10));
                scene->addLine(-25.,45.,-25.,-20.,QPen(QBrush(Qt::black), 10));
                scene->addLine(-25.,45.,0.,45.,QPen(QBrush(Qt::black), 10));

                QPolygonF Triangle;
                Triangle.append(QPointF(20.,45));
                Triangle.append(QPointF(0., 65.));
                Triangle.append(QPointF(0.,25.));
                Triangle.append(QPointF(20.,45.));

                 scene->addPolygon(Triangle,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            }
            posx = posx + 150;
            corredor = corredor->siguiente;

       }
       posx = 50;
    }
}


void ViewCircularList::on_addInicioButton_clicked()
{
    lista->ingresarDatoInicio(ui->addInicio->text());
    recorreDibuja(lista);
}

void ViewCircularList::on_ButtonInsertarporPos_clicked()
{
    lista->insertarPorPosicion(ui->labelTextoposicionInsertar->text().toInt(), ui->labeltextovalor->text());
    recorreDibuja(lista);
}

void ViewCircularList::on_EliminarInicioButton_clicked()
{
    lista->eliminarInicio();
    recorreDibuja(lista);
}

void ViewCircularList::on_EliminarFinalButton_clicked()
{
    lista->eliminarFinal();
    recorreDibuja(lista);
}

void ViewCircularList::on_EliminarPosButton_clicked()
{
    lista->eliminarPosicion(ui->labelEliminarPos->text().toInt());
    recorreDibuja(lista);
}

void ViewCircularList::on_EditarButton_clicked()
{
    lista->editar(ui->LabelEditarPos->text().toInt(),ui->LabelEditarVal->text());
    recorreDibuja(lista);
}

void ViewCircularList::on_buscarButton_clicked()
{

    if(lista->largo == 0){
        return;
    }
    bool yasedibujoprimero = false;
    NodoListaCircular *corredor = lista->primero;
    scene->clear();
    if (lista->primero == 0){
        std::cout << "No hay elementos en la lista" << std::endl;
        return;
    }
    else{
        while(corredor != lista->primero || yasedibujoprimero == false){
            yasedibujoprimero = true;
            QFont font;
            font.setPixelSize(10);
            font.setBold(false);
            font.setFamily("Calibri");

            QBrush redBrush(Qt::red);
            QBrush blueBrush(Qt::blue);
            QPen blackpen(Qt::black);
            blackpen.setWidth(6);
            if(corredor->getPos() != ui->labelBuscar->text().toInt()){
            rectangle = scene->addRect(posx,0,100,100,blackpen,blueBrush);
            }
            if(corredor->getPos() == ui->labelBuscar->text().toInt()){
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

            if(corredor->siguiente == lista->primero){
                scene->addLine(posx+105.,45.,posx+130.,45.,QPen(QBrush(Qt::black), 10));
                scene->addLine(posx+130.,45.,posx+130.,-20.,QPen(QBrush(Qt::black), 10));
                scene->addLine(posx+130.,-20.,-25.,-20.,QPen(QBrush(Qt::black), 10));
                scene->addLine(-25.,45.,-25.,-20.,QPen(QBrush(Qt::black), 10));
                scene->addLine(-25.,45.,0.,45.,QPen(QBrush(Qt::black), 10));

                QPolygonF Triangle;
                Triangle.append(QPointF(20.,45));
                Triangle.append(QPointF(0., 65.));
                Triangle.append(QPointF(0.,25.));
                Triangle.append(QPointF(20.,45.));

                 scene->addPolygon(Triangle,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            }

            posx = posx + 150;
            corredor = corredor->siguiente;
        }

        posx = 50;

    }
}
