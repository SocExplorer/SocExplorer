#ifndef UNIXPLUGINLOADER_H
#define UNIXPLUGINLOADER_H

#include <dlfcn.h>
#include <QString>

class unixPluginLoader
{
public:
    unixPluginLoader(const QString& libPath);
    void* resolve(const QString& symbol);
    void close();
private:
    void* dlHandle;
    QString libPath;
};

#endif // UNIXPLUGINLOADER_H
