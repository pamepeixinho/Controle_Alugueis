#include "listartodos.h"
#include "ui_listartodos.h"
#include <QDebug>


ListarTodos::ListarTodos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListarTodos)
{
    ui->setupUi(this);
}

ListarTodos::ListarTodos(ImovelDB *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListarTodos), db(db)
{
    ui->setupUi(this);
    QStringList list = db->getEnderecos();
    for(int i=0;i<db->getTotal();i++){
        ui->listWidget->addItem(list.at(i));
        qDebug() << list.at(i);
    }
}


ListarTodos::~ListarTodos()
{
    delete ui;
}
