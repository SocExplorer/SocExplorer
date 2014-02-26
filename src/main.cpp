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


int main(int argc, char *argv[])
{
   // Q_INIT_RESOURCE(socexplorer);
#ifdef Q_OS_LINUX
 //   QApplication::setGraphicsSystem("raster");
#endif
    QApplication a(argc, argv);
    QString scriptToEval;
    QStringList args= a.arguments();
    for(int i=0;i<args.count()-1;i++)
    {
        if((args.at(i).compare("&")==0) || (args.at(i).compare("--execute")==0))
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
    }

    LPMONMainWindow w(scriptToEval);
    w.show();
    return a.exec();
}
