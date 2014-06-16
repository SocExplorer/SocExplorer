/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2013, Plasma Physics Laboratory - CNRS
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
#include "XMLdata.h"

xmlDataBitfield::xmlDataBitfield(QObject *parent)
    :QObject(parent)
{

}

xmlDataBitfield::xmlDataBitfield(const QString& name,int offset,const QString& description,QObject* parent)
{
    Q_UNUSED(name)
    Q_UNUSED(offset)
    Q_UNUSED(offset)
    Q_UNUSED(description)
    Q_UNUSED(parent)
}

QString xmlDataBitfield::name()
{
    return this->p_name;
}

int xmlDataBitfield::offset()
{
    return this->p_offset;
}

QString xmlDataBitfield::description()
{
    return this->p_description;
}


void xmlDataBitfield::setName(const QString &name)
{
    this->p_name = name;
    emit nameChanged(this->p_name);
}

void xmlDataBitfield::setOffset(int offset)
{
    this->p_offset = offset;
    emit offsetChanged(this->p_offset);
}

void xmlDataBitfield::setDescription(const QString &description)
{
    this->p_description = description;
    emit descriptionChanged(this->p_description);
}

xmlDataRegister::xmlDataRegister(QObject *parent)
    :QObject(parent),QList<xmlDataBitfield*>()
{

}

void xmlDataRegister::setName(const QString &name)
{
    this->p_name = name;
    emit nameChanged(this->p_name);
}

void xmlDataRegister::setValue(quint32 value)
{
    this->p_value = value;
    emit valueChanged(this->p_value);
}

void xmlDataRegister::setOffset(qint64 offset)
{
    this->p_addressOffset = offset;
    emit offsetChanged(this->p_addressOffset);
}

xmlDataPeripheral::xmlDataPeripheral(QObject *parent)
    :QObject(parent), QList<xmlDataRegister*>()
{

}

xmlDataSystemOnChip::xmlDataSystemOnChip(QObject *parent)
    :QObject(parent),QList<xmlDataRegister*>()
{

}

void xmlDataSystemOnChip::setName(const QString &name)
{
    this->p_name = name;
    emit nameChanged(this->p_name);
}














