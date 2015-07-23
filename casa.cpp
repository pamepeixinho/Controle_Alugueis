#include "casa.h"
#include <QDebug>
#include <QString>

int Casa::getType()const{
    return 1;
}

void Casa::imprime(QString path)const{

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

    out << "1" <<"\n";
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
    //casa
    out << (this->sobrado==true? "true" : "false") << "\n";
    out << (this->garagem==true? "true" : "false") << "\n";
    out << (this->quintal==true? "true" : "false") << "\n";

    for(int i=0;i<12;i++)
        outP << "false\n";

    outI <<"false";

    file.close();
    fileP.close();
    fileI.close();
}

Casa::Casa(vector<QString>v):Imovel(){
    vector<bool> pay(12, false);
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

    //casa
    setSobrado((v[10]=="true"? true : false));
    setGaragem((v[12]=="true"? true : false));
    setQuintal((v[11]=="true"? true : false));

}

void Casa::setGaragem(bool ent){
    garagem = ent;
}

bool Casa::getGaragem(){
    return garagem;
}

void Casa::setSobrado(bool ent){
    sobrado = ent;
}

bool Casa::getSobrado(){
    return sobrado;
}

void Casa::setQuintal(bool ent){
    quintal = ent;
}

bool Casa::getQuintal(){
    return quintal;
}

//ostream &Casa::operator <<( ostream &output)const{
//    return output;
//}
