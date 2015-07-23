#ifndef CASA_H
#define CASA_H

#include "imovel.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <QString>
#include <QFile>
#include <QTextStream>

using namespace std;

class Casa : public Imovel
{
    bool sobrado;
    bool quintal;
    bool garagem;
public:
    Casa():Imovel(){}
    Casa(vector<QString>v);
    int getType()const;
    void imprime(QString path)const;
//    ostream &operator << ( ostream &output)const;
    ~Casa();

    void setSobrado(bool);
    bool getSobrado();

    void setQuintal(bool);
    bool getQuintal();

    void setGaragem(bool);
    bool getGaragem();
};

#endif // CASA_H
