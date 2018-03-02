#ifndef VIEWTREE_H
#define VIEWTREE_H

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

private:
    Ui::ViewTree *ui;
};

#endif // VIEWTREE_H
