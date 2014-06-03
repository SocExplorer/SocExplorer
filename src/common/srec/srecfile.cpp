#include "srecfile.h"
#include <QTextStream>

srecFile::srecFile()
{
}

srecFile::srecFile(const QString &File)
{
    openFile(File);
}

srecFile::srecFile(const QStringList &Files)
{
    openFiles(Files);
}

srecFile::~srecFile()
{

}

bool srecFile::openFile(const QString &File)
{
    return openFiles(QStringList()<<File);
}

bool srecFile::openFiles(const QStringList &Files)
{
    this->p_fileNames.clear();
    this->p_fileNames.append(Files);
    for(int i=0;i<p_files.count();i++)
    {
        delete p_files.at(i);
    }
    this->p_files.clear();
    for(int i=0;i<Files.count();i++)
    {
        this->p_isSrec=true;
        this->p_isSrec &= isSREC(Files.at(i));
        this->p_files.append(new QFile(Files.at(i)));
        this->p_files.at(i)->open(QIODevice::ReadOnly);
        parseFile(this->p_files.at(i));
    }
    return true;
}

bool srecFile::isopened()
{
    bool opened = true;
    for(int i=0;i<this->p_files.count();i++)
    {
        opened &= p_files.at(i)->isOpen();
    }
    return opened;
}

int srecFile::closeFile()
{
    for(int i=0;i<p_files.count();i++)
    {
        delete p_files.at(i);
    }
    p_files.clear();
    p_fileName.clear();
}

QList<codeFragment *> srecFile::getFragments()
{
    return p_fragments;
}

bool srecFile::toSrec(QList<codeFragment *> fragments, const QString &File)
{
    QString line;
    QFile file(File);
    file.open(QIODevice::WriteOnly);
    if(file.isOpen())
    {
        QTextStream stream( &file );
        //First build header
        line.append("S0");
        line.append(QString("%1").arg(File.count()+3,2,16).replace(' ','0'));
        line.append("0000");
        for(int i=0;i<File.count();i++)
        {
            line.append(QString("%1").arg((uchar)File.at(i).toLatin1(),2,16).replace(' ','0'));
        }
        line.append(QString("%1").arg((uchar)srecFile::lineCheckSum(line),2,16).replace(' ','0'));
        line.append('\n');
        stream << line.toUpper();
        for(int i=0;i<fragments.count();i++)
        {
            codeFragment *fragment = fragments.at(i);
            for(int j=0;j<(int)(fragment->size);j+=16)
            {
                line.clear();
                line.append("S315");
                line.append(QString("%1").arg(fragment->address+j,8,16).replace(' ','0'));
                for(int k=0;k<16;k++)
                {
                    line.append(QString("%1").arg((uchar)fragment->data[j+k],2,16).replace(' ','0'));
                }
                line.append(QString("%1").arg((uchar)srecFile::lineCheckSum(line),2,16).replace(' ','0'));
                line.append('\n');
                stream << line.toUpper();
            }
            int rem = fragment->size%16;
            if(rem)
            {
                line.clear();
                line.append("S3");
                line.append(QString("%1").arg(rem,2,16).replace(' ','0'));
                line.append(QString("%1").arg(fragment->address+fragment->size-rem,8,16).replace(' ','0'));
                for(int k=0;k<rem;k++)
                {
                    line.append(QString("%1").arg((uchar)fragment->data[fragment->size-rem+k],2,16).replace(' ','0'));
                }
                line.append(QString("%1").arg((uchar)srecFile::lineCheckSum(line),2,16).replace(' ','0'));
                line.append('\n');
                stream << line.toUpper();
            }
            line.clear();
            line.append("S705");
            line.append(QString("%1").arg(fragment->address,8,16).replace(' ','0'));
            line.append(QString("%1").arg((uchar)srecFile::lineCheckSum(line),2,16).replace(' ','0'));
            line.append('\n');
            stream << line.toUpper();
        }
        file.close();
        return true;
    }

    return false;
}

int srecFile::lineCount()
{
    return p_lineCount;
}

int srecFile::getFragmentsCount()
{
    return p_fragments.count();
}

int srecFile::getFragmentAddress(int index)
{
    if((index < p_fragments.count()) && (index>=0))
    {
        return p_fragments.at(index)->address;
    }
    return 0;
}

int srecFile::getFragmentSize(int index)
{
    if((index < p_fragments.count()) && (index>=0))
    {
        return p_fragments.at(index)->size;
    }
    return 0;
}

QString srecFile::getFragmentHeader(int index)
{
    if((index < p_fragments.count()) && (index>=0))
    {
        return p_fragments.at(index)->header;
    }
    return "";
}

bool srecFile::getFragmentData(int index, char **buffer)
{

    if((index < p_fragments.count()) && (index>=0))
    {
        *buffer = (char *)this->p_fragments.at(index)->data;
        return true;
    }
    return false;
}

bool srecFile::isSREC()
{
    return p_isSrec & isopened();
}

bool srecFile::isSREC(const QString &File)
{
    QFile file(File);
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {
        file.seek(0);
        QString line=file.readLine();
        file.close();
        return ((line.at(0)=='S')&&(line.at(1)=='0'));
    }
    return false;
}

void srecFile::parseFile(QFile *file)
{
    if(file->isOpen())
    {
        this->p_lineCount = 0;
        file->seek(0);
        codeFragment* fragment=NULL;
        QByteArray data;
        quint64 size=0;
        quint64 address=-1;
        QString header;
        while (!file->atEnd())
        {
            QString line = file->readLine();
            p_lineCount++;
            if(line.count()>4)
            {
                if(line.at(0)=='S')
                {
                    bool ok;
                    int count = line.mid(2,2).toInt(&ok,16);
                    if(line.at(1)=='0')
                    {
                        header.clear();
                        for(int i=0;i<(count-3);i++)
                        {
                            header.append((char)line.mid((2*i)+8,2).toInt(&ok,16));
                        }
                    }
                    if(line.at(1)=='1')
                    {
                    }
                    if(line.at(1)=='2')
                    {

                    }
                    if(line.at(1)=='3')
                    {
                        int naddress =line.mid(4,8).toInt(&ok,16);
                        if(address !=naddress)
                        {
                            if(fragment!=NULL)
                            {
                                fragment->size = data.size();
                                fragment->data = (char*)malloc(data.size());
                                for(int i =0;i<data.size();i++)
                                {
                                    fragment->data[i]=data.at(i);
                                }
                                data.clear();
                                p_fragments.append(fragment);
                            }
                            fragment = new codeFragment();
                            fragment->address = naddress;
                            fragment->header = header;
                        }
                        address = naddress+count-5;
                        for(int i=0;i<(count-5);i++)
                        {
                            data.append((char)line.mid((2*i)+12,2).toInt(&ok,16));
                        }
                    }
                    if(line.at(1)=='5')
                    {

                    }
                    if(line.at(1)=='6')
                    {

                    }
                    if(line.at(1)=='7')
                    {

                    }
                    if(line.at(1)=='8')
                    {

                    }
                    if(line.at(1)=='9')
                    {

                    }
                }
            }
        }
        if(data.size()!=0)
        {
            fragment->size = data.size();
            fragment->data = (char*)malloc(data.size());
            for(int i =0;i<data.size();i++)
            {
                fragment->data[i]=data.at(i);
            }
            data.clear();
            p_fragments.append(fragment);
        }

    }
}

char srecFile::lineCheckSum(const QString &line)
{
    char sum=0;
    QString localLine = line;
    bool ok;
    if(localLine.at(0)=='S') // then should skip the first two digits
    {
        localLine.remove(0,2);
    }
    for(int i=0;i<localLine.count();i+=2)
    {
        sum+=(char)(localLine.mid(i,2).toInt(&ok,16));
    }
    return ~sum;
}

