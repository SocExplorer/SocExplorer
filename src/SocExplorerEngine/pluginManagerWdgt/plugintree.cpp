#include "plugintree.h"
#include "pluginloader.h"
#include <QApplication>
#include "qsvgicon.h"
#include <QHeaderView>
#include <QString>

plugintree::plugintree(QWidget *parent) :
    QTreeWidget(parent)
{
    this->editingItem=false;
    this->editeditemprev=new QString;
    this->setAcceptDrops(true);
    this->setDragDropMode(QAbstractItemView::DropOnly);
    connect(this,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(pluginselectedslt(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemSelectionChanged()),this,SLOT(itemSelectionChangedslt()));
    this->setHeaderLabels(QStringList()<<"Loaded plugins");
    emit this->geteplugintree();
}


void plugintree::pluginselectedslt(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column)
    emit this->pluginselected(item->text(0));
}

void plugintree::itemSelectionChangedslt()
{
    if(this->selectedItems().count()==1)
    {
        emit this->pluginselected(this->selectedItems().first()->text(0));
    }
}

void plugintree::treeChanged(const QList<socexplorerplugin*>& drivers)
{
    this->clear();
    for(int i=0;i<drivers.count();i++)
    {
        QTreeWidgetItem* currentItem=new QTreeWidgetItem;
        currentItem->setIcon(0,QSvgIcon(":/images/server.svg"));
        currentItem->setText(0,drivers.at(i)->instanceName());
        this->addTopLevelItem(currentItem);
        if(drivers.at(i)->childs.count()!=0)
        {
                this->addplugin(drivers.at(i),currentItem);
        }
        currentItem->setExpanded(true);
    }
}

void plugintree::addplugin(socexplorerplugin *driver, QTreeWidgetItem *item)
{

    for(int i=0;i<driver->childs.count();i++)
    {
        QTreeWidgetItem* currentItem=new QTreeWidgetItem;
        currentItem->setIcon(0,QSvgIcon(":/images/server.svg"));
        currentItem->setText(0,driver->childs.at(i)->instanceName());
        item->addChild(currentItem);
        if(driver->childs.at(i)->childs.count()!=0)
        {
                this->addplugin(driver->childs.at(i),currentItem);
        }
        currentItem->setExpanded(true);
    }

}




void plugintree::dragEnterEvent(QDragEnterEvent *event)
{  
    if (event->mimeData()->hasFormat("socexplorer/pluginName"))
    {

        if(pluginloader::isvalid(event->mimeData()->text()))
        {
            event->acceptProposedAction();
        }else
            {
                event->ignore();
            }

    } else
    {
        event->ignore();
    }
}

void plugintree::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("socexplorer/pluginName"))
    {

        if(pluginloader::isvalid(event->mimeData()->text()))
        {
            this->clearSelection();
            if(this->itemAt(event->pos())!=NULL)
            {
                this->itemAt(event->pos())->setSelected(true);
                event->acceptProposedAction();
            }
            else
                if(pluginloader::libcanberoot(event->mimeData()->text()))
                {
                    event->acceptProposedAction();
                }
                else
                {
                    event->ignore();
                }
        }else
        {
            event->ignore();
        }

    } else
    {
        event->ignore();
    }
}


void plugintree::mouseDoubleClickEvent(QMouseEvent *event)
{
    this->clearSelection();
    this->editeditem=this->itemAt(event->pos());
    if(this->editeditem!=NULL && this->editingItem==false)
    {
        *this->editeditemprev=this->editeditem->text(0);
        this->openPersistentEditor(this->editeditem);
        this->editingItem=true;
    }
    QTreeWidget::mouseDoubleClickEvent(event);
}

void plugintree::mousePressEvent(QMouseEvent *event)
{
    QTreeWidget::mousePressEvent(event);
    if(this->editingItem==true && this->editeditem!=this->itemAt(event->pos()))
    {
        this->closePersistentEditor(this->editeditem);
        if(QString::compare(this->editeditem->text(0),this->editeditemprev))
        {
            emit this->changeSysDriverInstName(this->editeditem->text(0),QString(*this->editeditemprev));
        }
        this->editingItem=false;
    }
}


void plugintree::keyPressEvent(QKeyEvent *event)
{

    {
        switch(event->key())
        {
        case Qt::Key_Return:
            if(this->editingItem==true)
            {
                this->closePersistentEditor(this->editeditem);
                if(QString::compare(this->editeditem->text(0),this->editeditemprev))
                {
                    emit this->changeSysDriverInstName(this->editeditem->text(0),QString(*this->editeditemprev));
                }
                this->editingItem=false;
            }

            break;
        case Qt::Key_Delete:
            if(this->selectedItems().count()==1)
            {
                emit this->closeSysDriver(this->selectedItems().first()->text(0));
            }
            break;
        default:
            break;
        }
    }
}


void plugintree::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("socexplorer/pluginName"))
    {
        QTreeWidgetItem* item=this->itemAt(event->pos());
        if(item!=NULL)
        {
            emit this->loadSysDriverToParent(event->mimeData()->text(),item->text(0));
            event->acceptProposedAction();
        }
        else if(pluginloader::libcanberoot(event->mimeData()->text()))
        {
            QString test(event->mimeData()->text());
            emit this->loadSysDriver(event->mimeData()->text());
        }
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            if(pluginloader::checklibrary(event->mimeData()->text())!=0) //lib ok
            {
                if(pluginloader::libcanberoot(event->mimeData()->text()))
                    event->acceptProposedAction();
            }
        }
    } else
    {
        event->ignore();
    }
}



