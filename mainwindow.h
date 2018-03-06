#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/**
  *@file mainwindow.h
  * @version 1.0
  * @date 5/3/18
  * @author Oscar Isaac Porras Perez
  * @title Binary Tree
  * @brief controla todo lo referente a lo que se encuentra en la ventana principal
  */
namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class Esta clase controla todo lo referente a lo que se encuentra en la ventana inicial
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * @brief on_ButtonSimple_clicked Este boton abre la ventana para interactuar con la lista simple
     */
    void on_ButtonSimple_clicked();
    /**
     * @brief on_ButtonDoble_clicked Este boton abre la ventana para interactuar con la lista doble
     */
    void on_ButtonDoble_clicked();
    /**
     * @brief on_ButtonCircular_clicked Este boton abre la ventana para interactuar con la lista circular
     */
    void on_ButtonCircular_clicked();
    /**
     * @brief on_ButtonArbol_clicked Este boton abre la ventana para interactuar con el arbol binario
     */
    void on_ButtonArbol_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
