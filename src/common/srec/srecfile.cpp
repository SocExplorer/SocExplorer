#include "srecfile.h"

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
    openFiles(QStringList()<<File);
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
        this->p_files.append(new QFile(Files.at(i)));
        this->p_files.at(i)->open(QIODevice::ReadOnly);
        parseFile(this->p_files.at(i));
    }
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

}

QList<codeFragment *> srecFile::getFragments()
{
    return p_fragments;
}

void srecFile::parseFile(QFile *file)
{
    if(file->isOpen())
    {
        file->seek(0);
        codeFragment* fragment=NULL;
        QByteArray data;
        quint32 size=0;
        quint32 address=0;
        while (!file->atEnd())
        {
            QString line = file->readLine();
            if(line.count()>4)
            {
                if(line.at(0)=='S')
                {
                    bool ok;
                    int count = line.mid(2,2).toInt(&ok,16);
                    if(line.at(1)=='0')
                    {
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
                        }
                        address = naddress+count-5;
                        for(int i=0;i<(count-5);i++)
                        {
                            data.append((char)line.mid((2*i)+8,2).toInt(&ok,16));
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

