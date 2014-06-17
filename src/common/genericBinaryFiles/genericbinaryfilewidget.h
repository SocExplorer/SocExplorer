#ifndef GENERICBINARYFILEWIDGET_H
#define GENERICBINARYFILEWIDGET_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <abstractbinfile.h>

namespace Ui {
class genericBinaryFileWidget;
}

typedef enum {Type_SREC,Type_Bin,Type_Elf}FileTypeEnum;
class FileListElement
{
public:
    FileListElement() {}
    FileListElement(QString fileName,bool isOpened,FileTypeEnum FileType,abstractBinFileWidget* viewer)
        :fileName(fileName),isOpened(isOpened),FileType(FileType),viewer(viewer){}
    QString fileName;
    bool isOpened;
    FileTypeEnum FileType;
    abstractBinFileWidget* viewer;
};

class genericBinaryFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit genericBinaryFileWidget(QWidget *parent = 0);
    ~genericBinaryFileWidget();

public slots:
    void openFile();

private:
    Ui::genericBinaryFileWidget *ui;
    QList<FileListElement*> files;
};

#endif // GENERICBINARYFILEWIDGET_H
