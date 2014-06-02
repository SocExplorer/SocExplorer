#include "elffilewidget.h"
#include "ui_elffilewidget.h"
#include <QtWidgets/QTableWidgetItem>

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
        this->ui->abiLabel->setText(p_elf->getABI());
        this->ui->entryPointLabel->setText(QString("0x%1").arg((uint)p_elf->getEntryPointAddress(),8,16));
        this->ui->typeLabel->setText(p_elf->getType());
        this->ui->sectionCountLabel->setText(QString::number(p_elf->getSectionCount()));
        this->ui->symbolCountLabel->setText(QString::number(p_elf->getSymbolCount()));
    }
    updateSymbols();
}

void elfFileWidget::updateSymbols()
{
    this->ui->symbolsList->clear();
    this->ui->symbolsList->setRowCount(p_elf->getSymbolCount());
    this->ui->symbolsList->setHorizontalHeaderLabels(QStringList()<<"Value"<<"Size"<<"Type"<<"Link"<<"Section"<<"Name");
    for(int i=0;i<p_elf->getSymbolCount();i++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(QString("0x%1").arg(p_elf->getSymbolAddress(i),8,16));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 0, newItem);

        newItem = new QTableWidgetItem(QString("0x%1").arg(p_elf->getSymbolSize(i),8,16));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 1, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolType(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 2, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolLinkType(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 3, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolSectionName(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 4, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolName(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 5, newItem);
    }
    this->ui->symbolsList->resizeColumnsToContents();
}














