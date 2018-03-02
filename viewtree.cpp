#include "viewtree.h"
#include "ui_viewtree.h"

ViewTree::ViewTree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTree)
{
    ui->setupUi(this);
}

ViewTree::~ViewTree()
{
    delete ui;
}
