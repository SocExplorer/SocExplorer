#include "elffilewidget.h"
#include "ui_elffilewidget.h"
#include <QtWidgets/QTableWidgetItem>
#include "qhexedit.h"
#include "qtablewidgetintitem.h"

elfFileWidget::elfFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::elfFileWidget)
{
    ui->setupUi(this);
    connect(this->ui->sectionsList,SIGNAL(cellActivated(int,int)),this,SLOT(sectionCellActivated(int,int)));
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
    updateSections();
}



void elfFileWidget::updateSymbols()
{
    this->ui->symbolsList->clear();
    this->ui->symbolsList->setRowCount(p_elf->getSymbolCount());
    this->ui->symbolsList->setHorizontalHeaderLabels(QStringList()<<"Index"<<"Value"<<"Size"<<"Type"<<"Link"<<"Section"<<"Name");
    for(int i=0;i<p_elf->getSymbolCount();i++)
    {
        QTableWidgetItem *newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("%1").arg(i),DecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 0, newItem);

        newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("0x%1").arg(p_elf->getSymbolAddress(i),8,16).replace(" ","0"),HexaDecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 1, newItem);

        newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("%1").arg(p_elf->getSymbolSize(i)),DecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 2, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolType(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 3, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolLinkType(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 4, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolSectionName(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 5, newItem);

        newItem = new QTableWidgetItem(p_elf->getSymbolName(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->symbolsList->setItem(i, 6, newItem);
    }
    this->ui->symbolsList->resizeColumnsToContents();
}



void elfFileWidget::updateSections()
{
    this->ui->sectionsList->clear();
    this->ui->sectionsList->setRowCount(p_elf->getSectionCount());
    this->ui->sectionsList->setHorizontalHeaderLabels(QStringList()<<"Index"<<"Name"<<"Address"<<"Size");
    for(int i=0;i<p_elf->getSectionCount();i++)
    {
        QTableWidgetItem *newItem = (QTableWidgetItem*) new QTableWidgetIntItem(QString("%1").arg(i),DecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->sectionsList->setItem(i,0, newItem);

        newItem = new QTableWidgetItem(p_elf->getSectionName(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->sectionsList->setItem(i, 1, newItem);

        newItem = (QTableWidgetItem*) new QTableWidgetIntItem(QString("0x%1").arg(p_elf->getSectionPaddr(i),8,16).replace(" ","0"),HexaDecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->sectionsList->setItem(i, 2, newItem);

        newItem = (QTableWidgetItem*) new QTableWidgetIntItem(QString("%1").arg(p_elf->getSectionDatasz(i)),DecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->sectionsList->setItem(i, 3, newItem);
    }
    this->ui->sectionsList->resizeColumnsToContents();
}

void elfFileWidget::sectionCellActivated(int row, int column)
{
    Q_UNUSED(column)
    char* buff=NULL;
    int sectionIndex = p_elf->getSectionIndex(this->ui->sectionsList->item(row,1)->text());
    if(sectionIndex!=-1)
    {
        this->p_elf->getSectionData(sectionIndex,&buff);
        this->ui->sectionsHexView->setData(QByteArray(buff,this->p_elf->getSectionDatasz(sectionIndex)));
    }
}














