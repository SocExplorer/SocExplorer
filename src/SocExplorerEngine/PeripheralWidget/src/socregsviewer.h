/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Plasma Physics Laboratory - CNRS
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 3 of the License, or
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
#ifndef SOCREGSVIEWER_H
#define SOCREGSVIEWER_H

#include <QWidget>
#include <QtWidgets>
#include "peripheralwidget.h"

#if defined(SOCEXPLORER_SDK_BUILD)
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_EXPORT
#else
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_IMPORT
#endif

class SOCEXPLORER_SDK_EXPORT socRegsViewer : public QScrollArea
{
    Q_OBJECT
public:
    explicit socRegsViewer(const QString& name,QWidget *parent = 0);
    peripheralWidget* peripheral(int index);

signals:

public slots:
    void addPeripheral(peripheralWidget* peripheral);
    void periphClicked(peripheralWidget* sender);
    void periphUp(peripheralWidget* sender,int cursorIndex);
    void periphDown(peripheralWidget* sender,int cursorIndex);
private:
    QWidget* p_scrollAreaWdgt;
    QString p_name;
    QGridLayout* p_layout,*p_scrollAreaWdgtLayout;
    QLabel* p_nameLabel;
    QList<peripheralWidget*> p_peripherals;
};

#endif // SOCREGSVIEWER_H
