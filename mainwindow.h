#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imoveldb.h"
#include "mydialog.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QPalette>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void testao();
    ImovelDB db;
    void criaBasico();

private slots:
    void on_cadastroCasa_clicked();
    void on_cadastroAp_clicked();

    void on_buscaImovel_clicked();

    void on_DarBaixa_clicked();

    void on_Consulta_clicked();

    void on_listar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
