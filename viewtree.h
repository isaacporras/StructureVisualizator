#ifndef VIEWTREE_H
#define VIEWTREE_H
#include "binarytree.h"
#include "QGraphicsScene"
#include "treenode.h"

#include <QDialog>
/**
  *@file viewtree.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title ViewTree
  * @brief contiene todo lo referente a la ventana del arbol binario
  */
namespace Ui {
class ViewTree;
}
/**
 * @brief The ViewTree class clase que se encarga de la ventana del Arbol binario
 */
class ViewTree : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTree(QWidget *parent = 0);
    ~ViewTree();

private slots:
    /**
     * @brief on_InsertarButton_clicked inserta un nodo en el arbol
     */
    void on_InsertarButton_clicked();
    /**
     * @brief on_EliminarButton_clicked elimina un nodo en el arbol
     */
    void on_EliminarButton_clicked();
    /**
     * @brief recorreDibuja dibuja el arbol entero en el recuadro
     * @param nodo el nodo que se va a dibujar
     * @param corx la cordenada en x donde se va a dibujar
     * @param cory la coordenada en y donde se va a dibujar
     * @param lado si el nodo es del lado derecho o izquierdo
     */
    void recorreDibuja(TreeNode *nodo, int corx, int cory, QString lado);

private:
    Ui::ViewTree *ui;
    BinaryTree *arbol;
    QGraphicsScene *scene;
    int coordenadax;
    int coordenaday;
    bool sedibujoantes;
};

#endif // VIEWTREE_H
