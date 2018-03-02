#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listasimple.h"
#include "enlazadadoble.h"
#include "viewcircularlist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonSimple_clicked()
{
    ListaSimple ventanaSimple;


    ventanaSimple.setModal(true);
    ventanaSimple.exec();

}

void MainWindow::on_ButtonDoble_clicked()
{
   EnlazadaDoble ventanaEnlazada;
   ventanaEnlazada.setModal(true);
   ventanaEnlazada.exec();
}

void MainWindow::on_ButtonCircular_clicked()
{
        ViewCircularList ventanacircular;
        ventanacircular.setModal(true);
        ventanacircular.exec();
}
