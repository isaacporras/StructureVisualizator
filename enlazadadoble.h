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

namespace Ui {
class EnlazadaDoble;
}

class EnlazadaDoble : public QDialog
{
    Q_OBJECT

public:
    explicit EnlazadaDoble(QWidget *parent = 0);
    ~EnlazadaDoble();

private slots:
    void on_addFinalButton_clicked();

    void recorreDibuja(DobleLinkedList *lista);

    void on_addInicioButton_clicked();



    void on_ButtonInsertarporPos_clicked();

    void on_EliminarInicioButton_clicked();

    void on_EliminarFinalButton_clicked();

    void on_EliminarPosButton_clicked();

    void on_EditarButton_clicked();

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
