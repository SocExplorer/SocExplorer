/*------------------------------------------------------------------------------
███████╗ ██████╗  ██████╗    ███████╗██╗  ██╗██████╗ ██╗      ██████╗ ██████╗ ███████╗██████╗
██╔════╝██╔═══██╗██╔════╝    ██╔════╝╚██╗██╔╝██╔══██╗██║     ██╔═══██╗██╔══██╗██╔════╝██╔══██╗
███████╗██║   ██║██║         █████╗   ╚███╔╝ ██████╔╝██║     ██║   ██║██████╔╝█████╗  ██████╔╝
╚════██║██║   ██║██║         ██╔══╝   ██╔██╗ ██╔═══╝ ██║     ██║   ██║██╔══██╗██╔══╝  ██╔══██╗
███████║╚██████╔╝╚██████╗    ███████╗██╔╝ ██╗██║     ███████╗╚██████╔╝██║  ██║███████╗██║  ██║
╚══════╝ ╚═════╝  ╚═════╝    ╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝

--  This file is a part of the SOC Explorer Software
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
#ifndef SOCEXPLORERPLUGIN_H
#define SOCEXPLORERPLUGIN_H
#include <QWidget>
#include <QAction>
#include <QDockWidget>
#include <QMainWindow>
#include <QList>
#include <QMenu>
#include <socexplorer.h>
#include <QObject>
#include <QVariant>
#include <QVariantList>
#include <malloc.h>
#include <QFile>
#include <stdint.h>
#include <QTextStream>
#include <abstractbinfile.h>
#ifndef driver_Name
#define driver_Name "Plugin"
#endif
#ifndef driver_Author
#define driver_Author "No Author"
#endif
#ifndef driver_Version
#define driver_Version "0.0.0"
#endif
#ifndef driver_Description
#define driver_Description "No description."
#endif
#ifndef driver_can_be_root
#define driver_can_be_root 0
#endif
#ifndef driver_can_be_child
#define driver_can_be_child 0
#endif
#ifndef driver_VID
#define driver_VID 0
#endif
#ifndef driver_PID
#define driver_PID 0
#endif

#if defined(SOCEXPLORER_SDK_BUILD)
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_EXPORT
#else
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_IMPORT
#endif


//! socexplorerplugin is the base class for any SocExplorer plugin, it gives a standard interface to communicate
//! between each plugins and to interact with SocExplorer software.

class SOCEXPLORER_SDK_EXPORT socexplorerplugin : public QDockWidget
{
    Q_OBJECT
public:
    //! Default plugin constructor, any plugin should call this constructor.
    socexplorerplugin(QWidget *parent = 0,bool createPyObject=true):QDockWidget(parent)
    {
        closeAction=NULL;
        menu=NULL;
        ChildsMenu=NULL;
        this->Connected = false;
        this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetVerticalTitleBar);
        _Name = new QString(driver_Name);
        _Author = new QString(driver_Author);
        _Version = new QString(driver_Version);
        _Description = new QString(driver_Description);
        _canBeChild = driver_can_be_child;
        _canBeRoot = driver_can_be_root;
        _VID = driver_VID;
        _PID = driver_PID;
    }
    //! Tells if the plugin is connected, it is used to enable or disable all childrens interfaces.
    virtual int isConnected();
    //! Gives the associated Vendor IDentifier, usefull to automatically associate plugins with found
    //! hardware while board enumeration.
    virtual int VID(){return _PID;}
    //! Gives the associated Product IDentifier, usefull to automatically associate plugins with found
    //! hardware while board enumeration.
    virtual int PID(){return _VID;}
    //! Gives the plugin's base name, usefull to automatically generate instance name.
    virtual QString baseName();
    //! Gives the base address of the current instance, for example if your plugin is supposed to drive
    //! an UART it will correspond to the address of it's first register. This address have at least to
    //! be set by SocExplorer and it can be user accessible if you want.
    virtual int baseAddress();
    //! Sets the base address of the current instance, for example if your plugin is supposed to drive
    //! an UART it will correspond to the address of it's first register. This address have at least to
    //! be set by SocExplorer and it can be user accessible if you want.
    virtual void setBaseAddress(unsigned int baseAddress);

    QList<socexplorerplugin*> childs;
    socexplorerplugin* parent;
    QAction* closeAction;
    QString  instanceName();
    QString  instance(){return instanceName();}
    QMenu* menu;
    QMenu* ChildsMenu;

signals:
    //! Signal emited each time the plugin is about to be closed.
    void closePlugin(socexplorerplugin* driver);
    void activateSig(bool flag);
    void registerObject(QObject* object,const QString& instanceName);

public slots:
    virtual int registermenu(QMenu* menu);
    virtual void postInstantiationTrigger();
    //! Write slot this is the way your children plugins ask you for writing data.
    //! If your plugin is supposed to have childern drivers you should implement this methode.
    //! By default this methode forward the write request to the parent plugin.
    //! \param Value Pointer the data buffer.
    //! \param count Number of 32 bits words you should to write.
    //! \param address Address from where you should to start to write.
    //! \return Quantity of 32 bits words writtens.
    virtual unsigned int Write(unsigned int* Value, unsigned int count,unsigned int address);
    //! Read slot this is the way your children plugins ask you for reading data.
    //! If your plugin is supposed to have childern drivers you should implement this methode.
    //! By default this methode forward the write request to the parent plugin.
    //! \param Value Pointer the data buffer.
    //! \param count Number of 32 bits words you should to read.
    //! \param address Address from where you should to start to read.
    //! \return Quantity of 32 bits words read.
    virtual unsigned int Read(unsigned int* Value, unsigned int count,unsigned int address);
    virtual void closeMe();
    virtual void activate(bool flag);
    virtual void setInstanceName(const QString& newName);

    virtual bool dumpMemory(unsigned int address,unsigned int count,QString file);
    virtual bool memSet(unsigned int address,int value, unsigned int count);
    virtual bool loadbin(unsigned int address,QString file);
    virtual bool loadfile(abstractBinFile* file);
    virtual bool dumpMemory(unsigned int address,unsigned int count,QString file,const QString& format);
    QVariantList Read(unsigned int address, unsigned int count);
    void Write(unsigned int address, QList<QVariant> dataList);
    socexplorerplugin* parentPlugin(){return this->parent;}
    socexplorerplugin* toPlugin(){return (socexplorerplugin*)this;}
protected:
    int BaseAddress;
    bool Connected;
    QString* _Name;
    QString* _Author;
    QString* _Version;
    QString* _Description;
    QString  _instanceName;
    int _canBeChild;
    int _canBeRoot;
    int _VID;
    int _PID;
};

#endif // SOCEXPLORERPLUGIN_H
