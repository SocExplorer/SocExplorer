/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Plasma Physics Laboratory - CNRS
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 2 of the License, or
--  (at your option) any later version.
--
--  This program is distributed in the hope that it will be useful,
--  but WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--  GNU General Public License for more details.
--
--  You should have received a copy of the GNU General Public License
--  along with this program; if not, write to the Free Software
--  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
-------------------------------------------------------------------------------*/
/*--                  Author : Alexis Jeandet
--                     Mail : alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/
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
    this->setWindowTitle("SocExplorer SREC viewer");
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
        this->ui->fragmentHexView->setAddressOffset(this->p_srec->getFragmentAddress(index));
    }

}


