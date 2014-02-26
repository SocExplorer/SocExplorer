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
#ifndef SOCEXPLORERENUMDEVICE_H
#define SOCEXPLORERENUMDEVICE_H

#include <QObject>
#include <stdint.h>
#include <socexplorerplugin.h>
#include <socmodel.h>

class SOCEXPLORER_EXPORT socExplorerEnumDevice : public QObject
{
    Q_OBJECT
public:
    explicit socExplorerEnumDevice(SOCModel* soc,int VID,int PID,qint32 baseAddress,const QString& name,QObject *parent = 0);
    qint32 baseAddress(){return _baseAddress;}
    int VID(){return _VID;}
    int PID(){return _PID;}
    QString name(){return *_devName;}
    bool visible(){return _visible;}
    void setVisible(bool visible){_visible=visible;}
signals:

public slots:
    void writeReg(qint32 address,qint32 value);
    qint32 readReg(qint32 address);
private:
    bool _visible;
    qint32 _baseAddress;
    int _VID;
    int _PID;
    QString* _devName;
    SOCModel* _SOC;
    
};

#endif // SOCEXPLORERENUMDEVICE_H
