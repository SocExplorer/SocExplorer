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
#include <QApplication>
#include "mainwindow.h"
#include <PythonQt.h>
#include <PythonQt_QtAll.h>
#include <gui/PythonQtScriptingConsole.h>
#include <socexplorerplugin.h>
#include <QStyle>
#include <QStyleFactory>
#include <QStringList>
#include <QFile>
#include <QCommandLineOption>
#include <QCommandLineParser>


QCommandLineOption executeOption = QCommandLineOption (
            QStringList() << "e" << "execute",
            QCoreApplication::translate("main", "Execute given script <script>."),
            QCoreApplication::translate("main", "script"));

QCommandLineOption debugLevelOption = QCommandLineOption (
            QStringList() << "d" << "debug-level",
            QCoreApplication::translate("main", "Sets debug level to <level>, higher the level is more verbose the application will be."),
            QCoreApplication::translate("main", "level"),
            "1");

QCommandLineOption noGUIOption = QCommandLineOption (
            QStringList() << "n" << "no-gui",
            QCoreApplication::translate("main", "Starts SocExplorer in batch mode[not fully implemented yet!]."));

const char* socexplorerDesc="\
SocExplorer is an open source generic System On Chip testing software/framework.\
 We write this software for the development and the validation of our instrument,\
 the Low Frequency Receiver(LFR) for the Solar Orbiter mission. This instrument is\
 based on an actel FPGA hosting a LEON3FT processor and some peripherals. To make\
 it more collaborative, we use a plugin based system, the main executable is SocExplorer\
 then all the functionality are provided by plugins. Like this everybody can provide\
 his set of plugins to handle a new SOC or just a new peripheral. SocExplorer uses\
 PythonQt to allow user to automate some tasks such as loading some plugins, configuring\
 them and talking with his device. SocExplorer is provided under the terms of the GNU\
 General Public License as published by the Free Software Foundation; either version 2\
 of the License, or (at your option) any later version.";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString scriptToEval;
    QApplication::setOrganizationName("LPP");
    QApplication::setOrganizationDomain("lpp.fr");
    QApplication::setApplicationName("SocExplorer");
    QCommandLineParser parser;
    parser.setApplicationDescription(socexplorerDesc);
    parser.addHelpOption();
    parser.addVersionOption();
    bool noGUI=false;
    parser.addPositionalArgument("file", QCoreApplication::translate("main", "The Python file to execute."));
    parser.addOption(executeOption);
    parser.addOption(debugLevelOption);
    parser.addOption(noGUIOption);
    parser.process(a);
    if(parser.isSet(executeOption))
    {
        scriptToEval = parser.value(executeOption);
        if(!QFile::exists(scriptToEval))
        {
            scriptToEval.clear();
        }
    }
    else
    {
        scriptToEval = parser.positionalArguments().first();
        if(!QFile::exists(scriptToEval))
        {
            scriptToEval.clear();
        }
    }
    if(parser.isSet(debugLevelOption))
    {
        bool success;
        int lvl;
        lvl = parser.value(debugLevelOption).toInt(&success,10);
        if(success)
        {
            SocExplorerEngine::setLogLevel(lvl);
        }
    }
    if(parser.isSet(noGUIOption))
    {
        noGUI = true;
        qDebug() << "CLI mode";
    }
    SocExplorerMainWindow w(scriptToEval);
    if(!noGUI)
    {
        w.show();
    }
    else
    {

    }
    return a.exec();
}
