#include "janelabuscaimovel.h"
#include "ui_janelabuscaimovel.h"
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <qalgorithms.h>
#include <QMessageBox>
#include <QPushButton>
#include "imovel.h"

JanelaBuscaImovel::JanelaBuscaImovel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaBuscaImovel)
{
    ui->setupUi(this);
    //    QGridLayout *a = new QGridLayout;
    //    label = new QLabel;
    //    label->setText("teste");
    //    layout->addWidget(label);
    //    ui->groupBox->setLayout(a);
    ui->groupBox->setTitle("");
    ui->label->setText("Digite o Endereco");
}

JanelaBuscaImovel::JanelaBuscaImovel(ImovelDB *a, QWidget *parent): a(a),QDialog(parent),
    ui(new Ui::JanelaBuscaImovel){
    ui->setupUi(this);
    ui->groupBox->setTitle("");
    ui->label->setText("Digite o Endereco");
}

JanelaBuscaImovel::~JanelaBuscaImovel()
{
    delete ui;
}

void JanelaBuscaImovel::on_pushButton_clicked()
{

    if(ui->groupBox->layout()!=0){
        Sobrado->clear();
        Garagem->clear();
        Quintal->clear();
        Cobertura->clear();
        salaoFestas->clear();
        PISCINA->clear();
        academia->clear();
        andar->clear();
        vagas->clear();
        bloco->clear();
        qDeleteAll(ui->groupBox->layout()->children());
        ui->groupBox->layout()->update();
        delete ui->groupBox->layout();

    }
    else{
        endereco = new QLabel;
        cidade = new QLabel;
        inquilino = new QLabel;
        bairro = new QLabel;
        complemento = new QLabel;
        imobiliaria = new QLabel;
        observacao = new QLabel;
        valorAluguel= new QLabel;
        dataVencimento = new QLabel;
        Dormitorios= new QLabel;
        //casa
        Sobrado= new QLabel;
        Quintal= new QLabel;
        Garagem= new QLabel;
        //apartamento
        Cobertura = new QLabel;
        salaoFestas = new QLabel;
        PISCINA = new QLabel;
        academia = new QLabel;
        andar = new QLabel;
        vagas = new QLabel;
        bloco = new QLabel;
    }
    QString end = ui->lineEdit->text();
    //   qDebug()<< end;
    Imovel *imovel =  a->busca(end);
    if(imovel!=NULL){
//        qDebug() << imovel->getType();
        QGridLayout *layout = new QGridLayout;
        endereco->setText("Endereço: "+end);
        cidade->setText("Cidade: "+ (((Imovel*)imovel)->getCidade()));
        inquilino->setText("Inquilino: "+ (((Imovel*)imovel)->getInquilino()));
        bairro->setText("Bairro: "+ (((Imovel*)imovel)->getBairro()));
        complemento->setText("Complemento: "+ (((Imovel*)imovel)->getComplemento()));
        imobiliaria->setText("Imobiliaria: "+ (((Imovel*)imovel)->getImobiliaria()));
        observacao->setText("Observacao: "+ (((Imovel*)imovel)->getObservacoes()));
        valorAluguel->setText("Valor do Aluguel: "+ (((Imovel*)imovel)->getValorAluguel()));
        dataVencimento->setText("Data de Vencimento: "+ (((Imovel*)imovel)->getDataVencimento()));
        Dormitorios->setText("Dormitorios: "+ QString::number(((Imovel*)imovel)->getDormitorios()));

        layout->addWidget(endereco);
        layout->addWidget(cidade);
        layout->addWidget(inquilino);
        layout->addWidget(bairro);
        layout->addWidget(complemento);
        layout->addWidget(observacao);
        layout->addWidget(imobiliaria);
        layout->addWidget(valorAluguel);
        layout->addWidget(dataVencimento);
        layout->addWidget(Dormitorios);

        QString aux;
        if(imovel->getType()== 2){
            ui->groupBox->setTitle("Apartamento");
            Sobrado->clear();
            Garagem->clear();
            Quintal->clear();
            aux = (((Apartamento*)imovel)->getCobertura()==true? "Sim": "Nao");
            Cobertura->setText("Cobertura: " + aux);
            layout->addWidget(Cobertura);
            aux = (((Apartamento*)imovel)->getSalao()==true?"Sim":"Nao");
            salaoFestas->setText("Salao de festas: " + aux);
            layout->addWidget(salaoFestas);
            aux = (((Apartamento*)imovel)->getAcademia()==true? "Sim": "Nao");
            academia->setText("Academia: " + aux );
            layout->addWidget(academia);
            andar->setText("Andar: " + QString::number(((Apartamento*)imovel)->getAndar()));
            layout->addWidget(andar,0, 1);
            vagas->setText("Vagas: " + QString::number(((Apartamento*)imovel)->getVagas()));
            layout->addWidget(vagas, 1,1);
            bloco->setText("Bloco: " + (((Apartamento*)imovel)->getBloco()));
            layout->addWidget(bloco, 2, 1);
            aux = ((((Apartamento*)imovel)->getPiscina())==true? "Sim": "Nao");
            PISCINA->setText("Piscina: " + aux);
            layout->addWidget(PISCINA, 3, 1);
        }
        else {
            ui->groupBox->setTitle("Casa");
                   Cobertura->clear();
                   salaoFestas->clear();
                   PISCINA->clear();
                   academia->clear();
                   andar->clear();
                   vagas->clear();
                   bloco->clear();
            aux = (((Casa*)imovel)->getSobrado()==true?"Sim": "Nao");
            Sobrado->setText("Sobrado: " + aux);
            layout->addWidget(Sobrado);
            aux =(((Casa*)imovel)->getGaragem()==true?"Sim": "Nao");
            Garagem->setText("Garagem: " + aux);
            layout->addWidget(Garagem);
            aux =(((Casa*)imovel)->getQuintal()==true?"Sim": "Nao");
            Quintal->setText("Quintal: " + aux);
            layout->addWidget(Quintal);
        }

        ui->groupBox->setLayout(layout);

    }

    else{
        QMessageBox::warning(this, "Retorne", "Não existe este endereço!");
    }

}
