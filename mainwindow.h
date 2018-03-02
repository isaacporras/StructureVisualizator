#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ButtonSimple_clicked();

    void on_ButtonDoble_clicked();

    void on_ButtonCircular_clicked();

    void on_ButtonArbol_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
