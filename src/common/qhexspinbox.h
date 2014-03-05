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
#ifndef QHEXSPINBOX_H
#define QHEXSPINBOX_H

#include <QSpinBox>
#include <QWidget>
#include <QString>
#include <QValidator>

class QHexSpinBox : public QSpinBox
{
Q_OBJECT
public:
    explicit QHexSpinBox(QWidget *parent = 0);
    QString textFromValue ( int value ) const;
    int valueFromText ( const QString & text ) const ;
    QValidator::State validate(QString &input, int &pos) const
    {
        Q_UNUSED(pos)
        bool ok;
        input.toUInt( &ok, 16 );
        if(ok)
            return QValidator::Acceptable;
        else
            return QValidator::Invalid;
    }
    void show();
signals:

public slots:

};


#endif // QHEXSPINBOX_H
