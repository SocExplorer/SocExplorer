/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Plasma Physics Laboratory - CNRS
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
--                     Mail : alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/

#include "socclk.h"



SOCclk::SOCclk(const QString &name, qint64 value, qint64 divisor, qint64 multiplier)
{
    this->p_Name = name;
    this->p_Value = value;
    this->p_parentClk = NULL;
    this->p_Multiplier= multiplier;
    this->p_Divisor = divisor;
}

void SOCclk::appendChild(SOCclk *child)
{
    this->p_childrenClk.append(child);
    child->setParentClk(this);
}

void SOCclk::setParentClk(SOCclk *parent)
{
    p_parentClk = parent;
}

SOCclk *SOCclk::getClk(const QString &name)
{
    SOCclk* clk=NULL;
    if(this->p_Name==name)return this;
    for(int i=0;i<=p_childrenClk.count();i++)
    {
        clk =p_childrenClk.at(i)->getClk(name);
        if(clk!=NULL)break;
    }
    return clk;
}

qint64 SOCclk::Value()
{
    if(p_parentClk==NULL)
        return p_Value;
    return p_parentClk->Value()*p_Multiplier/p_Divisor;
}

void SOCclk::setValue(qint64 value)
{
    this->p_Value = value;
}

qint64 SOCclk::Divisor()
{
    return p_Divisor;
}

void SOCclk::setDivisor(qint64 divisor)
{
    p_Divisor = divisor;
}

qint64 SOCclk::Multiplier()
{
    return p_Multiplier;
}

void SOCclk::setMultiplier(qint64 multiplier)
{
    p_Multiplier = multiplier;
}

QString SOCclk::Name()
{
    return p_Name;
}

void SOCclk::setName(const QString &name)
{
    this->p_Name = name;
}
