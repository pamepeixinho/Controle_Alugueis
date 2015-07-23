#include "janelaconsultar.h"
#include "ui_janelaconsultar.h"

JanelaConsultar::JanelaConsultar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaConsultar)
{
    ui->setupUi(this);
}

JanelaConsultar::JanelaConsultar(ImovelDB *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaConsultar), db(db)
{
    ui->setupUi(this);
    QStringList list2 = (QStringList()<<"Aluguel"<<"IPTU");
    ui->TypePayment->addItems(list2);
    ui->mes_box->setRange(1,12);

}

void JanelaConsultar::on_search_clicked()
{
    ui->list->clear();
    int mesChoosed = ui->mes_box->value();
    QString choosed = ui->TypePayment->currentText();
    Imovel *a;
    QString k;
    QStringList list = db->getEnderecos(), pendencias;
    if(choosed == "Aluguel"){
        vector<vector<bool>>AllPayment;
        foreach (k, list) {
            a = db->busca(k);
            AllPayment.push_back(a->getPayment());
        }
//        for(int i=0;i<AllPayment.size();i++){
//                qDebug() << i << "--------";
//            for(int j=0;j<AllPayment[i].size();j++)
//                qDebug() <<j << " " << AllPayment[i][j];
//        }
        qDebug() << mesChoosed-1;
        for(int i=0;i<AllPayment.size();i++){
            if(AllPayment[i][mesChoosed-1]==false){
                pendencias.append(list[i]);
                qDebug() << AllPayment[i][mesChoosed-1] <<"->"<<list[i];
            }
        }
    }
    else{
        vector<bool>iptu;
        foreach (k, list) {
            a = db->busca(k);
            iptu.push_back(a->getIPTU());
        }
        for(int i=0;i<iptu.size();i++)
            if(iptu[i]==false)
                pendencias.append(list[i]);
    }

     ui->list->addItems(pendencias);
}

JanelaConsultar::~JanelaConsultar()
{
    delete ui;
}
