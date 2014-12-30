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
#ifndef GENERICPYSYSDRIVER_H
#define GENERICPYSYSDRIVER_H
#include <QObject>
#include <QVariant>
#include <QVariantList>
#include <malloc.h>
#include <QFile>
#include <stdint.h>
#include <QTextStream>
#include <abstractbinfile.h>
#if defined(SOCEXPLORER_SDK_BUILD)
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_EXPORT
#else
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_IMPORT
#endif
class socexplorerplugin;

class SOCEXPLORER_SDK_EXPORT genericPySysdriver : public QObject
{
    Q_OBJECT

public:

    explicit genericPySysdriver(socexplorerplugin* plugin,QObject* parent=0);
signals:
public slots:
    QVariantList Read(unsigned int address,unsigned int count);
    void Write(unsigned int address,QList<QVariant> dataList);
    bool dumpMemory(unsigned int address,unsigned int count,QString file);
    bool memSet(unsigned int address,int value, unsigned int count);
    bool loadbin(unsigned int address,QString file);
    bool loadfile(abstractBinFile* file);
    bool dumpMemory(unsigned int address, unsigned int count, QString file, const QString &format);
    QString instance();
private:
    socexplorerplugin* plugin;

};

#endif // GENERICPYSYSDRIVER_H
