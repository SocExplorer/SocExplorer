#ifndef SRECFILE_H
#define SRECFILE_H

#include <QObject>
#include <abstractexecfile.h>
#include <QFile>
#include <QStringList>

class srecFile : public abstractExecFile
{
    Q_OBJECT
public:
    explicit srecFile();
    srecFile(const QString& File);
    srecFile(const QStringList& Files);
    ~srecFile();
    bool openFile(const QString& File);
    bool openFiles(const QStringList& Files);
    bool isopened();
    int closeFile();
    QList<codeFragment*> getFragments();

signals:

public slots:
private:
    void parseFile(QFile* file);
    QStringList p_fileNames;
    QList<QFile*>p_files;
    QList<codeFragment*> p_fragments;

};

#endif // SRECFILE_H
