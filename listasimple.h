#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <QDialog>
#include "QGraphicsScene"
#include "simplelinkedlist.h"

namespace Ui {
class ListaSimple;
}

class ListaSimple : public QDialog
{
    Q_OBJECT



public:
    explicit ListaSimple(QWidget *parent = 0);
    ~ListaSimple();

private slots:
    void on_RefreshButton_clicked();

    void recorreDibuja(SimpleLinkedList *lista);


    void on_addButton_clicked();

    void on_addInicioButton_clicked();

    void on_ButtonInsertarporPos_clicked();

    void on_EliminarInicioButton_clicked();

    void on_EliminarFinalButton_clicked();

    void on_EliminarPosButton_clicked();

    void on_EditarButton_clicked();

    void on_buscarButton_clicked();

private:
    Ui::ListaSimple *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *dato;

public:
    SimpleLinkedList *lista;
    int posx;
};


#endif // LISTASIMPLE_H
