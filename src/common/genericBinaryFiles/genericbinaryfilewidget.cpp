#include "genericbinaryfilewidget.h"
#include "ui_genericbinaryfilewidget.h"
#include <QFileDialog>
#include <QFile>
#include "srec/srecfile.h"

genericBinaryFileWidget::genericBinaryFileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::genericBinaryFileWidget)
{
    ui->setupUi(this);
}

genericBinaryFileWidget::~genericBinaryFileWidget()
{
    delete ui;
}

void genericBinaryFileWidget::openFile()
{
    QStringList filesNames = QFileDialog::getOpenFileNames(
                this,
                "Select one or more files to open",
                NULL,
                "Binary Files (*.bin);;SREC Files (*.srec);;Elf Files (*)");

    for(int i=0;i<filesNames.count();i++)
    {
        QFile file(filesNames.at(i));
        if(file.open(QIODevice::ReadOnly))
        {
            char magic[4];
            file.read(magic,4);
            QString line;
            switch((int)magic[0])
            {
            case 'e':
                if((magic[1]=='l') && (magic[2]=='f'))
                {
                    files.append(new FileListElement(filesNames.at(i),false,Type_Elf,NULL));
                }
                break;
            case 'S':
                file.seek(0);
                line = file.readLine();
                if(srecFile::checkSum(line))
                {
                    files.append(new FileListElement(filesNames.at(i),false,Type_SREC,NULL));
                }
                break;
            default:
                files.append(new FileListElement(filesNames.at(i),false,Type_Bin,NULL));
                break;
            }
        }
    }

}




