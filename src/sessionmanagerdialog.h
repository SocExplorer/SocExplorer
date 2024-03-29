/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2015, Plasma Physics Laboratory - CNRS
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
#ifndef SESSIONMANAGERDIALOG_H
#define SESSIONMANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class SessionManagerDialog;
}

class SessionManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SessionManagerDialog(QWidget *parent = 0);
    ~SessionManagerDialog();

    QStringList getSessionsList();
public slots:
    void show();
    void newSession(QString session);
    int sessionExists(QString session);
private slots:
    void newSession();
    void renameSession();
    void deleteSession();
    void switchSession();
signals:
    void switchSession(QString session);
    void sessionListChanged();
    void sessionRenamed(const QString& oldName,const QString& newName);
    void sessionRemoved(const QString& session);
    void sessionAdded(const QString& newSession);
private:
    void updateSessionList();
    Ui::SessionManagerDialog *ui;
};

#endif // SESSIONMANAGERDIALOG_H
