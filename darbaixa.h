#ifndef DARBAIXA_H
#define DARBAIXA_H

#include <QDialog>
#include <QDebug>
#include "imoveldb.h"
#include <QString>
#include <QStringList>

namespace Ui {
class darBaixa;
}

class darBaixa : public QDialog
{
    Q_OBJECT

public:
    explicit darBaixa(QWidget *parent = 0);
    darBaixa(ImovelDB*,QWidget *parent = 0);
    ~darBaixa();

private slots:
    void on_salvar_clicked();

private:
    Ui::darBaixa *ui;
    ImovelDB * db;
};

#endif // DARBAIXA_H
