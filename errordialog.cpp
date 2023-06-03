#include "errordialog.h"
#include "ui_errordialog.h"

ErrorDialog::ErrorDialog(const QString& errorMessage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);

    ui->label->setText(errorMessage);
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}
