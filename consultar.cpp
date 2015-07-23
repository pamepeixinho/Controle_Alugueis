#include "consultar.h"
#include "ui_consultar.h"

Consultar::Consultar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Consultar)
{
    ui->setupUi(this);
}

Consultar::~Consultar()
{
    delete ui;
}
