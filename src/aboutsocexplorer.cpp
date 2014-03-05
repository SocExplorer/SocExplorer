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
#include "aboutsocexplorer.h"

#include <socexplorerengine.h>

aboutsocexplorer::aboutsocexplorer(QWidget *parent) :
    QTextBrowser(parent)
{
    this->setReadOnly(true);
    QString code;
    QFile file;
    code.clear();
    file.setFileName(":/about/about.html");
    this->setAcceptRichText(true);
    file.open(QIODevice::ReadOnly);
    QTextStream filestrm(&file);
    while(!filestrm.atEnd())code.append(filestrm.readLine().replace("$VERSION$",SocExplorerEngine::SocExplorerVersion()).replace("$Branch$",SocExplorerEngine::SocExplorerBranch()).replace("$Changeset$",SocExplorerEngine::SocExplorerChangeset())+"\n");
    this->setHtml(code);
    file.close();
    this->setMinimumSize(400,400);
    connect(this,SIGNAL(anchorClicked(QUrl)),this,SLOT(anchorClicked_slt(QUrl)));
    this->setOpenLinks(false);
}


void aboutsocexplorer::anchorClicked_slt(const QUrl & url)
{
    QDesktopServices::openUrl(url);
}
