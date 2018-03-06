#ifndef VIEWCIRCULARLIST_H
#define VIEWCIRCULARLIST_H

#include <QDialog>
#include <QDialog>
#include "QGraphicsScene"
#include "circularlist.h"
/**
  *@file viewcircularlist.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Ventana De la Lista Circular
  * @brief controla todo lo referente a la ventana De la Lista Circular
  */

namespace Ui {
class ViewCircularList;
}
/**
 * @brief The ViewCircularList class Ventana De la Lista Circular
 */
class ViewCircularList : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCircularList(QWidget *parent = 0);
    ~ViewCircularList();

private slots:
    /**
     * @brief on_addButton_clicked funcion que se encarga de realizar operaciones cuando
     * el boton de anadir es pulsado
     */

    void on_addButton_clicked();
    /**
     * @brief recorreDibuja Dibuja la lista circular en el recuadro
     * @param Lista la lista que se va a dibujar
     */
    void recorreDibuja(CircularList *lista);
    /**
     * @brief on_addInicioButton_clicked se encarga de realizar las operaciones respectivas cuando se pulsa el boton
     * de anadir al inicio
     */
    void on_addInicioButton_clicked();
    /**
     * @brief on_ButtonInsertarporPos_clicked Inserta en la lista por posicion
     */
    void on_ButtonInsertarporPos_clicked();
    /**
     * @brief on_EliminarInicioButton_clicked elimina al incio de la lista
     */
    void on_EliminarInicioButton_clicked();
    /**
     * @brief on_EliminarFinalButton_clicked elimina al final de la lista
     *
     */
    void on_EliminarFinalButton_clicked();
    /**
     * @brief on_EliminarPosButton_clicked elimina pro posicion
     */
    void on_EliminarPosButton_clicked();
    /**
     * @brief on_EditarButton_clicked edita los notos por posicion
     */
    void on_EditarButton_clicked();
    /**
     * @brief on_buscarButton_clicked busca y resalta el nodo que se busca
     */
    void on_buscarButton_clicked();

private:
    Ui::ViewCircularList *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *dato;

public:
    CircularList *lista;
    int posx;
};

#endif // VIEWCIRCULARLIST_H
