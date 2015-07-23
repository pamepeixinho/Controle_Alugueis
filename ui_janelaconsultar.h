/********************************************************************************
** Form generated from reading UI file 'janelaconsultar.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELACONSULTAR_H
#define UI_JANELACONSULTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_JanelaConsultar
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QLabel *label;
    QComboBox *TypePayment;
    QSplitter *mes;
    QLabel *label_2;
    QSpinBox *mes_box;
    QPushButton *search;
    QListWidget *list;

    void setupUi(QDialog *JanelaConsultar)
    {
        if (JanelaConsultar->objectName().isEmpty())
            JanelaConsultar->setObjectName(QStringLiteral("JanelaConsultar"));
        JanelaConsultar->resize(367, 300);
        verticalLayout = new QVBoxLayout(JanelaConsultar);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_3 = new QSplitter(JanelaConsultar);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        splitter->addWidget(label);
        TypePayment = new QComboBox(splitter);
        TypePayment->setObjectName(QStringLiteral("TypePayment"));
        splitter->addWidget(TypePayment);
        splitter_3->addWidget(splitter);
        mes = new QSplitter(splitter_3);
        mes->setObjectName(QStringLiteral("mes"));
        mes->setOrientation(Qt::Vertical);
        label_2 = new QLabel(mes);
        label_2->setObjectName(QStringLiteral("label_2"));
        mes->addWidget(label_2);
        mes_box = new QSpinBox(mes);
        mes_box->setObjectName(QStringLiteral("mes_box"));
        mes->addWidget(mes_box);
        splitter_3->addWidget(mes);

        verticalLayout->addWidget(splitter_3);

        search = new QPushButton(JanelaConsultar);
        search->setObjectName(QStringLiteral("search"));

        verticalLayout->addWidget(search);

        list = new QListWidget(JanelaConsultar);
        list->setObjectName(QStringLiteral("list"));

        verticalLayout->addWidget(list);


        retranslateUi(JanelaConsultar);

        QMetaObject::connectSlotsByName(JanelaConsultar);
    } // setupUi

    void retranslateUi(QDialog *JanelaConsultar)
    {
        JanelaConsultar->setWindowTitle(QApplication::translate("JanelaConsultar", "Dialog", 0));
        label->setText(QApplication::translate("JanelaConsultar", "Tipo de Pagamento", 0));
        label_2->setText(QApplication::translate("JanelaConsultar", "Mes", 0));
        search->setText(QApplication::translate("JanelaConsultar", "search", 0));
    } // retranslateUi

};

namespace Ui {
    class JanelaConsultar: public Ui_JanelaConsultar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELACONSULTAR_H
