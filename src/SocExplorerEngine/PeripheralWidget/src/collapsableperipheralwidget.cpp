#include "collapsableperipheralwidget.h"
#include "ui_collapsableperipheralwidget.h"
#include <QCursor>


CollapsablePeripheralWidget::CollapsablePeripheralWidget(peripheralWidget *periph, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollapsablePeripheralWidget)
{
    m_periph=0;
    m_collapsed = true;
    ui->setupUi(this);
    tthidetmr.setSingleShot(true);
    tthidetmr.setInterval(200);
    connect(this->ui->collapseQpb,SIGNAL(clicked()),this,SLOT(collapse()));
    connect(this->ui->periphName,SIGNAL(clicked()),this,SLOT(collapse()));
    connect(this->ui->periphName,SIGNAL(enter()),this,SLOT(showTooltip()));
    connect(this->ui->periphName,SIGNAL(leave()),&this->tthidetmr,SLOT(start()));
    connect(&this->tthidetmr,SIGNAL(timeout()),this,SLOT(hideTooltip()));
    setPeripheralWidget(periph);
}

CollapsablePeripheralWidget::~CollapsablePeripheralWidget()
{
    delete ui;
}

void CollapsablePeripheralWidget::setPeripheralWidget(peripheralWidget *periph)
{
    if(periph)
    {
        this->m_periph = periph;
        this->ui->gridLayout->addWidget(periph,1,0,1,-1);
        this->ui->periphName->setText(periph->name());
        this->m_periph->setVisible(false);
    }
}

peripheralWidget *CollapsablePeripheralWidget::getPeripheralWidget()
{
    return m_periph;
}

void CollapsablePeripheralWidget::changeEvent(QEvent *e)
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

void CollapsablePeripheralWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void CollapsablePeripheralWidget::collapse()
{
    this->m_periph->setVisible(m_collapsed);
    if(this->m_collapsed)
    {
        this->ui->collapseQpb->setIcon(QIcon(":/img/Gnome-list-remove.svg"));
    }
    else
    {
        this->ui->collapseQpb->setIcon(QIcon(":/img/Gnome-list-add.svg"));
    }
    m_collapsed = !m_collapsed;
}

void CollapsablePeripheralWidget::setName(const QString &name)
{
    if(m_periph)
    {
        this->ui->periphName->setText(name);
    }
}

void CollapsablePeripheralWidget::showTooltip()
{
    if(!m_periph->isVisible() && m_collapsed)
    {
        m_periph->show();
    }
}

void CollapsablePeripheralWidget::hideTooltip()
{
    if(m_periph->isVisible() && m_collapsed)
    {
        QRect temprect = this->geometry();
        temprect.moveTo(this->mapToGlobal(mapFromParent(QPoint(this->x(),this->y()))));
        if(temprect.contains(QCursor::pos()))
        {
            this->tthidetmr.start();
        }
        else
        {
            m_periph->hide();
        }
    }
}

