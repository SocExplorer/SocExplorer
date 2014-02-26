#include "dockablepluginmanager.h"

dockablePluginManager::dockablePluginManager(QWidget *parent) :
    QDockWidget(parent)
{
    this->managerGui = new pluginmanagerWDGT;
    connect(this->managerGui,SIGNAL(loadSysDrviver(QString)),this,SIGNAL(loadSysDrviver(QString)));
    connect(this->managerGui,SIGNAL(loadSysDriverToParent(QString,QString)),this,SIGNAL(loadSysDriverToParent(QString,QString)));
    connect(this->managerGui,SIGNAL(geteplugintree()),this,SIGNAL(geteplugintree()));
    connect(this,SIGNAL(treeChanged(QList<socexplorerplugin*>)),this->managerGui,SIGNAL(treeChanged(QList<socexplorerplugin*>)));
    connect(this->managerGui,SIGNAL(changeSysDriverInstName(QString,QString)),this,SIGNAL(changeSysDriverInstName(QString,QString)));
    connect(this->managerGui,SIGNAL(closeSysDriver(QString)),this,SIGNAL(closeSysDriver(QString)));
    this->setWidget(this->managerGui);
    this->setWindowTitle(this->managerGui->windowTitle());
}



void dockablePluginManager::setRootLoadable(bool flag)
{
    this->managerGui->setRootLoadable(flag);
}
