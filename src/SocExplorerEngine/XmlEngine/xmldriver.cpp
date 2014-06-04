#include "xmldriver.h"
#include <socexplorerengine.h>
#include <QFile>
#include <QDebug>

XMLDriver::XMLDriver(QObject *parent) :
    QObject(parent)
{
    this->xmlFiles = new QList<xmlfile*>();
    this->scanXmlFiles();
}

int XMLDriver::checkXmlFile(const QString &fileName)
{
    QDomDocument document;
    QFile file( fileName );
    if( !file.open( QIODevice::ReadOnly ) )
        return 0;
    document.setContent(&file);
    if(document.isNull())
        return 0;
    file.close();
    return 1;
}

int XMLDriver::createXmlFile(const QString &fileName)
{
    QDomDocument* xmlDoc=new QDomDocument();
    QDomProcessingInstruction header = xmlDoc->createProcessingInstruction( "xml", "version=\"1.0\" encoding=\"utf-8\"" );
    xmlDoc->appendChild( header );
    QDomElement rootnode= xmlDoc->createElement("socExplorerXml");
    rootnode.setAttribute("name",fileName);
    xmlDoc->appendChild(rootnode);
    QFile file( fileName );
    if(!file.exists())
    {
        if( !file.open( QIODevice::WriteOnly ) )
            return 0;
        QTextStream ts( &file );
        ts << xmlDoc->toString();
        file.close();
        return 1;
    }
    return 0;
}

QList<xmlfile *> XMLDriver::getFileList(const QString &tagNameFilter)
{
    QList<xmlfile*> list;
    for(int i=0;i<xmlFiles->count();i++)
    {
        if(xmlFiles->at(i)->rootTagName()==tagNameFilter)
        {
            list.append(xmlFiles->at(i));
        }
    }
    return list;
}

QList<QDomNodeList> XMLDriver::getAllNodes(const QString &tagName)
{
    QList<QDomNodeList> list;
    for(int i=0;i<xmlFiles->count();i++)
    {
        QDomNodeList nodes=xmlFiles->at(i)->getRootElement()->elementsByTagName(tagName);
        if(!nodes.isEmpty())
        {
            list.append(nodes);
        }
    }
    return list;
}

void XMLDriver::registerXmlFile(const QString &fileName)
{
    for(int i=0;i<xmlFiles->count();i++)
    {
        if(xmlFiles->at(i)->fileName()==fileName)
        {
            return;
        }
    }
    xmlFiles->append(new xmlfile(fileName));
}

void XMLDriver::scanXmlFiles()
{
    QDir configDir(SocExplorerEngine::configFolder());
    QFileInfoList list = configDir.entryInfoList();
    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.isFile())
        {
            if(fileInfo.fileName().contains(".xml") && !fileInfo.fileName().contains(".xml~"))
            {
                qDebug()<<"Found " + fileInfo.fileName();
                if(checkXmlFile(fileInfo.absoluteFilePath()))
                {
                    registerXmlFile(fileInfo.absoluteFilePath());
                }
            }
        }
    }
}
