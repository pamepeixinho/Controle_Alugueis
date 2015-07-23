#ifndef JANELACONSULTAR_H
#define JANELACONSULTAR_H

#include <QDialog>
#include <QDebug>
#include "imoveldb.h"
#include <QStringList>
#include <QString>
#include <vector>
using namespace std;

namespace Ui {
class JanelaConsultar;
}

class JanelaConsultar : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaConsultar(QWidget *parent = 0);
    ~JanelaConsultar();
    JanelaConsultar(ImovelDB *, QWidget *parent = 0);

private slots:
    void on_search_clicked();

private:
    Ui::JanelaConsultar *ui;
    ImovelDB *db;
};

#endif // JANELACONSULTAR_H
