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
#ifndef PYTHONQTSCRIPTINGCONSOLEDANDD_H
#define PYTHONQTSCRIPTINGCONSOLEDANDD_H
#include "PythonQt.h"
#include "PythonQt_QtAll.h"
#include "gui/PythonQtScriptingConsole.h"
#include "../plugins/socexplorerplugin.h"
#include <QtGui/QDragEnterEvent>
#include <QtGui/QDragLeaveEvent>
#include <QtGui/QDragMoveEvent>
#include <QtGui/QDropEvent>
#include <QtCore/QMimeData>
#include <QtCore/QUrl>
#include <QtCore/QList>
#include "NicePyConsole/NicePyConsole.h"

class PythonQtScriptingConsoleDandD : public NicePyConsole
{
    Q_OBJECT
public:
    PythonQtScriptingConsoleDandD(QWidget* parent, const PythonQtObjectPtr& context, Qt::WindowFlags i = 0);

    //void pyConsoleRunFiles(const QStringList&);
signals:
    void pyConsoleRunFiles(const QStringList&);
protected:
    void dropEvent(QDropEvent * event);
    void dragMoveEvent(QDragMoveEvent *e);
    void dragEnterEvent(QDragEnterEvent *e);
private:

};

#endif // PYTHONQTSCRIPTINGCONSOLEDANDD_H
