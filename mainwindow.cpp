#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listasimple.h"

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