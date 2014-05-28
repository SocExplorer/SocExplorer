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
/*--                  Author :
        Alexis Jeandet
--                     Mail :
        alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/
#include "elffile.h"

ElfFile::ElfFile(QObject *parent)
    :QObject(parent),abstractExecFile(),elfparser()
{
}

ElfFile::ElfFile(const QString &File, QObject *parent)
    :QObject(parent),abstractExecFile(),elfparser()
{
    this->p_fileName = File;
    setFilename(File);
}

bool ElfFile::openFile(const QString &File)
{
    this->p_fileName = File;
    return setFilename(File);
}

bool ElfFile::isopened()
{
    return elfparser::isopened();
}

int ElfFile::closeFile()
{
    return elfparser::closeFile();
}


QList<codeFragment> ElfFile::getFragments(QStringList fragmentList)
{
    QList<codeFragment> fragments;
    if (isopened())
    {
        for(int i =0;i<fragmentList.count();i++)
        {
            fragments.append(getFragment(fragmentList.at(i)));
        }
    }
    return fragments;
}

QList<codeFragment> ElfFile::getFragments()
{
    return getFragments(QStringList()<<".data"<<".text");
}

codeFragment ElfFile::getFragment(const QString &name)
{
    codeFragment fragment;
    for(int i=0;i<getSectioncount();i++)
    {
        if(getSectionName(i) == name)
        {
            fragment.data =NULL;
            fragment.size = getSectionDatasz(i);
            fragment.address = getSectionPaddr(i);
            getSectionData(i,&fragment.data);
        }
    }

}














