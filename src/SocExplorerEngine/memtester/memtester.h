#ifndef MEMTESTER_H
#define MEMTESTER_H
#include <socexplorerplugin.h>
#include <QObject>

class MemTester : public QObject
{
  Q_OBJECT
public:
  MemTester(QObject *parent=0);
  ~MemTester();

  static unsigned int measureMemSize(socexplorerplugin* plugin, unsigned int address,unsigned int maxSize=0xFFFFFFFF);
  static unsigned int measureMemSize(const QString& plugin, unsigned int address,unsigned int maxSize=0xFFFFFFFF);
public slots:

};

#endif // MEMTESTER_H
