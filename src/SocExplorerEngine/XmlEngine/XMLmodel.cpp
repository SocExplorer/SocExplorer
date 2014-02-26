/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2013, Laboratory of Plasmas Physic - CNRS
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
#include "XMLmodel.h"
#include <socexplorerengine.h>
#include <QFile>
#include <QDebug>

socExplorerXmlModel::socExplorerXmlModel(QObject *parent)
    :QObject(parent)
{
    p_driver = new XMLDriver;
    p_driver->scanXmlFiles();
    this->updateSOClist();
}

int socExplorerXmlModel::checkXmlFile(const QString &fileName)
{
    return p_driver->checkXmlFile(fileName);
}

int socExplorerXmlModel::createXmlFile(const QString &fileName)
{
    return p_driver->createXmlFile(fileName);
}

QList<xmlfile *> socExplorerXmlModel::getFileList(const QString &tagNameFilter)
{
    return p_driver->getFileList(tagNameFilter);
}

QList<QDomNodeList> socExplorerXmlModel::getAllNodes(const QString &tagName)
{
    return p_driver->getAllNodes(tagName);
}

QStringList socExplorerXmlModel::getPeripheralRegList(const QString &peripheralName)
{
    QStringList result;
    QList<QDomNodeList> nodeList = p_driver->getAllNodes("peripheral");
    for(int i=0;i<nodeList.count();i++)
    {
        for(int l=0;l<nodeList.at(i).count();l++)
        {
            if(peripheralName==nodeList.at(i).at(l).toElement().attribute("name","name"))
            {
                QDomNodeList registers=nodeList.at(i).at(l).toElement().elementsByTagName("register");
                for(int m=0;m<registers.count();m++)
                {
                    result.append(registers.at(m).toElement().attribute("name","No name"));
                }
            }
        }
    }
    return result;
}

peripheralModel socExplorerXmlModel::getPeripheral(const QString &peripheralName)
{
    peripheralModel result= peripheralModel(peripheralName);
    QList<QDomNodeList> nodeList = p_driver->getAllNodes("peripheral");
    QDomNodeList filteredPeriph;
    for(int i=0;i<nodeList.count();i++)
    {
        for(int l=0;l<nodeList.at(i).count();l++)
        {
            if(peripheralName==nodeList.at(i).at(l).toElement().attribute("name","name"))
            {
                filteredPeriph = nodeList.at(i).at(l).toElement().elementsByTagName("register");
                p_getRegs(&result,&filteredPeriph);
            }
        }
    }
    return result;
}



void socExplorerXmlModel::updateSOClist()
{
    QString socName;
    this->clearSocList();
    QList<QDomNodeList> nodeList = p_driver->getAllNodes("soc");
    for(int i=0;i<nodeList.count();i++)
    {
        for(int l=0;l<nodeList.at(i).count();l++)
        {
            socName = nodeList.at(i).at(l).toElement().attribute("name","name");
            qDebug()<<"Found SOC " + socName;
        }
    }
}

void socExplorerXmlModel::registerXmlFile(const QString &fileName)
{
    p_driver->registerXmlFile(fileName);
}

void socExplorerXmlModel::scanXmlFiles()
{
    p_driver->scanXmlFiles();
}

void socExplorerXmlModel::p_getRegs(peripheralModel *periph, QDomNodeList *nodes)
{
    QString name;
    QString description;
    int size=0;
    int offset=0;
    bool rw;
    for(int i=0;i<nodes->count();i++)
    {
        periph->registers.append(registerModel(nodes->at(i).toElement().attribute("name","No name"),nodes->at(i).toElement().attribute("addOffset",QString::number(i*4)).toInt()));
        QDomNodeList bitfields=nodes->at(i).toElement().elementsByTagName("bitField");
        for(int l=0;l<bitfields.count();l++)
        {
            name = bitfields.at(l).toElement().attribute("name","No name");
            description = bitfields.at(l).toElement().attribute("desc","");
            offset = bitfields.at(l).toElement().attribute("offset",QString("%1").arg(offset+size)).toInt();
            size = bitfields.at(l).toElement().attribute("size","1").toInt();
            rw = bitfields.at(l).toElement().attribute("mode","1").toInt()==3;
            periph->registers.last().bitfields.append(registerBitFieldModel(name,description,size,offset,rw));
        }
        size = 0;
        offset = 0;
    }
}

void socExplorerXmlModel::clearSocList()
{
    xmlDataSystemOnChip* tmp;
    for(int i=0;i<this->p_SocList.length();i++)
    {
        tmp = this->p_SocList.last();
        this->p_SocList.removeLast();
        delete tmp;
    }
}











