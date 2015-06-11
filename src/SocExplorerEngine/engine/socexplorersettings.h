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
#ifndef SOCEXPLORERSETTINGS_H
#define SOCEXPLORERSETTINGS_H

#include <QObject>
#include <QWidget>
#include <QSettings>
#include <socexplorersettingsdialog.h>

class SocExplorerSettings : public QObject
{
    Q_OBJECT
private:
    static SocExplorerSettings* _self;
    static QSettings* m_settings;
    static QSettings* m_sessionSettings;
    static SocExplorerSettingsDialog* m_configDialog;
    SocExplorerSettings(QObject *parent = 0);
    ~SocExplorerSettings();
public:
    enum SettingScope {
        SystemWide = 0,
        Session
    };
    static void init();
    static SocExplorerSettings* self(){ if(!_self){_self= new SocExplorerSettings;}return _self;}
    static void	setValue(QObject* object,const QString & key, const QVariant & value,SettingScope Sscope =SystemWide);
    static QVariant	value(QObject* object, const QString & key, const QVariant & defaultValue = QVariant(),SettingScope Sscope=SystemWide);
    static void	setValue(const QString scope,const QString & key, const QVariant & value,SettingScope Sscope= SystemWide);
    static QVariant	value(const QString scope, const QString & key, const QVariant & defaultValue = QVariant(),SettingScope Sscope =SystemWide);
    static QList<QList<QVariant> > arrays(const QString & prefix, QStringList keys,SettingScope Sscope =SystemWide);
    static void setArrays(const QString & prefix, QStringList keys,QList<QList<QVariant> > values,SettingScope Sscope =SystemWide);
    static void sync();
    static bool registerConfigEntry(SocExplorerSettingsItem* configEntry,QIcon icon, QString text);
    //! Loads the given session, or sreate it if doesn't exists.
    //! \param session Session name.
    //! \return true if success or false if fails to create session config file.
    static bool loadSession(const QString& session);
    static bool deleteSession();
    static bool deleteSession(const QString& session);
signals:

public slots:
    void popConfigDialog();
private:
    static QList<QList<QVariant> > arrays(const QString & prefix, QStringList keys,QSettings* settings);
    static void setArrays(const QString & prefix, QStringList keys,QList<QList<QVariant> > values,QSettings* settings);
};

#endif // SOCEXPLORERSETTINGS_H
