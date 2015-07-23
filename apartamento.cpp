#include "apartamento.h"

//Apartamento::Apartamento()
//{
//}

int Apartamento::getType()const{
    return 2;
}

void Apartamento::imprime(QString path)const{
    qDebug() << "printa ap";
    QFile file(path + "data.txt");
    QFile fileP(path + "payment.txt");
    QFile fileI(path + "IPTU.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    if (!fileP.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    if (!fileI.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    QTextStream outP(&fileP);
    QTextStream outI(&fileI);

    out << "2" <<"\n";
    out << getEndereco() << "\n";
    out << this->getCidade() << "\n";
    out << this->getInquilino() << "\n";
    out << getBairro() << "\n";
    out << getComplemento() << "\n";
    out << getImobiliaria() << "\n";
    out << getObservacoes() << "\n";
    out << getValorAluguel() << "\n";
    out << getDataVencimento() << "\n";
    out << getDormitorios() << "\n";
    //ap

    out << (this->cobertura==true? "true" : "false") << "\n";
    out << (this->salaoFestas==true? "true" : "false") << "\n";
    out << (this->piscina==true? "true" : "false") << "\n";
    out << (this->academia==true? "true" : "false") << "\n";
    out << QString::number(this->andar) << "\n";
    out << QString::number(this->vagas) << "\n";
    out << this->bloco << "\n";


    for(int i=0;i<12;i++)
        outP << "false\n";

    outI <<"false";

    file.close();
    fileP.close();
    fileI.close();
}

Apartamento::Apartamento(vector<QString>v):Imovel(){
    vector<bool>pay(12, false);
    setEndereco(v[0]);
    setCidade(v[1]);
    setInquilino(v[2]);
    setBairro(v[3]);
    setComplemento(v[4]);
    setImobiliaria(v[5]);
    setObservacao(v[6]);
    setValorAluguel(v[7]);
    setDataVencimento(v[8]);
    setDormitorios(v[9].toInt());
    setPayment(pay);
    //ap
    setCobertura((v[10]=="true"? true : false));
    setSalao((v[11]=="true"? true : false));
    setPiscina((v[12]=="true"? true : false));
    setAcademia((v[13]=="true"? true : false));
    setAndar(v[14].toInt());
    setVagas(v[15].toInt());
    setBloco(v[16]);
}


void Apartamento::setCobertura(bool ent){
    cobertura = ent;
}

bool Apartamento::getCobertura(){
    return cobertura;
}

void Apartamento::setSalao(bool ent){
    salaoFestas = ent;
}

bool Apartamento::getSalao(){
    return salaoFestas;
}

void Apartamento::setPiscina(bool ent){
    piscina = ent;
}

void Apartamento::setVagas(int n){
    this->vagas = n;
}

int Apartamento::getVagas()const{
    return this->vagas;
}

bool Apartamento::getPiscina(){
    return piscina;
}

void Apartamento::setAcademia(bool ent){
    academia = ent;
}

bool Apartamento::getAcademia(){
    return academia;
}

void Apartamento::setAndar(int ent){
    andar = ent;
}

int Apartamento::getAndar(){
    return andar;
}

void Apartamento::setBloco(QString ent){
    bloco = ent;
}

QString Apartamento::getBloco(){
    return bloco;
}

//ostream & Apartamento::operator<<( ostream &output)const{
//    return output;
//}
