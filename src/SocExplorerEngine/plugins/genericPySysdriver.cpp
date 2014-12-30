
#include <genericPySysdriver.h>
#include <socexplorerplugin.h>
#ifdef WIN32
#include <stdlib.h>
#define socexplorerBswap32(X) _byteswap_ulong(X)
#else
#ifdef UNIX
#include <byteswap.h>
#define socexplorerBswap32(X) bswap_32(X)
#endif
#endif

#include <socexplorerengine.h>


genericPySysdriver::genericPySysdriver(socexplorerplugin* plugin,QObject* parent):
    QObject(parent)
{
    Q_UNUSED(parent)
    this->plugin = plugin;
}

QVariantList genericPySysdriver::Read(unsigned int address,unsigned int count)
{
    unsigned int data[count];
    QVariantList result;
    this->plugin->Read(data,count,address);
    for(unsigned int i = 0;i<count;i++)
    {
        result.append(QVariant((int)data[i]));
    }
    return result;
}
void genericPySysdriver::Write(unsigned int address,QList<QVariant> dataList)
{
    unsigned int data[dataList.count()];
    for(int i = 0;i<dataList.count();i++)
    {
        data[i] = (unsigned int)dataList.at(i).toUInt();
    }
    this->plugin->Write(data,dataList.count(),address);
}

bool genericPySysdriver::dumpMemory(unsigned int address,unsigned int count,QString file)
{
    return this->plugin->dumpMemory(address,count,file);
}

bool genericPySysdriver::memSet(unsigned int address,int value, unsigned int count)
{
    return this->plugin->memSet(address,value,count);
}

bool genericPySysdriver::loadbin(unsigned int address,QString file)
{
    return this->plugin->loadbin(address,file);

}

bool genericPySysdriver::loadfile(abstractBinFile *file)
{
  return this->plugin->loadfile(file);
}

bool genericPySysdriver::dumpMemory(unsigned int address, unsigned int count, QString file, const QString &format)
{
  return this->plugin->dumpMemory(address,count,file,format);
}

QString genericPySysdriver::instance()
{
    return plugin->instanceName();
}

