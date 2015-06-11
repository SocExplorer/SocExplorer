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
#include "sessionmanagerdialog.h"
#include "ui_sessionmanagerdialog.h"
#include <socexplorersettings.h>
#include <socexplorerconfigkeys.h>
#include <QInputDialog>
#include <QMessageBox>

SessionManagerDialog::SessionManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SessionManagerDialog)
{
    ui->setupUi(this);
    connect(this->ui->NewQPB,SIGNAL(clicked(bool)),this,SLOT(newSession()));
    connect(this->ui->DeleteQPB,SIGNAL(clicked(bool)),this,SLOT(deleteSession()));
    connect(this->ui->RenameQPB,SIGNAL(clicked(bool)),this,SLOT(renameSession()));
    connect(this->ui->SwitchToQPB,SIGNAL(clicked(bool)),this,SLOT(switchSession()));
}

SessionManagerDialog::~SessionManagerDialog()
{
    delete ui;
}


QStringList SessionManagerDialog::getSessionsList()
{
    QStringList result;
    QList<QList<QVariant> > sessions = SocExplorerSettings::arrays(SOCEXPLORERGLOBAL_SETTINGS_SESSIONS_SCOPE,QStringList()<<SOCEXPLORERGLOBAL_SETTINGS_SESSIONS_NAME);
    for(int i=0;i<sessions.count();i++)
    {
        if(sessions.at(i).count()>=1)
        {
            result.append(sessions.at(i).at(0).toString());
        }
    }
    // May always return at least default session
    if(result.count()==0)
    {
        result.append("default");
    }
    return result;
}

void SessionManagerDialog::show()
{
    QStringList sessions = getSessionsList();
    this->ui->listWidget->clear();
    this->ui->listWidget->addItems(sessions);
    QDialog::show();
}

void SessionManagerDialog::newSession()
{
    bool ok=true,exists=false;
    QString text;
    do
    {
        text = QInputDialog::getText(this, tr("SocExplorer Session Manager"),
                                     tr("Session name:"), QLineEdit::Normal,
                                     "New Session", &ok);
        exists = sessionExists(text);
        if(exists && ok)
        {
            QMessageBox::warning(this, tr("SocExplorer Session Manager"),
                                 tr("The session ")+text+tr(" already exists."),
                                 QMessageBox::Ok);
        }
    }while(ok && (text.isEmpty() || exists));

    if (ok && !text.isEmpty())
    {
        this->newSession(text);
    }
}

void SessionManagerDialog::newSession(QString session)
{
    if (!session.isEmpty())
    {
        this->ui->listWidget->addItem(session);
        updateSessionList();
    }
}

void SessionManagerDialog::renameSession()
{
    bool ok=true;
    int exists=0;
    QListWidgetItem* item = this->ui->listWidget->currentItem();
    QString text= item->text();
    do
    {
        text = QInputDialog::getText(this, tr("SocExplorer Session Manager"),
                                     tr("New session name:"), QLineEdit::Normal,
                                     text, &ok);
        exists = sessionExists(text);
        if(exists&& ok)
        {
            QMessageBox::warning(this, tr("SocExplorer Session Manager"),
                                 tr("The session ")+text+tr(" already exists."),
                                 QMessageBox::Ok);
        }
    }while(ok && text.isEmpty());

    if (ok && !text.isEmpty())
    {
        item->setText(text);
    }
}

void SessionManagerDialog::deleteSession()
{
    if(this->ui->listWidget->selectedItems().count())
    {
        QListWidgetItem* item = this->ui->listWidget->currentItem();
        if(item && item->text().compare("default"))
        {
            this->ui->listWidget->removeItemWidget(item);
            SocExplorerSettings::deleteSession(item->text());
            delete item;
            updateSessionList();
        }
    }
}

void SessionManagerDialog::switchSession()
{
    QListWidgetItem* item = this->ui->listWidget->currentItem();
    if(item)
        emit switchSession(item->text());
}

int SessionManagerDialog::sessionExists(QString session)
{
    int exists=0;
    for(int i=0;i< this->ui->listWidget->count();i++)
    {
        exists += (this->ui->listWidget->item(i)->text().compare(session)==0);
    }
    return exists;
}

void SessionManagerDialog::updateSessionList()
{
    QList<QList<QVariant> >  sessions;
    for(int i=0;i< this->ui->listWidget->count();i++)
    {
        QList<QVariant> sess;
        sess.append(this->ui->listWidget->item(i)->text());
        sessions.append(sess);
    }
    SocExplorerSettings::setArrays(SOCEXPLORERGLOBAL_SETTINGS_SESSIONS_SCOPE,QStringList()<<SOCEXPLORERGLOBAL_SETTINGS_SESSIONS_NAME,sessions);
}
