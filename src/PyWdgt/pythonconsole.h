/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2011, Laboratory of Plasmas Physic - CNRS
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
#ifndef PYTHONCONSOLE_H
#define PYTHONCONSOLE_H

#include <QWidget>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QtGui/QDragEnterEvent>
#include <QtGui/QDragLeaveEvent>
#include <QtGui/QDragMoveEvent>
#include <QtGui/QDropEvent>
#include <QtCore/QMimeData>
#include <QtCore/QUrl>
#include <QtCore/QList>
#include "PythonQt.h"
#include "PythonQt_QtAll.h"
#include <gui/PythonQtScriptingConsole.h>
#include "../plugins/socexplorerplugin.h"
#include "pythonqtscriptingconsoledandd.h"
#include <QMainWindow>
#include "../proxy/socexplorerproxy.h"
class LPMONMainWindow;
class PythonConsole : public QWidget
{
    Q_OBJECT
public:
    explicit PythonConsole(socexplorerproxy* proxy,QWidget *parent = 0);

signals:
    void rootDriverDelete();
public slots:
    void setBussDriver(socexplorerplugin* driver);
    void removeBussDriver();
    void removeDriver(const QString& instanceName);
    void pyConsoleRunFiles(const QStringList&);
    void pyConsoleRunFile(const QString& fileName);
    void registerObject(QObject* object,const QString& instanceName);
    void changeSysDriverInstName(const QString newinstanceName,const QString previnstanceName);
    void addObject(const QString& name, QObject* object);
protected:
    QSize sizeHint();

private:
    QHBoxLayout* mainlayout;
    socexplorerplugin* bussdriver;
    PythonQtScriptingConsoleDandD* console;
    PythonQtObjectPtr*  mainContext;
    socexplorerproxy* proxy;
    //LPMONMainWindow* mainwin;
};

#endif // PYTHONCONSOLE_H
