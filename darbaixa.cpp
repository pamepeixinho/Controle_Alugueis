#include "darbaixa.h"
#include "ui_darbaixa.h"

darBaixa::darBaixa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::darBaixa)
{
    ui->setupUi(this);
}

darBaixa::~darBaixa()
{
    delete ui;
}

darBaixa::darBaixa(ImovelDB* db,QWidget *parent):
    QDialog(parent),
    ui(new Ui::darBaixa), db(db)
{
    ui->setupUi(this);
    QStringList list = db->getEnderecos();
     QStringList list2 = (QStringList()<<"Aluguel"<<"IPTU");
    ui->Imovel->addItems(list);
    ui->typePayment->addItems(list2);
    ui->mes->setRange(1,12);
}

void darBaixa::on_salvar_clicked()
{
    QString endereco = ui->Imovel->currentText();
    int n = db->search(endereco);
    Imovel *im = db->busca(endereco);
    QString caminho = db->getCaminho();
    QString path = caminho + "/" + QString::number(n+1) + "/";
    qDebug() << "path " << path;
    QFile fileP(path + "payment.txt");
    QFile fileI(path + "IPTU.txt");
    if (!fileP.open(QIODevice::ReadOnly| QIODevice::WriteOnly | QIODevice::Text))
        return;
    if (!fileI.open(QIODevice::ReadOnly| QIODevice::WriteOnly | QIODevice::Text))
        return;


    QTextStream outP(&fileP);
    QTextStream outI(&fileI);
    if(ui->typePayment->currentText()=="Aluguel"){
        vector<bool>pay(12);
        while(!outP.atEnd())
            pay.push_back((outP.readLine()=="true"?true:false));
        int mes = ui->mes->value();
        pay[mes-1] = true;
        im->setPayment(pay);
        outP.seek(0);
        for(int i=0;i<12;i++)
            outP << (pay[i]==true? "True": "False") << "\n";
    }
    else{
        QString teste = outI.readLine();
        outI.seek(0);
        outI << "true" << "\n";
        im->setIPTU(true);
    }

    fileP.close();
    fileI.close();
    close();
}
