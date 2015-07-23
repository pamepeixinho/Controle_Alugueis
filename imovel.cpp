#include "imovel.h"

Imovel::Imovel()
{
    this->payment.resize(12, false);
}

Imovel::~Imovel()
{
}

void Imovel::setPayment(vector<bool>v){
    this->payment = v;
}

vector<bool> Imovel::getPayment()const{
    return this->payment;
}

QString Imovel::getEndereco()const{
    return endereco;
}

QString Imovel::getBairro()const{
    return bairro;
}

QString Imovel::getCidade()const{
    return cidade;
}

QString Imovel::getInquilino()const{
    return inquilino;
}

void Imovel::setDormitorios(int d){
    this->dormitorios = d;
}

int Imovel::getDormitorios()const{
    return dormitorios;
}

QString Imovel::getComplemento()const{
    return complemento;
}

QString Imovel::getObservacoes()const{
    return observacao;
}

QString Imovel::getValorAluguel()const{
    return valorAluguel;
}

bool Imovel::getIPTU()const{
    return IPTU;
}

void Imovel::setEndereco(QString _ent){
    endereco = _ent;
}

void Imovel::setCidade(QString ent){
    cidade = ent;
}

void Imovel::setBairro(QString ent){
    bairro = ent;
}

void Imovel::setImobiliaria(QString ent){
    imobiliaria = "Imobiliária " + ent;
}

QString Imovel::getImobiliaria()const{
    return this->imobiliaria;
}

void Imovel::setObservacao(QString ent){
    observacao = ent;
}

void Imovel::setInquilino(QString ent){
    inquilino = ent;
}

void Imovel::setValorAluguel(QString ent){
    valorAluguel = ent;
}

void Imovel::setComplemento(QString ent){
    complemento = ent;
}

void Imovel::setIPTU(bool ent){
    IPTU = ent;
}

bool Imovel::operator <(const Imovel &other)const{
    return this->endereco<other.endereco;
}

QString Imovel::getDataVencimento()const{
    return this->dataVencimento;
}

void Imovel::setDataVencimento(QString ent){
    this->dataVencimento = ent;
}

