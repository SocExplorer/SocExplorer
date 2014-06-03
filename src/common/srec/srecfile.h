#ifndef SRECFILE_H
#define SRECFILE_H

#include <QObject>
#include <abstractbinfile.h>
#include <QFile>
#include <QStringList>

class srecFile : public abstractBinFile
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
    static bool toSrec(QList<codeFragment*> fragments,const QString& File);
    int lineCount();
    int getFragmentsCount();
    int getFragmentAddress(int index);
    int getFragmentSize(int index);
    QString getFragmentHeader(int index);
    bool getFragmentData(int index, char **buffer);

    bool isSREC();
    static bool isSREC(const QString& File);
signals:

public slots:
private:
    void parseFile(QFile* file);
    static char lineCheckSum(const QString& line);
    QStringList p_fileNames;
    QList<QFile*>p_files;
    QList<codeFragment*> p_fragments;
    int p_lineCount;
    bool p_isSrec;

};

#endif // SRECFILE_H
