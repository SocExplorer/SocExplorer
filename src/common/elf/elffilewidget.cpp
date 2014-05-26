#include "elffilewidget.h"
#include "ui_elffilewidget.h"

elfFileWidget::elfFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::elfFileWidget)
{
    ui->setupUi(this);
}

elfFileWidget::~elfFileWidget()
{
    delete ui;
}
