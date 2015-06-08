#include "sessionmanagerdialog.h"
#include "ui_sessionmanagerdialog.h"

SessionManagerDialog::SessionManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SessionManagerDialog)
{
    ui->setupUi(this);
}

SessionManagerDialog::~SessionManagerDialog()
{
    delete ui;
}
