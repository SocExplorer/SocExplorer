/*------------------------------------------------------------------------------
--  This file is a part of the LPPMON Software
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
#include "registermodel.h"

registerModel::registerModel(QObject *parent)
    : QObject(parent)
{
    this->SOC = new ucSystemOnChip(this);
}

int registerModel::fromXml(QDomElement *element)
{
    this->currentElement=element;
    this->reload();
    return 1;
}

void registerModel::reload()
{
    if(this->currentElement && !this->currentElement->isNull())
    {
        QDomElement regXml;
        QDomElement bfieldXml;
        QString regName;
        QString bfieldName;
        int bfieldSize;
        QString bfieldDesc;
        //this->clrregs();
        if(!QString::compare(this->currentElement->tagName(),QString("peripherial")))
        {
            /* Get SOC Name */
            this->SOC->setName(this->currentElement->attribute("name","name"));
            this->setTitle(*this->Name);
            /* Get register list */
            regXml=this->currentElement->firstChildElement("register");
            while(!regXml.isNull())
            {
                regName.clear();
                regName.append(regXml.attribute("name","name"));
                bfieldXml=regXml.firstChildElement("bitField");
                bfields= new QList<bitField*>;
                while(!bfieldXml.isNull())
                {
                    bfieldName.clear();
                    bfieldName.append(bfieldXml.attribute("name","name"));
                    bfieldDesc.clear();
                    bfieldDesc.append(bfieldXml.attribute("desc","desc"));
                    bfieldSize = bfieldXml.attribute("size","1").toInt();
                    bfieldMode = (bitField::AccessMode)bfieldXml.attribute("mode","0").toInt();
                    bfieldXml=bfieldXml.nextSiblingElement("bitField");
                    bfield=new bitField(bfieldSize,bfieldName,bfieldDesc,bfieldMode);
                    bfields->append(bfield);
                }
                reg=new registerWdgt(*bfields,regXml.attribute("addOffset","0").toInt(),regName);
                addreg(reg);
                regXml=regXml.nextSiblingElement("register");
            }
        }
    }
}


















