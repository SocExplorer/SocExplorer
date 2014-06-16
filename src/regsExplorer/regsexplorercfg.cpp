#include "regsexplorercfg.h"
#include <socexplorerengine.h>
#include <peripheralwidget.h>

regsExplorerCfg::regsExplorerCfg(QWidget *parent) :
    QWidget(parent)
{
    this->mainLayout = new QGridLayout;
    this->setLayout(this->mainLayout);
    this->regsList = new QList<QCheckBox*>();
}

QCheckBox *regsExplorerCfg::addDev(socExplorerEnumDevice *device)
{
    QCheckBox* chkbx = new QCheckBox(device->name() + QString(" @0x%1").arg((uint)device->baseAddress(),8,16));
    this->regsList->append(chkbx);
    this->mainLayout->addWidget(this->regsList->last());
    return chkbx;
}

void regsExplorerCfg::updateRegList()
{
    this->clear();
    QCheckBox* tmp;
    QList<SOCModel*>* socs = SocExplorerEngine::getSOCs();
//    for(int i=0;i<->count();i++)
//    {
//        tmp = new QCheckBox(devs->at(i)->name());
//        this->regsList->append(tmp);
//        this->mainLayout->addWidget(tmp);
//    }
}



void regsExplorerCfg::clear()
{
    QCheckBox* tmp;
    for(int i=0;i<this->regsList->count();i++)
    {
        this->mainLayout->removeWidget(this->regsList->last());
        tmp = this->regsList->last();
        this->regsList->removeLast();
        delete tmp;
    }
}









