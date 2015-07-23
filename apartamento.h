#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "imovel.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>

using namespace std;

class Apartamento : public Imovel
{
    bool cobertura;
    bool salaoFestas;
    bool piscina;
    bool academia;
    int andar;
    int vagas;
    QString bloco;
public:
    Apartamento():Imovel(){}
    Apartamento(vector<QString>);
    int getType()const;
    void imprime(QString path)const;
//    ostream &operator <<( ostream &output) const;
    ~Apartamento();

    void setCobertura(bool);
    bool getCobertura();

    void setSalao(bool);
    bool getSalao();

    void setVagas(int);
    int getVagas()const;

    void setPiscina(bool);
    bool getPiscina();

    void setAcademia(bool);
    bool getAcademia();

    void setAndar (int);
    int getAndar();

    void setBloco(QString);
    QString getBloco();

};

#endif // APARTAMENTO_H
