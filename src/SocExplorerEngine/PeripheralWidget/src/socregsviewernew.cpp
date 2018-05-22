#include "socregsviewernew.h"
#include "ui_socregsviewernew.h"

SocRegsViewerNew::SocRegsViewerNew(const QString &name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocRegsViewerNew)
{
    ui->setupUi(this);
    this->ui->socName->setText(name);
}

SocRegsViewerNew::SocRegsViewerNew(QWidget *parent):
    QWidget(parent),
    ui(new Ui::SocRegsViewerNew)
{
    ui->setupUi(this);
    this->ui->socName->setText("No name");
}

SocRegsViewerNew::~SocRegsViewerNew()
{
    delete ui;
}

peripheralWidget *SocRegsViewerNew::peripheral(int index)
{
    if(index>=0 && index<p_peripherals.count())
    {
        return p_peripherals.at(index);
    }
    return NULL;
}

void SocRegsViewerNew::addPeripheral(peripheralWidget *peripheral)
{
    if(peripheral!=NULL)
    {
        CollapsablePeripheralWidget* cperiph = new CollapsablePeripheralWidget(peripheral);
        cperiph->setPeripheralWidget(peripheral);
        p_peripherals.append(peripheral);
        p_CPeripherals.append(cperiph);
        this->ui->scrollAreaWidgetContents->layout()->addWidget(cperiph);
        connect(cperiph,SIGNAL(clicked(peripheralWidget*)),this,SLOT(periphClicked(peripheralWidget*)));
        connect(cperiph,SIGNAL(upSig(peripheralWidget*,int)),this,SLOT(periphUp(peripheralWidget*,int)));
        connect(cperiph,SIGNAL(downSig(peripheralWidget*,int)),this,SLOT(periphDown(peripheralWidget*,int)));
    }
}

void SocRegsViewerNew::periphClicked(peripheralWidget *sender)
{
    peripheralWidget * item;
    if(sender!=NULL)
    {
        for(int i=0;i<p_peripherals.count();i++)
        {
            item = p_peripherals.at(i);
            if(item!=sender)
            {
                item->leave();
            }
        }
    }
}

void SocRegsViewerNew::periphUp(peripheralWidget *sender, int cursorIndex)
{
    int index,senderIndex;
    if(sender!=NULL)
    {
        index =senderIndex= p_peripherals.indexOf(sender);
        while(index!=-1 && index!=0)
        {
            if(p_peripherals.at(index-1)->count()>0)
            {
                p_peripherals.at(senderIndex)->leave();
                p_peripherals.at(index-1)->enter(cursorIndex,false);
                //                ensureWidgetVisible(p_peripherals.at(index-1));
                break;
            }
            index--;
        }
    }
}

void SocRegsViewerNew::periphDown(peripheralWidget *sender, int cursorIndex)
{
    int index,senderIndex;
    if(sender!=NULL)
    {
        index=senderIndex= p_peripherals.indexOf(sender);
        while((index!=-1) && (index<(p_peripherals.count()-1)))
        {
            if(p_peripherals.at(index+1)->count()>0)
            {
                p_peripherals.at(senderIndex)->leave();
                p_peripherals.at(index+1)->enter(cursorIndex);
                //                ensureWidgetVisible(p_peripherals.at(index+1));
                break;
            }
            index++;
        }
    }
}

void SocRegsViewerNew::setSocName(const QString &name)
{
    this->ui->socName->setText(name);
}

void SocRegsViewerNew::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
