#include "unixpluginloader.h"
#include <stdio.h>
#include <QDebug>

unixPluginLoader::unixPluginLoader(const QString &libPath)
{
    qDebug()<<"try to open "+libPath;
    dlHandle = dlopen(libPath.toStdString().c_str(),RTLD_LAZY|RTLD_GLOBAL);
    if(dlHandle==NULL)
        qDebug() << "Failed"<< dlerror();
    else
        qDebug() << "Success";
    this->libPath = libPath;
}

void *unixPluginLoader::resolve(const QString &symbol)
{
    if(dlHandle!=NULL)
    {
        qDebug()<<"try to resolve "+symbol+" in "+libPath;
        void* sym =  dlsym (dlHandle, symbol.toStdString().c_str());
        if(sym==NULL)
            qDebug() << "Failed"<< dlerror();
        else
            qDebug() << "Success";
        return sym;
    }
    return NULL;
}

void unixPluginLoader::close()
{
    if(dlHandle!=NULL)
    {
        dlclose(dlHandle);
        qDebug() << dlerror();
    }
}
