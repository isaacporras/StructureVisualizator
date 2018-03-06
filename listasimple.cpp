#include "listasimple.h"
#include "ui_listasimple.h"
#include "QPaintEvent"
#include "QPainter"
#include "QDialog"
#include "QtGui"
#include "QtCore"
#include "QGraphicsScene"
#include <QTextEdit>
#include "simplelinkedlist.h"

ListaSimple::ListaSimple(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaSimple)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    lista = new SimpleLinkedList();
    int posx = 50;





}

ListaSimple::~ListaSimple()
{
    delete ui;
}







void ListaSimple::on_addButton_clicked()
{
 posx = 50;
 lista->ingresarDatoFinal(ui->addText->text());
 recorreDibuja(lista);

}
void ListaSimple::recorreDibuja(SimpleLinkedList *lista){

    NodoSimple *corredor = lista->primero;
    scene->clear();
    posx = 50;
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

            rectangle = scene->addRect(posx,0,100,100,blackpen,blueBrush);
            QPainterPath path;
            path.addText(posx+45, 50, font,  corredor->getDato());
            scene->addPath(path,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if(corredor != lista->ultimo){
            QPolygonF Triangle;
            Triangle.append(QPointF(posx+150.,45));
            Triangle.append(QPointF(posx+130., 65.));
            Triangle.append(QPointF(posx+130.,25.));
            Triangle.append(QPointF(posx+150.,45.));

            scene->addLine(posx+130.,45.,posx+105.,45.,QPen(QBrush(Qt::black), 10));
            scene->addPolygon(Triangle,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
            }

            posx = posx + 150;
            corredor = corredor->siguiente;
        }
        posx = 50;

    }
}

void ListaSimple::on_addInicioButton_clicked()
{
    lista->ingresarDatoInicio(ui->addInicio->text());
    recorreDibuja(lista);
}

void ListaSimple::on_ButtonInsertarporPos_clicked()
{

    QString entero = ui->labelTextoposicionInsertar->text();


    lista->insertarPorPosicion(entero.toInt(),ui->labeltextovalor->text());
    recorreDibuja(lista);
}

void ListaSimple::on_EliminarInicioButton_clicked()
{
    lista->eliminarInicio();
    recorreDibuja(lista);
}

void ListaSimple::on_EliminarFinalButton_clicked()
{
    lista->eliminarFinal();
    recorreDibuja(lista);
    posx = posx - 150;
}

void ListaSimple::on_EliminarPosButton_clicked()
{
    QString entero = ui->labelEliminarPos->text();
    lista->eliminarPosicion(entero.toInt());
    recorreDibuja(lista);
}

void ListaSimple::on_EditarButton_clicked()
{
    QString entero = ui->LabelEditarPos->text();
    lista->editar(entero.toInt(),ui->LabelEditarVal->text());
    recorreDibuja(lista);
}

void ListaSimple::on_buscarButton_clicked()
{
    QString entero = ui->labelBuscar->text();
    NodoSimple *corredor = lista->primero;
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
            if(entero.toInt() == corredor->getPos() ){
                rectangle = scene->addRect(posx,0,100,100,blackpen,redBrush);
            }

            QPainterPath path;
            path.addText(posx+45, 50, font,  corredor->getDato());
            scene->addPath(path,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));

            if(corredor != lista->ultimo){
            QPolygonF Triangle;
            Triangle.append(QPointF(posx+150.,45));
            Triangle.append(QPointF(posx+130., 65.));
            Triangle.append(QPointF(posx+130.,25.));
            Triangle.append(QPointF(posx+150.,45.));

            scene->addLine(posx+130.,45.,posx+105.,45.,QPen(QBrush(Qt::black), 10));
            scene->addPolygon(Triangle,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
            }

            posx = posx + 150;
            corredor = corredor->siguiente;
        }
        posx = 50;

    }

}

