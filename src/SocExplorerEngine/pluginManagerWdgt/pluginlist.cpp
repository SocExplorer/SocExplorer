/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2011, Laboratory of Plasmas Physic - CNRS
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
#include "pluginlist.h"
#include "pluginloader.h"
#include <QDir>
#include <QFile>
#include <QFileInfoList>
#include <QString>
#include <QStringList>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include "qsvgicon.h"
#include <QWidget>
#include <QDrag>

PluginList::PluginList(QWidget *parent):QListWidget(parent)
{
    this->setAcceptDrops(true);
    this->setDragEnabled(true);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    connect(this,SIGNAL(itemSelectionChanged()),this,SLOT(updateSelection()));
    this->showCacheAction = new QAction(tr("View cache content"),this);
    this->addAction(this->showCacheAction);
    connect(this->showCacheAction,SIGNAL(triggered()),this,SLOT(showCache()));
    this->setContextMenuPolicy(Qt::ActionsContextMenu);

}


void PluginList::refreshPluginList()
{
    this->clear();
    QList<PluginsCacheItem*> plugins = pluginloader::listAvailiables(true);
    for (int i = 0; i < plugins.count(); ++i)
    {
        PluginListItem *newItem = new PluginListItem(QString(plugins.at(i)->getpluginName()),plugins.at(i)->getpath()+"/"+plugins.at(i)->getfileName());
        newItem->setFlags(newItem->flags() &~ Qt::ItemIsEditable);
        this->addItem((QListWidgetItem*)newItem);
    }
}

void PluginList::dragEnterEvent(QDragEnterEvent *event)
{
    this->clearSelection();
    this->itemAt(dragStartPosition)->setSelected(true);
    event->acceptProposedAction();
}

void PluginList::dragMoveEvent(QDragMoveEvent *e)
{
    e->accept();
}

void PluginList::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragStartPosition = event->pos();
    }
    QListWidget::mousePressEvent(event);
}

void PluginList::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if ((event->pos() - dragStartPosition).manhattanLength()< QApplication::startDragDistance())
        return;
    if(this->selectedItems().count()==0)
        return;
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    drag->setHotSpot(event->pos() - rect().topLeft());
    mimeData->setData("socexplorer/pluginName",QByteArray(((PluginListItem*)this->selectedItems().first())->fullPath->toLatin1()));
    mimeData->setText(((PluginListItem*)this->selectedItems().first())->fullPath->toLatin1());
    drag->setMimeData(mimeData);
    drag->exec(Qt::MoveAction);
}



void PluginList::dropEvent(QDropEvent *event)
{
    Q_UNUSED(event)
}



void PluginList::updateSelection()
{
    QStringList _items;
    for(int i=0;i<this->selectedItems().count();i++)
    {
        _items << *((PluginListItem*)(this->selectedItems().at(i)))->fullPath;
    }
    emit this->itemSelectionChanged(_items);
}
