#include "binaryfilewidget.h"
#include "ui_binaryfilewidget.h"
#include "qtablewidgetintitem.h"
#include <QtWidgets/QTableWidget>

binaryFileWidget::binaryFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::binaryFileWidget)
{
    ui->setupUi(this);
    connect(this->ui->fragmentList,SIGNAL(cellActivated(int,int)),this,SLOT(fragmentCellActivated(int,int)));
    connect(this->ui->fragmentList,SIGNAL(cellChanged(int,int)),this,SLOT(fragmentCellChanged(int,int)));
}

binaryFileWidget::~binaryFileWidget()
{
    delete ui;
}

void binaryFileWidget::updateBinaryFile(binaryFile *file)
{
    this->p_binfile = file;
    if(p_binfile->isopened())
    {
        updateFragments();
    }
}

void binaryFileWidget::updateFragments()
{
    this->ui->fragmentList->clear();
    this->ui->fragmentList->setRowCount(p_binfile->getFragmentsCount());
    this->ui->fragmentList->setHorizontalHeaderLabels(QStringList()<<"File"<<"Size"<<"Address");
    for(int i=0;i<p_binfile->getFragmentsCount();i++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(p_binfile->getFragmentHeader(i));
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->fragmentList->setItem(i, 0, newItem);

        newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("%1").arg(p_binfile->getFragmentSize(i)),DecimalItem);
        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->fragmentList->setItem(i, 1, newItem);

        newItem = (QTableWidgetItem*)new QTableWidgetIntItem(QString("0x%1").arg(p_binfile->getFragmentAddress(i),8,16).replace(" ","0"),HexaDecimalItem);
//        newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
        this->ui->fragmentList->setItem(i, 2, newItem);

    }
    this->ui->fragmentList->resizeColumnsToContents();
}

void binaryFileWidget::fragmentCellActivated(int row, int column)
{
    Q_UNUSED(column)
    char* buff=NULL;
    int index = this->ui->fragmentList->item(row,0)->text().toInt();
    if(index!=-1)
    {
        this->p_binfile->getFragmentData(index,&buff);
        this->ui->hexViewer->setData(QByteArray(buff,this->p_binfile->getFragmentSize(index)));
        this->ui->hexViewer->setAddressOffset(this->p_binfile->getFragmentAddress(index));
    }
}

void binaryFileWidget::fragmentCellChanged(int row, int column)
{
    if(column==2)
    {
        QString newAddressStr = this->ui->fragmentList->item(row,column)->text();
        int newAddress = 0;
        newAddressStr.remove(" ");
        if(newAddressStr.at(0)=='0' && newAddressStr.at(1)=='x')
        {
            newAddress = newAddressStr.remove("0x").toUInt(0,16);
        }
        else
        {
            newAddress = newAddressStr.toUInt();
        }
        this->p_binfile->getFragments().at(row)->address = newAddress;
    }
}
