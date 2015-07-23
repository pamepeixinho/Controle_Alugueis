#ifndef JANELACADASTROAPTO_H
#define JANELACADASTROAPTO_H

#include <QDialog>
#include "imoveldb.h"
#include <QDebug>
#include "apartamento.h"
#include <QString>

namespace Ui {
class JanelaCadastroApto;
}

class JanelaCadastroApto : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaCadastroApto(QWidget *parent = 0);
    JanelaCadastroApto(QString,int,QWidget *parent = 0);
    Imovel *getImovel()const;
    Imovel *atribuiValores();
    ~JanelaCadastroApto();
    bool getSave()const;

private slots:
    void on_buttonAp_clicked();


private:
    Ui::JanelaCadastroApto *ui;
    Imovel * ImovelTmp;
    QString PathtoSave;
    int n;
    bool save;
};

#endif // JANELACADASTROAPTO_H
