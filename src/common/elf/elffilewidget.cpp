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

void elfFileWidget::updateElfFile(ElfFile *file)
{
    this->p_elf = file;
    if(p_elf->isopened() && p_elf->iself())
    {
        this->ui->classLabel->setText(p_elf->getClass());
        this->ui->VersionLabel->setText(QString::number(p_elf->getVersion()));
        this->ui->machineLabel->setText(p_elf->getArchitecture());
        this->ui->endiannesLabel->setText(p_elf->getEndianness());
    }
}
