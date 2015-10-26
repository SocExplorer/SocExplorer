/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2013, Plasma Physics Laboratory - CNRS
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
#ifndef REGISTERDATA_H
#define REGISTERDATA_H
#include <QString>
#include <QList>
#include <QObject>

class ucRegister :public QObject
{
    Q_OBJECT
public:
    ucRegister(QObject* parent=0);
    quint32 value();
public slots:
    void setName(const QString& name);
    void setValue(quint32 value);
    void setOffset(qint64 offset);
signals:
    void nameChanged(const QString& name);
    void offsetChanged(qint64 offset);
    void valueChanged(quint32 value);
private:
    QString p_name;
    qint64  p_addressOffset;
    quint32 p_value;
};

class ucPeripheral: public QObject,public QList<ucRegister*>
{
    Q_OBJECT
public:
    ucPeripheral(QObject* parent=0);
private:
    QString p_name;
    qint64  p_baseAddress;
};



class ucSystemOnChip : public QObject,public QList<ucPeripheral*>
{
    Q_OBJECT
public:
    ucSystemOnChip(QObject* parent=0);
public slots:
    void setName(const QString& name);
signals:
    void nameChanged(const QString& name);
private:
    QString p_name;
};



#endif // REGISTERDATA_H







