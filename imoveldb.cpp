#include "imoveldb.h"
#include <QFileDialog>
#include <QFile>
#include <QDialog>
#include <QDebug>
#include <vector>
#include <QString>
#include <QtGui>
#include <QWidget>
#include <QtCore>
#include <QApplication>
#include <QMainWindow>
#include <QTextStream>
#include "imovel.h"
#include "casa.h"
#include "apartamento.h"

//#include "mainwindow.h"

ImovelDB::ImovelDB()
{
this->DataBase.clear();

}

ImovelDB::ImovelDB(QString dir):dir(dir){
    this->DataBase.clear();
//    testao();

}

int ImovelDB::getTotal()const{
    return this->DataBase.size();
}

void ImovelDB::reloadAll(int n){
    QString path = getCaminho(), pathD,pathP, pathI;
    QString id;
    Imovel *imovel;

    vector<QString> vet;
    for (int i = 1; i <= n; i++){
        qDebug() << i;
        pathD = path + "/" + (QString::number(i)) + "/data.txt";
        pathP = path + "/" + (QString::number(i)) + "/payment.txt";
        pathI = path + "/" + (QString::number(i)) + "/IPTU.txt";

        qDebug() << pathD ;
        qDebug() << pathP ;

        QFile textFileD(pathD);
        if (!textFileD.open(QIODevice::ReadOnly))
            return;
        QFile textFileP(pathP);
        if (!textFileP.open(QIODevice::ReadOnly))
            return;
        QFile textFileI(pathI);
        if (!textFileI.open(QIODevice::ReadOnly))
            return;

        QTextStream textStream(&textFileD);
        id = textStream.readLine();

        while (!textStream.atEnd())
            vet.push_back(textStream.readLine());

        qDebug() <<"vet"<< vet.size();

        for(int i=0; i < vet.size() ; i++)
            qDebug () << vet[i];

         qDebug () << "id" << id;
         qDebug () << "--------------";

        if (id.toInt() == 1)
            imovel = new Casa(vet);
        else if(id.toInt()==2)
            imovel = new Apartamento(vet);

        QTextStream textStreamP(&textFileP);
        vector<bool>pay;

        for(int i=0;i<12;i++)
            pay.push_back(textStreamP.readLine()=="True"? true : false);

        for(int i=0;i<12;i++){
            qDebug() << pay[i];
        }

        QTextStream textStreamI(&textFileI);
        imovel->setIPTU(textStreamI.readLine()=="True"? true : false);
        imovel->setPayment(pay);

        add(imovel);
        vet.clear();
    }
}

void ImovelDB::imprimeEndereco(int i){
    qDebug() << ((Imovel*)DataBase[i])->getEndereco();
}

void ImovelDB::add(Imovel *a){
    DataBase.push_back(a);
}

void ImovelDB::setCaminho(QString ent){
    dir = ent;
}

int ImovelDB::tamanhoDB(){
    return (DataBase.size());
}

QString ImovelDB::getCaminho(){
    return dir;
}

//vector<Imovel*>::iterator ImovelDB::busca(QString endereco){
//vector<Imovel*>::iterator it;
//    for(it=DataBase.begin();it!=DataBase.end();it++)
//        if((*it)->getEndereco() == endereco)
//            return it;
//}

Imovel* ImovelDB::busca(QString endereco){
    for(int i=0;i<DataBase.size();i++)
        if(((Imovel*)DataBase[i])->getEndereco() == endereco)
            return DataBase[i];

    return NULL;
}

vector<Imovel*>::iterator ImovelDB::busca(Imovel *p){
vector<Imovel*>::iterator it;

    for(it=DataBase.begin();it!=DataBase.end();it++)
        if(*it == p)
            return it;

}

bool ImovelDB::loadBasico(){

    QString path = QDir::currentPath() + "/base.txt";
    QFile textFile(path);

        if (!textFile.open(QIODevice::ReadOnly))
            return false;

        QTextStream textStream(&textFile);
        QString texto = textStream.readLine();
        QString qt = textStream.readLine();

        setCaminho(texto);
        qDebug()<< "qt = " <<qt.toInt();

        reloadAll(qt.toInt());
        return true;
}

bool ImovelDB::loadQt(){

    QString path = QDir::currentPath() + "/base.txt";
    QFile textFile(path);

        if (!textFile.open(QIODevice::ReadOnly| QIODevice::WriteOnly | QIODevice::Text))
            return false;

        QTextStream textStream(&textFile);
        QString texto = textStream.readLine();
        QString qt = textStream.readLine();
        QString n = QString::number(this->DataBase.size());
        textStream.seek(0);
        textStream << texto << "\n";
        textStream << n << "\n";

    textFile.close();
        return true;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

void ImovelDB::consultarTodos()const{
    for( int i=0;i<DataBase.size();i++)
        qDebug() <<((Imovel*)DataBase[i])->getEndereco();
}

QStringList ImovelDB::getEnderecos()const{
  QStringList list;
    for( int i=0;i<DataBase.size();i++)
        list.append(((Imovel*)DataBase[i])->getEndereco());
    return list;
}

int ImovelDB::search(QString endereco){
    for( int i=0;i<DataBase.size();i++)
        if(((Imovel*)DataBase[i])->getEndereco() == endereco)
            return i;
}
