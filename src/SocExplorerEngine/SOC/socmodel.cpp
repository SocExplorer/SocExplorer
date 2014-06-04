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
#include "socmodel.h"
#include <socexplorerenumdevice.h>


SOCModel::SOCModel(socexplorerplugin *rootDev, QObject *parent):
    QObject(parent)
{
        p_rootDev = rootDev;
}

qint32 SOCModel::getEnumDeviceBaseAddress(int VID, int PID, int count)
{
    for(int i=0;i<p_enumeratedDevices.count();i++)
    {
        if((p_enumeratedDevices.at(i)->VID()==VID) && (p_enumeratedDevices.at(i)->PID()==PID))
        {
            if(count==0)
            {
                return p_enumeratedDevices.at(i)->baseAddress();
            }
            count--;
        }
    }
    return -1;
}

qint32 SOCModel::getEnumDeviceCount(int VID, int PID)
{
    qint32 count =0;
    for(int i=0;i<p_enumeratedDevices.count();i++)
    {
        if((p_enumeratedDevices.at(i)->VID()==VID) && (p_enumeratedDevices.at(i)->PID()==PID))
        {
            count++;
        }
    }
    return count;
}

socExplorerEnumDevice *SOCModel::addEnumDevice( int VID, int PID, qint32 baseAddress, const QString &name)
{
    if(enumDeviceExists(baseAddress))
        return getEnumDevice(baseAddress);
    socExplorerEnumDevice* device= new socExplorerEnumDevice(this,VID,PID,baseAddress,name);
    p_enumeratedDevices.append(device);
    return device;
}

int SOCModel::addEnumDevice(socExplorerEnumDevice *device)
{
    if(enumDeviceExists(device->baseAddress()))
        return 0;
    p_enumeratedDevices.append(device);
    return 1;
}



bool SOCModel::enumDeviceExists(qint32 baseAddress)
{
    for(int i=0;i<p_enumeratedDevices.count();i++)
    {
        if(p_enumeratedDevices.at(i)->baseAddress()==baseAddress)
            return true;
    }
    return false;
}

socExplorerEnumDevice *SOCModel::getEnumDevice(qint32 baseAddress)
{
    for(int i=0;i<p_enumeratedDevices.count();i++)
    {
        if(p_enumeratedDevices.at(i)->baseAddress()==baseAddress)
            return p_enumeratedDevices.at(i);
    }
    return NULL;
}


void SOCModel::writeReg(qint32 address, qint32 value)
{
    uint valueInt=value,addressInt=address;
    p_rootDev->Write(&valueInt,1,addressInt);
}

qint32 SOCModel::readReg(qint32 address)
{
    uint valueInt=0,addressInt=address;
    p_rootDev->Read(&valueInt,1,addressInt);
    return (qint32)valueInt;
}
