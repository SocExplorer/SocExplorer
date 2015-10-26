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

void usage();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString scriptToEval;
    QStringList args= a.arguments();
    bool noGUI=false;
    for(int i=0;i<=args.count()-1;i++)
    {
        if(((args.at(i).compare("-e")==0) || (args.at(i).compare("--execute")==0)) && (i<(args.count()-1)))
        {
            scriptToEval = args.at(i+1);
            if(!QFile::exists(scriptToEval))
            {
                scriptToEval.clear();
            }
            else
                qDebug() << "Will execute" << scriptToEval;
            break;
        }
        if(((args.at(i).compare("-d")==0) || (args.at(i).compare("--debug-level")==0)) && (i<(args.count()-1)))
        {
            bool success;
            int lvl;
            lvl = args.at(i+1).toInt(&success,10);
            if(success)
            {
                SocExplorerEngine::setLogLevel(lvl);
            }
        }
        if((args.at(i).compare("--no-gui")==0))
        {
            noGUI = true;
            qDebug() << "CLI mode";
        }
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


void usage()
{
    // TODO respect usual Linux Cli interface, socexplore [OPTION]...FILES...
    // TODO write an usage helper.
}
