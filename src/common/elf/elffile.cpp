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

ElfFile::ElfFile(QObject *parent) :
    abstractExecFile(parent)
{
}

ElfFile::ElfFile(const QString &File, QObject *parent)
    :abstractExecFile(parent)
{
    this->p_fileName = File;
    parser.setFilename(File);
}

bool ElfFile::openFile(const QString &File)
{
    this->p_fileName = File;
    parser.setFilename(File);
}

bool ElfFile::isopened()
{
    return parser.isopened();
}

int ElfFile::closeFile()
{
    return parser.closeFile();
}

QList<codeFragment> ElfFile::getFragments()
{
    QList<codeFragment> fragments;
    if (parser.isopened())
    {
        fragments.append(getFragment(".text"));
        fragments.append(getFragment(".data"));
    }
}

QList<codeFragment> ElfFile::getFragments(QStringList fragmentList)
{
    QList<codeFragment> fragments;
    if (parser.isopened())
    {
        for(int i =0;i<fragmentList.count();i++)
        {
            fragments.append(getFragment(fragmentList.at(i)));
        }
    }
}

codeFragment ElfFile::getFragment(const QString &name)
{
    codeFragment fragment;
    for(int i=0;i<parser.getSectioncount();i++)
    {
        if(parser.getSectionName(i) == name)
        {
            fragment.data =NULL;
            fragment.size = parser.getSectionDatasz(i);
            fragment.address = parser.getSectionPaddr(i);
            parser.getSectionData(i,&fragment.data);
        }
    }

}














