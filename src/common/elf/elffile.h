/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Plasma Physics Laboratory - CNRS
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
--                     Mail : alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/
#include <abstractexecfile.h>
#include <elf.h>
#include "elfparser.h"
#include <QStringList>

#ifndef ELFFILE_H
#define ELFFILE_H

class ElfFile :public QObject, public abstractExecFile, public elfparser
{
    Q_OBJECT
public:
    ElfFile(QObject *parent = 0);
    ElfFile(const QString& File,QObject *parent = 0);
    bool openFile(const QString& File);
    bool isopened();
    int closeFile();
    QList<codeFragment> getFragments();
    QList<codeFragment> getFragments(QStringList fragmentList);
//    elfparser parser;

signals:

public slots:
private:
    codeFragment getFragment(const QString& name);

};

#endif // ELFFILE_H
