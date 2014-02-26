/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2012, Laboratory of Plasmas Physic - CNRS
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
#include "socexplorerenumdevice.h"

socExplorerEnumDevice::socExplorerEnumDevice(SOCModel* soc, int VID, int PID, qint32 baseAddress, const QString &name, QObject *parent)
    :QObject(parent)
{
    _VID=VID;
    _PID=PID;
    _baseAddress=baseAddress;
    _devName=new QString(name);
    _visible=true;
    _SOC = soc;
}

void socExplorerEnumDevice::writeReg(qint32 address, qint32 value)
{
    _SOC->writeReg(address,value);
}

qint32 socExplorerEnumDevice::readReg(qint32 address)
{
    return _SOC->readReg(address);
}
