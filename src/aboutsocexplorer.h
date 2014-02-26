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
#ifndef ABOUTSOCEXPLORER_H
#define ABOUTSOCEXPLORER_H

#include <QWidget>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>

class aboutsocexplorer : public QTextBrowser
{
    Q_OBJECT
public:
    explicit aboutsocexplorer(QWidget *parent = 0);

signals:

public slots:
    void anchorClicked_slt(const QUrl &);
private:

};

#endif // ABOUTSOCEXPLORER_H
