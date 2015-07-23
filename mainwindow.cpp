#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include <QWidget>
#include <QFileDialog>
#include "janelacadastroapto.h"
#include "casa.h"
#include "apartamento.h"
#include "janelacadastrocasa.h"
#include <QDir>
#include "janelabuscaimovel.h"
#include <QDebug>
#include "darbaixa.h"
#include "listartodos.h"
#include "janelaconsultar.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << QDir::currentPath();

    if (db.loadBasico()==false){
        myDialog d("Você precisa dar um set no path");
        testao();
        criaBasico();
    }
    ui->label->setText("Imoveis Cadastrados: " + QString::number(db.getTotal()));
    qDebug() << db.getTotal();
    db.consultarTodos();
}

void MainWindow::criaBasico(){

    // Create a new file
    QString file_name = QDir::currentPath() + "/base.txt";
    QFile file(file_name);
    qDebug() << file_name ;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);

    out << db.getCaminho() << "\n";
    out << "0";

    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testao(){

    QString dir;
    if (dir == ""){
        dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    } else {
        dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      dir,
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    }
    printf("dir = %s\n",dir.toStdString().c_str());
    db.setCaminho(dir);
}

void MainWindow::on_cadastroCasa_clicked()
{

    printf("chamou casa window\n%s\n", this->db.getCaminho().toStdString().c_str());
    JanelaCadastroCasa casaWin(this->db.getCaminho(),this->db.getTotal(), this);

    casaWin.setWindowTitle("Cadastro de Casa");
    casaWin.setWindowIcon(QIcon("../ProjetoLeandro/house.png"));
    casaWin.setModal(true);
    casaWin.exec();

    if(casaWin.getSave()==false)
        return;

    Imovel * casa = casaWin.getImovel();
    qDebug() << ((Casa*)casa)->getSobrado();

    this->db.add(casa);
    qDebug() << "total = " <<this->db.getTotal();
    this->db.loadQt();
    ui->label->setText("Imoveis Cadastrados: " + QString::number(db.getTotal()));
}

void MainWindow::on_cadastroAp_clicked()
{
    printf("chamou casa window\n%s\n", this->db.getCaminho().toStdString().c_str());
     JanelaCadastroApto apWin(this->db.getCaminho(),this->db.getTotal(), this);

    apWin.setWindowTitle("Cadastro de Apartamento");
    apWin.setWindowIcon(QIcon("../ProjetoLeandro/house.png"));
    apWin.setModal(true);
    apWin.exec();
    if(apWin.getSave()==false)
        return;

    Imovel * apartamento = apWin.getImovel();
//    qDebug() << ((Apartamento*)apartamento)->getSobrado();
    qDebug() << apartamento->getType();

    this->db.add(apartamento);
    qDebug() << "total = " <<this->db.getTotal();
    this->db.loadQt();
        ui->label->setText("Imoveis Cadastrados: " + QString::number(db.getTotal()));
}

void MainWindow::on_buscaImovel_clicked()
{
    JanelaBuscaImovel t(&db,this);
    t.setWindowTitle("Buscar Imovel");
    t.exec();

}

void MainWindow::on_DarBaixa_clicked()
{
    darBaixa baixa(&db, this);
    baixa.setWindowTitle("Dar Baixa");
    baixa.exec();

}

void MainWindow::on_Consulta_clicked()
{
    JanelaConsultar consulta(&db,this);
    consulta.setWindowTitle("Consultando Pendencias");
    consulta.exec();
}

void MainWindow::on_listar_clicked()
{
    ListarTodos tds(&db, this);
    tds.setWindowTitle("Listar Todos os Imoveis Cadastrados");
    tds.exec();
}
