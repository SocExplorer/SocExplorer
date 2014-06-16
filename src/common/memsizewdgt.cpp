#include "memsizewdgt.h"
#include "QStringList"

MemSizeWdgt::MemSizeWdgt(QWidget *parent) :
    QWidget(parent)
{
    this->mainLayout = new QHBoxLayout;
    this->sizeValue = new QLineEdit;
    this->sizeUnit = new QComboBox;
    this->sizeUnit->addItems(QStringList()<<tr("B")<<tr("kB")<<tr("MB")<<tr("GB")<<tr("TB"));
    this->mainLayout->addWidget(this->sizeValue);
    this->mainLayout->addWidget(this->sizeUnit);
    this->setLayout(this->mainLayout);
    connect(this->sizeValue,SIGNAL(returnPressed()),this,SLOT(setSizeValue()));
    this->sizeValue->setText(QString::number(1));
    this->maximum = (unsigned int)-1;
}

MemSizeWdgt::MemSizeWdgt(int defaultSize,QWidget *parent):
    QWidget(parent)
{
    this->mainLayout = new QHBoxLayout;
    this->sizeValue = new QLineEdit;
    this->sizeUnit = new QComboBox;
    this->sizeUnit->addItems(QStringList()<<tr("B")<<tr("kB")<<tr("MB")<<tr("GB")<<tr("TB"));
    this->mainLayout->addWidget(this->sizeValue);
    this->mainLayout->addWidget(this->sizeUnit);
    this->setLayout(this->mainLayout);
    connect(this->sizeValue,SIGNAL(returnPressed()),this,SLOT(setSizeValue()));
    this->sizeValue->setText(QString::number(defaultSize));
    this->setSizeValue();
    this->maximum = (unsigned int)-1;
}

void MemSizeWdgt::setSizeValue(int size)
{
    this->sizeValue->setText(QString::number(size));
}

void MemSizeWdgt::setSizeValue(QString size)
{
    this->sizeValue->setText(size);
    this->setSizeValue();
}

void MemSizeWdgt::updateSizeValue()
{
    this->setSizeValue();
}

void MemSizeWdgt::show()
{
    QWidget::show();
}

void MemSizeWdgt::setSizeValue()
{
    int unit=0;
    double localSize=this->getsize();
    if(localSize>this->maximum)
    {
        localSize = maximum;
    }
    if(localSize<0)
    {
        localSize = 0;
    }
    while(localSize>1024.0)
    {
        localSize=localSize/1024;
        unit++;
    }
    if((unsigned int)this->sizeValue->text().toDouble()!=localSize)
    {
        this->sizeValue->setText(QString::number(localSize));
        this->sizeUnit->setCurrentIndex(unit);
    }
}


int MemSizeWdgt::getsize()
{
    double size = this->sizeValue->text().toDouble();
    int unit=this->sizeUnit->currentIndex();
    while(unit>0)
    {
        size = size*1024;
        unit--;
    }
    return (int)size;
}


void MemSizeWdgt::setMaximum(unsigned int max)
{
    this->maximum = max;
}


