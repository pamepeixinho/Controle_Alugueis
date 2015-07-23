#ifndef JANELACADASTROCASA_H
#define JANELACADASTROCASA_H

#include <QDialog>
#include "imoveldb.h"
#include <QDebug>
#include "casa.h"
#include "apartamento.h"
#include <QString>

namespace Ui {
class JanelaCadastroCasa;
}

class JanelaCadastroCasa : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaCadastroCasa(QWidget *parent = 0);
    JanelaCadastroCasa(QString,int,QWidget *parent = 0);
    Imovel *atribuiValores();
    ~JanelaCadastroCasa();
    Imovel *getImovel()const;
    bool getSave()const;

private slots:
    void on_buttonCasa_clicked();

private:
    Ui::JanelaCadastroCasa *ui;
    QString PathtoSave;
    int n;
    Imovel * ImovelTmp;
    bool save;
    //    Imovel &db;
};

#endif // JANELACADASTROCASA_H
