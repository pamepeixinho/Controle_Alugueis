#include "janelacadastrocasa.h"
#include "ui_janelacadastrocasa.h"
#include "casa.h"
#include <QTextEdit>
#include <QFile>
#include <QDir>

JanelaCadastroCasa::JanelaCadastroCasa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaCadastroCasa)
{
    ui->setupUi(this);
}

JanelaCadastroCasa::JanelaCadastroCasa(QString t,int n, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaCadastroCasa),PathtoSave(t), n(n)
{
    ui->setupUi(this);
    this->save = false;
}

JanelaCadastroCasa::~JanelaCadastroCasa()
{
    delete ui;
}
Imovel* JanelaCadastroCasa::atribuiValores(){
    Casa *casa = new Casa();
    casa->setEndereco(ui->endereco->text());
    casa->setCidade(ui->cidade->text());
    casa->setInquilino(ui->locatario->text());
    casa->setBairro(ui->bairro->text());
    casa->setComplemento(ui->complemento->text());
    casa->setImobiliaria(ui->imobiliaria->currentText());
    casa->setObservacao(ui->observacoes->toPlainText());
    casa->setValorAluguel(ui->valorAluguel->text());
    casa->setDormitorios(ui->dormitorios->currentText().toInt());
    casa->setDataVencimento(QString::number(ui->dataVencimento->date().day()) + '/' + QString::number(ui->dataVencimento->date().month()));
//casa
    casa->setSobrado(ui->sobrado->isChecked());
    casa->setQuintal(ui->quintal->isChecked());
    casa->setGaragem(ui->garagem->isChecked());
//default
    casa->setPayment(vector<bool>(12,false));
    casa->setIPTU(false);

    return (Imovel*)casa;
}


void JanelaCadastroCasa::on_buttonCasa_clicked()
{
    Imovel *imovel = atribuiValores();
    this->ImovelTmp = imovel;
    QString path_dir;
    QDir dir;
    path_dir = PathtoSave + "/" + QString::number(n+1) + "/";
    dir.mkdir(path_dir);
    qDebug() << "folder = " << path_dir;
    imovel->imprime(path_dir);\
    this->save = true;
    close();
}

bool JanelaCadastroCasa::getSave()const{
    return this->save;
}

Imovel *JanelaCadastroCasa::getImovel()const{
    return ImovelTmp;
}
