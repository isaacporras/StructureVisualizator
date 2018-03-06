#ifndef ENLAZADADOBLE_H
#define ENLAZADADOBLE_H

#include <iostream>
#include "QPaintEvent"
#include "QPainter"
#include "QDialog"
#include "QtGui"
#include "QtCore"
#include "QGraphicsScene"
#include <QTextEdit>
#include <QDialog>
#include "doblelinkedlist.h"

/**
  *@file enlazadadoble.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Enlazada Doble
  * @brief contiene lo referente a la ventana de la lista doblemente enlazada
  */
namespace Ui {
class EnlazadaDoble;
}
/**
 * @brief The EnlazadaDoble class clase que contiene lo referente a la ventana de la lista doblemente enlazada
 */
class EnlazadaDoble : public QDialog
{
    Q_OBJECT

public:
    explicit EnlazadaDoble(QWidget *parent = 0);
    ~EnlazadaDoble();

private slots:
    /**
     * @brief on_addFinalButton_clicked anade un nodo al final de la lista
     */
    void on_addFinalButton_clicked();
    /**
     * @brief recorreDibuja recorre y dubuja la lista
     * @param lista Es la lista que se va a dibujar
     */

    void recorreDibuja(DobleLinkedList *lista);
    /**
     * @brief on_addInicioButton_clicked anade un nodo al inicio de la lista
     */
    void on_addInicioButton_clicked();
    /**
     * @brief on_ButtonInsertarporPos_clicked inserta un nodo por una posicion dicha
     */
    void on_ButtonInsertarporPos_clicked();
    /**
     * @brief on_EliminarInicioButton_clicked elimina el nodo del inicio
     */
    void on_EliminarInicioButton_clicked();
    /**
     * @brief on_EliminarFinalButton_clicked elimina el nodo del final
     */
    void on_EliminarFinalButton_clicked();
    /**
     * @brief on_EliminarPosButton_clicked elimina del nodo por la posicion digitada
     */
    void on_EliminarPosButton_clicked();
    /**
     * @brief on_EditarButton_clicked edita el dato del nodo por la posicion digitada
     */
    void on_EditarButton_clicked();
    /**
     * @brief on_buscarButton_clicked busca un nodo y lo resalta con color rojo
     */
    void on_buscarButton_clicked();

private:
    Ui::EnlazadaDoble *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;

public:
    DobleLinkedList *lista;
    int posx;

};
#endif // ENLAZADADOBLE_H
