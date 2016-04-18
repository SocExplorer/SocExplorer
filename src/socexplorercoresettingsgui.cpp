#include "socexplorercoresettingsgui.h"
#include "ui_socexplorercoresettingsgui.h"
#include <socexplorersettings.h>
#include <socexplorerengine.h>
#include <socexplorerconfigkeys.h>

SocExplorerCoreSettingsGUI::SocExplorerCoreSettingsGUI(QWidget *parent) :
    SocExplorerSettingsItem(parent),
    ui(new Ui::SocExplorerCoreSettingsGUI)
{
    ui->setupUi(this);
    this->ui->PluginsLookupPath->setText(SocExplorerSettings::value(SOCEXPLORERENGINE_SETTINGS_SCOPE,SOCEXPLORERENGINE_SETTINGS_PLUGINS_LOOKUP_PATH,"").toString());
    this->ui->SOCregsLookupPath->setText(SocExplorerSettings::value(SOCEXPLORERENGINE_SETTINGS_SCOPE,SOCEXPLORERENGINE_SETTINGS_SOC_REGS_LOOKUP_PATH,"").toString());
}

SocExplorerCoreSettingsGUI::~SocExplorerCoreSettingsGUI()
{
    delete ui;
}

void SocExplorerCoreSettingsGUI::changeEvent(QEvent *e)
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

void SocExplorerCoreSettingsGUI::accept()
{
    SocExplorerSettings::setValue(SOCEXPLORERENGINE_SETTINGS_SCOPE,SOCEXPLORERENGINE_SETTINGS_PLUGINS_LOOKUP_PATH,this->ui->PluginsLookupPath->text());
    SocExplorerSettings::setValue(SOCEXPLORERENGINE_SETTINGS_SCOPE,SOCEXPLORERENGINE_SETTINGS_SOC_REGS_LOOKUP_PATH,this->ui->SOCregsLookupPath->text());
}
