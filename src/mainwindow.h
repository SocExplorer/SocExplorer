/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2011, Plasma Physics Laboratory - CNRS
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QVBoxLayout>
#include <QIcon>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDockWidget>
#include <QTranslator>
#include <QSplitter>
#include "dockablepluginmanager.h"
#include <socexplorerproxy.h>
#include "PyWdgt/pythonconsole.h"
#include "aboutsocexplorer.h"
#include "toolbar.h"
#include "regsExplorer/regsexplorer.h"
#include "socexplorergui.h"

class SocExplorerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SocExplorerMainWindow(QString ScriptToEval,QWidget *parent = 0);
    ~SocExplorerMainWindow();
    QAction* Quit,*LoadPlugin,*ManagePlugins,*help,*regsManager,*exploreRegs,*about,*translateAction;
    QActionGroup*langActionGrp;
    QMenu* FileMenu,*SettingsMenu,*PluginsMenu,*ToolsMenu,*langMenu,*helpMenu,*SessionsMenu;
    QTranslator* appTranslator;
    void createLangMenu();
    void closeEvent(QCloseEvent *event);
    toolBar* toolpane;


public slots:
    void launchPluginManager();
    void addPluginInterface(QDockWidget* plugin);
    void removePluginInterface(QDockWidget* plugin);
    void clearMenu();
    void updateText();
    void setLangage(QAction* action);
    void showAboutBox();
    void pluginselected(const QString& instanceName);

signals:
    void translateSig();
    void registerObject(QObject* object,const QString& instanceName);

private:
    void makeObjects(QString ScriptToEval);
    void makeLayout();
    void makeConnections();
    void makeMenu();
    void loadSessions();
    QMainWindow* pluginsDockContainer;
    QSplitter* mainWidget;
    PythonConsole* PythonConsoleInst;
    dockablePluginManager* pluginManager;
    RegsExplorer* regExplorer;
    aboutsocexplorer* p_about;
    QList<QDockWidget*>* p_pluginGUIlist;
    QStringList p_Sessions;
};

#endif // MAINWINDOW_H
