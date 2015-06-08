#include "socexplorersettingsdialog.h"
#include "ui_socexplorersettingsdialog.h"

SocExplorerSettingsDialog::SocExplorerSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SocExplorerSettingsDialog)
{
    ui->setupUi(this);
    connect(ui->contentsWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
    ui->contentsWidget->setViewMode(QListView::IconMode);
    ui->contentsWidget->setIconSize(QSize(96, 84));
    ui->contentsWidget->setMovement(QListView::Static);
    ui->contentsWidget->setSpacing(12);
}

SocExplorerSettingsDialog::~SocExplorerSettingsDialog()
{
    delete ui;
}

void SocExplorerSettingsDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;
    ui->pagesWidget->setCurrentIndex(ui->contentsWidget->row(current));
}

bool SocExplorerSettingsDialog::registerConfigEntry(SocExplorerSettingsItem *configEntry, QIcon icon, QString text)
{
    if(configEntry!=NULL)
    {
        ui->pagesWidget->addWidget(configEntry);
        QListWidgetItem *configButton = new QListWidgetItem(ui->contentsWidget);
        configButton->setIcon(icon);
        configButton->setText(text);
        configButton->setTextAlignment(Qt::AlignHCenter);
        configButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        connect(this,SIGNAL(accepted()),configEntry,SLOT(accept()));
        return true;
    }
    return false;
}

void SocExplorerSettingsDialog::popConfigDialog(SocExplorerSettingsItem *selectedConfigEntry)
{
    if(selectedConfigEntry!=NULL)
    {
        for(int i=0;i<ui->pagesWidget->count();i++)
        {
            if(ui->pagesWidget->widget(i)==selectedConfigEntry)
            {
                ui->pagesWidget->setCurrentIndex(i);
            }
        }
    }
    this->show();
}

void SocExplorerSettingsDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
