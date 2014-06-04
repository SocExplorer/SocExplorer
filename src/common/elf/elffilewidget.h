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
/*--                  Author : Alexis Jeandet
--                     Mail : alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/
#ifndef ELFFILEWIDGET_H
#define ELFFILEWIDGET_H

#include <QtWidgets/QWidget>
#include "elffile.h"
#include <QtWidgets/QAction>
#include <qhexedit.h>

namespace Ui {
class elfFileWidget;
}

class elfFileWidget : public QWidget
{
    Q_OBJECT

public:
    elfFileWidget(QWidget *parent = 0);
    ~elfFileWidget();

public slots:
    void updateElfFile(ElfFile* file);
    void updateSymbols();
    void updateSections();

private slots:
    void sectionCellActivated(int row, int column);
    void exportToSREC();
    void exportToBIN();
    void pointSymbol();
    void filterSymbols(const QString& pattern);
    void filterSymbolsCaseUpdate(bool toggled);
private:
    Ui::elfFileWidget *ui;
    QStringList getSelectedSectionsNames();
    ElfFile* p_elf;
    QAction* exportToSREC_action;
    QAction* exportToBIN_action;
    QAction* pointInSections_action;
    QHexEdit* p_hexviewer;
};

#endif // ELFFILEWIDGET_H
