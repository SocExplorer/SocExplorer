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
#ifndef XMLFILE_H
#define XMLFILE_H

#include <QObject>
#include <QDomDocument>
#include <QDomElement>
#include <QString>

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//! Stores a cached Xml file and expose synchronization functions (Slots).
class xmlfile : public QObject
{
    Q_OBJECT
public:
    xmlfile(const QString& fileName);
    //! Return the root xml element of the current file.
    QDomElement* getRootElement(){return &m_rootElement;}
    //! Return the current file name.
    QString fileName(){return this->m_fileName;}
    //! Return the root xml element tag name of the current file.
    QString rootTagName()
    {
        if(!this->m_rootElement.isNull())
            return this->m_rootElement.tagName();
        else
            return QString("");
    }
public slots:
    void save();
    void reload();
    void addElement(QDomElement* parentElement, const QString& tagName);
    void removeElement(QDomElement* parentElement, QDomElement* element);
private:
    QString m_fileName;
    QDomDocument* m_document;
    QDomElement m_rootElement;
};
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


#endif // XMLFILE_H
