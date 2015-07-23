#include "janelacadastroapto.h"
#include "ui_janelacadastroapto.h"
#include <QTextEdit>
#include <QFile>
#include <QDir>

JanelaCadastroApto::JanelaCadastroApto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaCadastroApto)
{
    ui->setupUi(this);
    // check box -> ui->lazer->isChecked();
}

JanelaCadastroApto::JanelaCadastroApto(QString t,int n, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaCadastroApto),PathtoSave(t), n(n)
{
    ui->setupUi(this);
    this->save = false;
}


bool JanelaCadastroApto::getSave()const{
    return this->save;
}

JanelaCadastroApto::~JanelaCadastroApto()
{
    delete ui;
}

void JanelaCadastroApto::on_buttonAp_clicked()
{
    Imovel *imovel = atribuiValores();
    this->ImovelTmp = imovel;
    QString path_dir;
    QDir dir;
    path_dir = PathtoSave + "/" + QString::number(n+1) + "/";
    dir.mkdir(path_dir);
    qDebug() << "folder = " << path_dir;
    imovel->imprime(path_dir);
    this->save = true;
    close();

}

Imovel* JanelaCadastroApto::atribuiValores(){
    Apartamento *apartamento = new Apartamento();
    apartamento->setEndereco(ui->endereco->text());
    apartamento->setCidade(ui->cidade->text());
    apartamento->setInquilino(ui->locatario->text());
    apartamento->setBairro(ui->bairro->text());
    apartamento->setComplemento(ui->complemento->text());
    apartamento->setImobiliaria(ui->imobiliaria->currentText());
    apartamento->setObservacao(ui->observacoes->toPlainText());
    apartamento->setValorAluguel(ui->valorAluguel->text());
    apartamento->setDataVencimento(QString::number(ui->dataVencimento->date().day()) + '/' + QString::number(ui->dataVencimento->date().month()));
    apartamento->setDormitorios(ui->dormitorios->currentText().toInt());
//apartamento
    apartamento->setCobertura(ui->cobertura->isChecked());
    apartamento->setSalao(ui->salaodefestas->isChecked());
    apartamento->setPiscina(ui->piscina->isChecked());
    apartamento->setAcademia(ui->academia->isChecked());
    apartamento->setAndar(ui->andar->text().toInt());
    apartamento->setVagas(ui->vagasGaragem->currentText().toInt());
    apartamento->setBloco(ui->bloco->text());

//default
    apartamento->setPayment(vector<bool>(12,false));
    apartamento->setIPTU(false);

    return (Imovel*)apartamento;
}

Imovel *JanelaCadastroApto::getImovel()const{
    return ImovelTmp;
}
