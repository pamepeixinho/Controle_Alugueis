#ifndef IMOVELDB_H
#define IMOVELDB_H

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include "imovel.h"
#include <QString>
#include <QDir>
#include <QFile>
#include <QDialog>
#include "apartamento.h"
#include "casa.h"
#include <QStringList>

using namespace std;

class ImovelDB
{
   vector<Imovel*>DataBase;
   QString dir;

public:
    ImovelDB();
    ImovelDB(QDir);
    ImovelDB(QString);
    void add(Imovel *);
    void reloadAll(int);
    void remove(Imovel *);
//    vector<Imovel*>::iterator busca(QString endereco);
    vector<Imovel*>::iterator busca(Imovel *);
    Imovel* busca(QString endereco);
    int search(QString);
    void consultar(Imovel *)const;
    void consultarTodos()const;
    void consultar(QString endereco)const;
    void printAll()const;
    int getTotal()const;
    void carregaImoveis();
    int tamanhoDB();
    bool loadBasico();
    bool loadQt();
    void imprimeEndereco(int);
    QStringList getEnderecos()const;

    void setCaminho(QString);
    QString getCaminho();

};

#endif // IMOVELDB_H
