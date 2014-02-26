/*------------------------------------------------------------------------------
--  This file is a part of the LPPMON Software
--  Copyright (C) 2013, Laboratory of Plasmas Physic - CNRS
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

#ifndef REGISTERSMODEL_H
#define REGISTERSMODEL_H
#include <QString>
#include <QList>
#include <QObject>
#include <QDomDocument>
#include <QDomElement>
#include "registerdata.h"


class registerModel : QObject
{
    Q_OBJECT
public:
    registerModel(QObject* parent=0);

    QDomElement toXml(QDomDocument* doc);

public slots:
    int fromXml(QDomElement* element);
    void reload();
private:
    ucSystemOnChip* SOC;
    QDomElement* currentElement;

};


#endif // REGISTERSMODEL_H







