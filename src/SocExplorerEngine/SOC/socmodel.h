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

#ifndef REGISTERSMODEL_H
#define REGISTERSMODEL_H
#include <QString>
#include <QList>
#include <QObject>
#include <QDomDocument>
#include <QDomElement>
#include "registerdata.h"
#include <socclk.h>
#include <socexplorerplugin.h>
class socExplorerEnumDevice;

class registerBitFieldModel
{
public:
    registerBitFieldModel(const QString& name,const QString& description,
                          int size, int offset, bool rw)
    {
        this->name = name;
        this->description = description;
        this->size = size;
        this->offset = offset;
        this->rw = rw;
    }
    QString name;
    QString description;
    int size;
    int offset;
    bool rw;
};

class registerModel
{
public:
    registerModel(const QString& name,qint32 offset)
    {
        this->name = name;
        this->offset = offset;
    }
    QString name;
    qint32 offset;
    QList<registerBitFieldModel> bitfields;
};

class peripheralModel
{
public:
    peripheralModel(const QString& name)
    {
        this->name = name;
    }
    QString name;
    QList<registerModel> registers;
};


class SOCEXPLORER_EXPORT SOCModel :public QObject
{
    Q_OBJECT
public:
    SOCModel(socexplorerplugin* rootDev,QObject* parent=0);
    bool isRootDev(socexplorerplugin* rootDev)
    {
        return rootDev==p_rootDev;
    }
    bool enumDeviceExists(qint32 baseAddress);
    socExplorerEnumDevice *getEnumDevice(qint32 baseAddress);
    const QString& name(){return p_name;}
public slots:
    qint32 getEnumDeviceBaseAddress(int VID,int PID,int count=0);
    qint32 getEnumDeviceCount(int VID,int PID);
    socExplorerEnumDevice* addEnumDevice(int VID, int PID, qint32 baseAddress, const QString& name);
    int addEnumDevice(socExplorerEnumDevice* device);
    void writeReg(qint32 address,qint32 value);
    qint32 readReg(qint32 address);
    bool isLitleEndian();
private:
    QString p_name;
    socexplorerplugin* p_rootDev;
    QList<socExplorerEnumDevice*> p_enumeratedDevices;
    QList<SOCclk*> clktree;
    bool p_litleEndian;
};




#endif // REGISTERSMODEL_H







