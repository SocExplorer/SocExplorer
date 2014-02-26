
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
    unsigned int* buffer = (unsigned int*)malloc(count*sizeof(unsigned int));
    if(buffer!=NULL)
    {
        this->plugin->Read(buffer,count,address);
        QFile outfile(file);
        if (!outfile.open(QIODevice::ReadWrite | QIODevice::Text))
            return false;
        QTextStream out(&outfile);
        for(int i=0;(unsigned int)i<count;i++)
            out << "0x"+QString::number(address+(i*4),16) + ": 0x" + QString::number(buffer[i],16) + "\n";
        free(buffer);
        out.flush();
        outfile.close();
        return true;
    }
    return false;
}

bool genericPySysdriver::memSet(unsigned int address,int value, unsigned int count)
{
    unsigned int* buffer = (unsigned int*)malloc(count*sizeof(unsigned int));
    if(buffer!=NULL)
    {
        memset((void*)buffer,value,count*sizeof(unsigned int));
        this->plugin->Write(buffer,count,address);
        free(buffer );
        return true;
    }
    return false;
}

bool genericPySysdriver::loadbin(unsigned int address,QString file)
{
    QFile infile(file);
    if (!infile.open(QIODevice::ReadOnly))
        return false;
    uint32_t* buffer = (uint32_t*)malloc(infile.size());
    if(buffer!=NULL)
    {
        infile.read((char*)buffer,infile.size());
        for(int i=0;i<(infile.size()/4);i++)
        {
            buffer[i] = socexplorerBswap32(buffer[i]);
        }
        this->plugin->Write(buffer,infile.size()/4,address);
        free(buffer);
        return true;
    }
    return false;

}

QString genericPySysdriver::instance()
{
    return plugin->instanceName;
}

