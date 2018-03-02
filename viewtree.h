#ifndef VIEWTREE_H
#define VIEWTREE_H
#include "binarytree.h"
#include "QGraphicsScene"
#include "treenode.h"

#include <QDialog>

namespace Ui {
class ViewTree;
}

class ViewTree : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTree(QWidget *parent = 0);
    ~ViewTree();

private slots:
    void on_InsertarButton_clicked();

    void on_EliminarButton_clicked();
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
