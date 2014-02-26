/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2012, Laboratory of Plasmas Physic - CNRS
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
#include "socexplorerxmlfile.h"
#include <QFile>
#include <QTextStream>

xmlfile::xmlfile(const QString& fileName)
{
    this->m_fileName = fileName;
    this->m_document=new QDomDocument();
    QFile file( fileName );
    if( !file.open( QIODevice::ReadOnly ) )
        return;
    this->m_document->setContent(&file);
    file.close();
    this->m_rootElement = this->m_document->documentElement();
}

void xmlfile::save()
{
    QFile file( this->m_fileName );
    if( !file.open( QIODevice::WriteOnly ) )
        return;
    QTextStream ts( &file );
    ts << this->m_document->toString();
    file.close();
    this->reload();
}

void xmlfile::reload()
{
    QFile file( this->m_fileName );
    if( !file.open( QIODevice::ReadOnly ) )
        return;
    this->m_document->setContent(&file);
    file.close();
    this->m_rootElement = this->m_document->documentElement();
}

void xmlfile::addElement(QDomElement* parentElement, const QString& tagName)
{
    if(m_document)
    {
        QDomElement element=this->m_document->createElement(tagName);
        parentElement->appendChild(element);
        //emit this->elementAdded(element);
    }
}

void xmlfile::removeElement(QDomElement *parentElement, QDomElement *element)
{
    Q_UNUSED(parentElement)
    Q_UNUSED(element)
    if(m_document)
    {

    }
}
