#include "viewtree.h"
#include "ui_viewtree.h"
#include "binarytree.h"

ViewTree::ViewTree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTree)
{
    ui->setupUi(this);
    arbol = new BinaryTree();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    coordenadax = 30;
    coordenaday = 30;
}

ViewTree::~ViewTree()
{
    delete ui;
}

void ViewTree::on_InsertarButton_clicked()
{
    arbol->insertarNodo(ui->LabelInsertar->text().toInt());
    std::cout << "Se inserto el nodo"<< std::endl;
    arbol->recorridoPreOrder(arbol->getRoot());
    recorreDibuja(arbol->getRoot(), 30, 30);
}

void ViewTree::on_EliminarButton_clicked()
{
    arbol->eliminar(arbol->getRoot(),ui->LabelEliminar->text().toInt());
    recorreDibuja(arbol->getRoot(), 30, 30);
}


void ViewTree::recorreDibuja(TreeNode *nodo, int corx, int cory){

    if(nodo!= 0){
        int i = nodo->getDato();
        QString s = QString::number(i);
        QFont font;
        font.setPixelSize(10);
        font.setBold(false);
        font.setFamily("Calibri");
        QPainterPath path;
        path.addText(corx, cory, font, s);
        scene->addPath(path,QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
        std::cout << "Entro a la funcion"<< std::endl;
        QBrush redBrush(Qt::red);
        QBrush blueBrush(Qt::blue);
        QPen blackpen(Qt::black);
        blackpen.setWidth(6);
        scene->addEllipse(corx + 0.,cory + 0.,60.,60.,blackpen,blueBrush);
        recorreDibuja(nodo->left, corx - 120, cory+120 );
        recorreDibuja(nodo->right, corx + 120, cory + 120);
    }

}
