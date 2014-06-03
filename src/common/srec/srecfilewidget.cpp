#include "srecfilewidget.h"
#include "ui_srecfilewidget.h"
#include <QTableWidgetItem>
#include <qtablewidgetintitem.h>

srecFileWidget::srecFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::srecFileWidget)
{
    ui->setupUi(this);
    connect(this->ui->fragmentsList,SIGNAL(cellActivated(int,int)),this,SLOT(recordCellActivated(int,int)));
}

srecFileWidget::~srecFileWidget()
{
    delete ui;
}

void srecFileWidget::updatSrecFile(srecFile *file)
{
    this->p_srec = file;
    if(p_srec->isopened() && p_srec->isSREC())
    {
        updateRecords();
    }
}

void srecFileWidget::updateRecords()
{
    this->ui->fragmentsList->clear();
    this->ui->fragmentsList->setRowCount(p_srec->getFragmentsCount());
    this->ui->fragmentsList->setHorizontalHeaderLabels(QStringList()<<"Index"<<"Address"<<"Size"<<"Header");
    for(int i=0;i<p_srec->getFragmentsCount();i++)
    {
        QTableWidgetItem *newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("%1").arg(i),DecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->fragmentsList->setItem(i, 0, newItem);

        newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("0x%1").arg(p_srec->getFragmentAddress(i),8,16).replace(" ","0"),HexaDecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->fragmentsList->setItem(i, 1, newItem);

        newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("%1").arg(p_srec->getFragmentSize(i)),DecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->fragmentsList->setItem(i, 2, newItem);

        newItem = new QTableWidgetItem(p_srec->getFragmentHeader(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->fragmentsList->setItem(i, 3, newItem);

    }
    this->ui->fragmentsList->resizeColumnsToContents();
}

void srecFileWidget::recordCellActivated(int row, int column)
{
    Q_UNUSED(column)
    char* buff=NULL;
    int index = this->ui->fragmentsList->item(row,0)->text().toInt();
    if(index!=-1)
    {
        this->p_srec->getFragmentData(index,&buff);
        this->ui->fragmentHexView->setData(QByteArray(buff,this->p_srec->getFragmentSize(index)));
    }

}


