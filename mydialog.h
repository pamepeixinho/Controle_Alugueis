#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QPalette>
#include <QApplication>
#include <QWidget>

class myDialog : public QDialog
{
public:
    myDialog(QString texto);
};

#endif // MYDIALOG_H
