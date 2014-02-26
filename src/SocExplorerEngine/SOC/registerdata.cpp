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
#include "registerdata.h"





ucSystemOnChip::ucSystemOnChip(QObject *parent)
    :QObject(parent),QList<ucPeripheral*>()
{

}


ucPeripheral::ucPeripheral(QObject *parent)
    :QObject(parent),QList<ucRegister*>()
{

}



ucRegister::ucRegister(QObject *parent)
    :QObject(parent)
{

}

quint32 ucRegister::value()
{
    return this->p_value;
}

void ucRegister::setName(const QString &name)
{
    this->p_name = name;
    emit nameChanged(this->p_name);
}

void ucRegister::setValue(quint32 value)
{
    this->p_value = value;
    emit valueChanged(this->p_value);
}

void ucRegister::setOffset(qint64 offset)
{
    this->p_addressOffset = offset;
    emit offsetChanged(this->p_addressOffset);
}

void ucSystemOnChip::setName(const QString &name)
{
    this->p_name = name;
    emit nameChanged(this->p_name);
}
















