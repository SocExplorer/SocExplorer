#ifndef XMLDRIVER_H
#define XMLDRIVER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QObject>
#include "XMLdata.h"
#include "socexplorerxmlfile.h"

class XMLDriver : public QObject
{
    Q_OBJECT
public:
    explicit XMLDriver(QObject *parent = 0);
    //! Check that the given file is a readable Xml file.
    int checkXmlFile(const QString& fileName);
    int createXmlFile(const QString& fileName);
    //! Return the list of all xml nodes with the given tag name in cached Xml files.
    QList<xmlfile*> getFileList(const QString& tagNameFilter);
    QList<QDomNodeList> getAllNodes(const QString& tagName);
public slots:
    void registerXmlFile(const QString &fileName);
    //! Reload all xmlFiles.
    void scanXmlFiles();

signals:

private:
        QList<xmlfile*>* xmlFiles;
};

#endif // XMLDRIVER_H
