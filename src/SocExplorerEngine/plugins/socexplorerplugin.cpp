/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Laboratory of Plasmas Physic - CNRS
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

#include <socexplorerplugin.h>


int socexplorerplugin::isConnected(){return this->Connected;}

QString socexplorerplugin::baseName(){return *_Name;}

int socexplorerplugin::baseAddress(){return this->BaseAddress;}

void socexplorerplugin::setBaseAddress(unsigned int baseAddress){this->BaseAddress = baseAddress;}

int socexplorerplugin::registermenu(QMenu *menu)
{
    this->menu = menu->addMenu(this->instanceName);
    this->closeAction = this->menu->addAction(tr("Close plugin"));
    QObject::connect(this->closeAction,SIGNAL(triggered()),this,SLOT(closeMe()));
    this->ChildsMenu = this->menu->addMenu(QString("Childs"));
    for(int i=0;i<this->childs.count();i++)
    {
        this->childs.at(i)->registermenu(this->ChildsMenu);
    }
    if(this->pyObject!=NULL)emit this->registerObject((QObject*)this->pyObject,this->instanceName);
    return 0;
}

void socexplorerplugin::postInstantiationTrigger()
{
    return;
}

unsigned int socexplorerplugin::Write(unsigned int *Value, unsigned int count, unsigned int address)
{
    if(parent!=NULL)
    {
        return parent->Write(Value,count,address);
    }
    return 0;
}

unsigned int socexplorerplugin::Read(unsigned int *Value, unsigned int count, unsigned int address)
{
    if(parent!=NULL)
    {
        return parent->Read(Value,count,address);
    }
    return 0;
}

void socexplorerplugin::closeMe(){emit this->closePlugin(this);}

void socexplorerplugin::activate(bool flag){this->setEnabled(flag);emit this->activateSig(flag);}

void socexplorerplugin::setInstanceName(const QString &newName)
{
    this->instanceName = newName;
    this->menu->setTitle(this->instanceName);
}

void socexplorerplugin::makeGenericPyWrapper()
{
    this->pyObject = new genericPySysdriver(this);
}
