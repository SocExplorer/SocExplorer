/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2011, Laboratory of Plasmas Physic - CNRS
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
--                     Mail : alexis.jeandet@lpp.polytechnique.fr
----------------------------------------------------------------------------*/
#include "pluginmanagerWDGT.h"
#include "pluginloader.h"
#include <QFileDialog>
#include <unistd.h>
#include <qsvgicon.h>
#include <socexplorerengine.h>

#define mkbutton(button,text,image)button = new QPushButton();\
button->setIcon(QSvgIcon(image));\
button->setIconSize(QSize(16,16));\
button->setToolTip(text)



pluginmanagerWDGT::pluginmanagerWDGT(QWidget *parent) :
    QSplitter(parent)
{
    this->setWindowTitle("Plugin Manager");
    this->setOrientation(Qt::Vertical);
    this->pluginListWidgetContainer = new QWidget();
    this->mainlayoutSpliter = new QSplitter;
    this->pluginListLayout = new QVBoxLayout();
    this->mainlayoutSpliter->setOrientation(Qt::Vertical);
    this->treeview = new plugintree();
    this->pluginTable = new PluginList;
    this->ButtonsLayout = new QHBoxLayout();
    this->ButtonsLayout->addStretch();
    this->pluginListLayout->addLayout(this->ButtonsLayout);
    this->addWidget(this->treeview);
    this->pluginListWidgetContainer->setLayout(this->pluginListLayout);
    this->addWidget(this->pluginListWidgetContainer);
    this->pluginListLayout->addWidget(this->pluginTable);
    this->pluginInfos = new pluginInfosWdgt;

    mkbutton(this->addPluginBt,tr("add plugin"),":/images/open.svg");
    mkbutton(this->removePluginBt,tr("remove plugin(s)"),":/images/trash.svg");
    mkbutton(this->refreshPluginListBt,tr("Refresh Plugin(s) list"),":/images/refresh.svg");

    this->ButtonsLayout->addWidget(this->addPluginBt);
    this->ButtonsLayout->addWidget(this->refreshPluginListBt);
    this->ButtonsLayout->addWidget(this->removePluginBt);

    this->addWidget(this->pluginInfos);

    connect(this->treeview,SIGNAL(geteplugintree()),this,SIGNAL(geteplugintree()));
    connect(this,SIGNAL(treeChanged(QList<socexplorerplugin*>)),this->treeview,SLOT(treeChanged(QList<socexplorerplugin*>)));
    connect(this->pluginTable,SIGNAL(currentRowChanged(int)),this,SLOT(libselected(int)));
    connect(this->pluginTable,SIGNAL(itemSelectionChanged(QStringList)),this->pluginInfos,SLOT(updateInfos(QStringList)));
    connect(this->addPluginBt,SIGNAL(clicked()),this,SLOT(addPlugin()));
    connect(this->removePluginBt,SIGNAL(clicked()),this,SLOT(removePlugin()));
    connect(this->pluginTable,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(loadplugin(QListWidgetItem*)));
    connect(this->refreshPluginListBt,SIGNAL(clicked()),this->pluginTable,SLOT(refreshPluginList()));
    connect(this->treeview,SIGNAL(loadSysDriver(QString)),this,SIGNAL(loadSysDrviver(QString)));
    connect(this->treeview,SIGNAL(loadSysDriverToParent(QString,QString)),this,SIGNAL(loadSysDriverToParent(QString,QString)));
    connect(this->treeview,SIGNAL(changeSysDriverInstName(QString,QString)),this,SIGNAL(changeSysDriverInstName(QString,QString)));
    connect(this->treeview,SIGNAL(closeSysDriver(QString)),this,SIGNAL(closeSysDriver(QString)));
    this->rootLoadable = false;
    this->childLoadable = false;
    this->pluginTable->refreshPluginList();
    this->pluginTable->refreshPluginList();
}


void pluginmanagerWDGT::setRootLoadable(bool flag)
{
    this->rootLoadable = flag;
}


void pluginmanagerWDGT::setChildLoadable(bool flag)
{
    this->childLoadable = flag;
}




void pluginmanagerWDGT::addPlugin()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Plugin"), QDir::homePath(), tr("Plugin Files Files (*.dll *.so *.so.*)"));
    if(pluginloader::checklibrary(fileName))
    {
        QFile::copy(fileName,QString(SocExplorerEngine::pluginFolder())+"/"+ fileName.section('/',-1));
    }
    this->pluginTable->refreshPluginList();
}


void pluginmanagerWDGT::removePlugin()
{
    for(int i=0;i<this->pluginTable->selectedItems().count();i++)
    {
        QListWidgetItem* item = this->pluginTable->selectedItems().at(i);
        if(item!=NULL)
        {
            QFile::remove(QString(SocExplorerEngine::pluginFolder())+"/"+item->text());
        }
    }
    this->pluginTable->refreshPluginList();
}



void pluginmanagerWDGT::loadplugin()
{
    for(int i=0;i<this->pluginTable->selectedItems().count();i++)
    {
        QListWidgetItem* item = this->pluginTable->selectedItems().at(i);
        if(item!=NULL)
        {
            QString plugin = QString(SocExplorerEngine::pluginFolder())+"/"+item->text();
            emit this->loadSysDrviver(plugin);
        }
    }
    this->pluginTable->refreshPluginList();
}




