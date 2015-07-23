#ifndef JANELABUSCAIMOVEL_H
#define JANELABUSCAIMOVEL_H

#include <QDialog>
#include "imoveldb.h"
#include <QLabel>

namespace Ui {
class JanelaBuscaImovel;
}

class JanelaBuscaImovel : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaBuscaImovel(QWidget *parent = 0);
    ~JanelaBuscaImovel();
    JanelaBuscaImovel(ImovelDB*,QWidget *parent = 0);

private slots:
    void on_pushButton_clicked();

private:
    Ui::JanelaBuscaImovel *ui;
    ImovelDB *a;
    QLabel *endereco;
    QLabel *cidade;
    QLabel *inquilino;
    QLabel *bairro;
    QLabel *complemento;
    QLabel *imobiliaria;
    QLabel *observacao;
    QLabel *valorAluguel;
    QLabel *dataVencimento;
    QLabel *Dormitorios;
    //casa
    QLabel *Sobrado;
    QLabel *Quintal;
    QLabel *Garagem;
    //apartamento
    QLabel *Cobertura;
    QLabel *salaoFestas;
    QLabel *TESTE;
    QLabel *academia;
    QLabel *andar;
    QLabel *vagas;
    QLabel *bloco;
    QLabel *PISCINA;


};

#endif // JANELABUSCAIMOVEL_H
