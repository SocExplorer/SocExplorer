/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2012, Plasma Physics Laboratory - CNRS
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
#ifndef PLUGINSCACHE_H
#define PLUGINSCACHE_H

#include <QObject>
#include <QString>
#include <QList>
//#include <QtXml>
#include <QTableWidget>

class PluginsCacheItem
{
public:
    PluginsCacheItem(const QString& fileName,const QString& path,const QString& pluginName,int VID,int PID);
    ~PluginsCacheItem(){delete fileName;delete path;delete pluginName;}
    bool compare(PluginsCacheItem* item);
    bool comparePluginName(const QString& pluginName);
    bool comparefileName(const QString& fileName);
    bool comparefilePath(const QString& filePath);
    bool compareIDs(int VID,int PID);
    QString getpath(){return QString(*path);}
    QString getfileName(){return QString(*fileName);}
    QString getpluginName(){return QString(*pluginName);}
    int getVID(){return this->VID;}
    int getPID(){return this->PID;}
private:
    QString* fileName;
    QString* path;
    QString* pluginName;
    int VID;
    int PID;
};

class PluginsCache : public QObject
{
    Q_OBJECT
public:
    explicit PluginsCache(QObject *parent = 0);
    void append(const QString& fileName,const QString& path,const QString& pluginName,int VID,int PID);
    QString first(const QString& pluginName);
    QString first(int VID,int PID);
    QStringList findDriver(int VID,int PID);
    QList<PluginsCacheItem*> listDrivers();
    void flush();
public slots:
    void show();
private:
    QList<PluginsCacheItem*>* items;
    QTableWidget* __view;

};

#endif // PLUGINSCACHE_H
