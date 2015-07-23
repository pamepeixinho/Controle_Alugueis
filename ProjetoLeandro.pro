#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T13:50:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoLeandro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    janelacadastrocasa.cpp \
    janelacadastroapto.cpp \
    imovel.cpp \
    imoveldb.cpp \
    casa.cpp \
    apartamento.cpp \
    mydialog.cpp \
    janelabuscaimovel.cpp \
    darbaixa.cpp \
    listartodos.cpp \
    janelaconsultar.cpp

HEADERS  += mainwindow.h \
    janelacadastrocasa.h \
    janelacadastroapto.h \
    imovel.h \
    imoveldb.h \
    casa.h \
    apartamento.h \
    mydialog.h \
    janelabuscaimovel.h \
    darbaixa.h \
    listartodos.h \
    janelaconsultar.h

FORMS    += mainwindow.ui \
    janelacadastrocasa.ui \
    janelacadastroapto.ui \
    janelabuscaimovel.ui \
    darbaixa.ui \
    listartodos.ui \
    janelaconsultar.ui
