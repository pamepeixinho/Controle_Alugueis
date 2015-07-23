#include "mainwindow.h"
#include "janelacadastroapto.h"
#include "janelabuscaimovel.h"
#include "janelacadastrocasa.h"
#include "imovel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        MainWindow w;
        w.setWindowIcon(QIcon("../ProjetoLeandro/window.png"));
        w.setWindowTitle("Controle de Aluguel");
        w.show();

    return a.exec();
}

