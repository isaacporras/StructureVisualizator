#ifndef VIEWCIRCULARLIST_H
#define VIEWCIRCULARLIST_H

#include <QDialog>
#include <QDialog>
#include "QGraphicsScene"
#include "circularlist.h"

namespace Ui {
class ViewCircularList;
}

class ViewCircularList : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCircularList(QWidget *parent = 0);
    ~ViewCircularList();

private slots:

    void on_addButton_clicked();
    void recorreDibuja(CircularList *lista);

    void on_addInicioButton_clicked();

    void on_ButtonInsertarporPos_clicked();

    void on_EliminarInicioButton_clicked();

    void on_EliminarFinalButton_clicked();

    void on_EliminarPosButton_clicked();

    void on_EditarButton_clicked();

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
