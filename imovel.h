#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
#include <QString>
#include <vector>
#include <QStringList>

using namespace std;

class Imovel
{
    QString endereco;
    QString cidade;
    QString inquilino;
    QString bairro;
    QString complemento;
    QString imobiliaria;
    QString observacao;
    QString valorAluguel;
    QString dataVencimento;
    int dormitorios;
    bool IPTU;
    vector<bool>payment;

public:
    Imovel();
    virtual int getType()const=0;
    virtual void imprime(QString path)const =0;
    bool operator < (const Imovel &)const;
//    virtual ostream & operator <<( ostream &) const;
    ~Imovel();

    void setEndereco(QString);
    void setBairro(QString);
    void setInquilino(QString);
    void setCidade(QString);
    void setObservacao(QString);
    void setValorAluguel(QString);
    void setImobiliaria(QString);
    void setComplemento(QString);
    void setIPTU(bool);
    void setPayment(vector<bool>);
    void setDormitorios(int);
    void setDataVencimento(QString);


    QString getDataVencimento()const;
    QString getEndereco()const;
    QString getBairro()const;
    QString getInquilino()const;
    QString getCidade()const;
    QString getObservacoes()const;
    QString getComplemento()const;
    QString getImobiliaria()const;
    QString getValorAluguel()const;
    bool getIPTU()const;
    vector<bool> getPayment()const;
    int getDormitorios()const;
};

#endif // IMOVEL_H
