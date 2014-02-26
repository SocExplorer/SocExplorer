/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2013, Laboratory of Plasmas Physic - CNRS
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
#ifndef XMLMODEL_H
#define XMLMODEL_H
#include <QString>
#include <QList>
#include <QObject>
#include "XMLdata.h"
#include "socexplorerxmlfile.h"
#include "xmldriver.h"
#include <socmodel.h>
#if defined(SOCEXPLORER_SDK_BUILD)
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_EXPORT
#else
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_IMPORT
#endif

class SOCEXPLORER_SDK_EXPORT socExplorerXmlModel: public QObject
{
    Q_OBJECT
public:
    socExplorerXmlModel(QObject* parent=0);
    //! Check that the given file is a readable Xml file.
    int checkXmlFile(const QString& fileName);
    int createXmlFile(const QString& fileName);
    //! Return the list of all xml nodes with the given tag name in cached Xml files.
    QList<xmlfile*> getFileList(const QString& tagNameFilter);
    QList<QDomNodeList> getAllNodes(const QString& tagName);
    QStringList getPeripheralRegList(const QString& peripheralName);
    peripheralModel getPeripheral(const QString& peripheralName);
public slots:
    void updateSOClist();
    void registerXmlFile(const QString &fileName);
    //! Reload all xmlFiles.
    void scanXmlFiles();
signals:

private:
    void p_getRegs(peripheralModel *periph, QDomNodeList *nodes);
    QList<xmlDataSystemOnChip*> p_SocList;
    void clearSocList();
    XMLDriver* p_driver;
};



#endif // XMLMODEL_H







