#include "regsexplorer.h"
#include "ui_regsexplorernew.h"
#include "socmodel.h"

RegsExplorer::RegsExplorer(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::RegsExplorerNew)
{
    ui->setupUi(this);
    connect(SocExplorerEngine::self(),SIGNAL(enumDeviceAdded(socExplorerEnumDevice*)),this,SLOT(addDev(socExplorerEnumDevice*)));
    delegate.device=NULL;
}

RegsExplorer::~RegsExplorer()
{
    delete ui;
}

void RegsExplorer::addDev(socExplorerEnumDevice *device)
{
    if((delegate.device->sameSoc(device))||(delegate.device==NULL))
    {
        delegate.device = device;
        peripheralWidget* peripheral=new peripheralWidget(device->name(),device->baseAddress(),&delegate,this);
        this->ui->regsViewer->addPeripheral(peripheral);
        peripheralModel periphM=SocExplorerEngine::xmlModel()->getPeripheral(device->name());
        int startIndex,stopIndex;
        QString desc;
        QString name;
        bool rw;
        this->ui->regsViewer->setSocName(device->socName());
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
    }
}

void RegsExplorer::changeEvent(QEvent *e)
{
    QDockWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
