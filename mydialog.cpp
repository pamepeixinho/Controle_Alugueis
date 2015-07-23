#include "mydialog.h"

myDialog::myDialog(QString texto)
{
    QDialog *d = new QDialog;
    QLabel * l = new QLabel;
    l->setText(texto);
    QPushButton *b = new QPushButton(tr("Ok! Let's go!"));

    connect(b,SIGNAL(clicked()),d, SLOT(close()));

    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(l);
    box->addWidget(b);

    d->setLayout(box);
    d->setModal(true);
    d->exec();

}
