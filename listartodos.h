#ifndef LISTARTODOS_H
#define LISTARTODOS_H
#include "imoveldb.h"
#include <QDialog>
#include <QStringList>


namespace Ui {
class ListarTodos;
}

class ListarTodos : public QDialog
{
    Q_OBJECT

public:
    explicit ListarTodos(QWidget *parent = 0);
    ~ListarTodos();
    ListarTodos(ImovelDB *db, QWidget *parent = 0);
private slots:
//    void on_pushButton_clicked();

private:
    Ui::ListarTodos *ui;
    ImovelDB *db;
};

#endif // LISTARTODOS_H
