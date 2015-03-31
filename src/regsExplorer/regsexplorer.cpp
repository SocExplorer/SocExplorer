#include "regsexplorer.h"
#include "socmodel.h"

regsExplorer::regsExplorer(QWidget *parent) :
    QDockWidget(parent)
{
    mainWidget = new QTabWidget;
    cfg = new regsExplorerCfg;
    socViewer = new SocRegsViewerNew(tr("No soc Detected"),this);
    this->setWidget(this->mainWidget);
    this->mainWidget->addTab(this->cfg,"Config");
    this->mainWidget->addTab(this->socViewer,"View");
    this->setWindowTitle(tr("Regs Explorer"));
    connect(SocExplorerEngine::self(),SIGNAL(enumDeviceAdded(socExplorerEnumDevice*)),this,SLOT(addDev(socExplorerEnumDevice*)));
}


void regsExplorer::addDev(socExplorerEnumDevice *device)
{
    delegate.device = device;
    peripheralWidget* peripheral=new peripheralWidget(device->name(),device->baseAddress(),&delegate,this);
    this->socViewer->addPeripheral(peripheral);
    peripheralModel periphM=SocExplorerEngine::xmlModel()->getPeripheral(device->name());
    int startIndex,stopIndex;
    QString desc;
    QString name;
    bool rw;
    for(int i=0;i<periphM.registers.count();i++)
    {
        peripheral->addRegister(periphM.registers.at(i).name,device->baseAddress() + periphM.registers.at(i).offset);
        for(int j=0;j<periphM.registers.at(i).bitfields.count();j++)
        {
            startIndex = periphM.registers.at(i).bitfields.at(j).offset;
            stopIndex = periphM.registers.at(i).bitfields.at(j).offset+periphM.registers.at(i).bitfields.at(j).size-1;
            desc = periphM.registers.at(i).bitfields.at(j).description;
            rw = periphM.registers.at(i).bitfields.at(j).rw;
            name = periphM.registers.at(i).bitfields.at(j).name;
            peripheral->registerAt(i)->setBitFieldAttribute(startIndex,stopIndex,name,desc,rw);
        }
    }
//    connect(peripheral,SIGNAL(readRegSig(qint32)),device,SLOT(readReg(qint32)));
//    connect(peripheral,SIGNAL(writeRegSig(qint32,qint32)),device,SLOT(writeReg(qint32,qint32)));
//    QCheckBox* chkbx = this->cfg->addDev(device);
//    chkbx->setChecked(true);
//    connect(chkbx,SIGNAL(toggled(bool)),peripheral,SLOT(setVisible(bool)));
}




