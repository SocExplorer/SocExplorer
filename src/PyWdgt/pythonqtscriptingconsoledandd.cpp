#include "pythonqtscriptingconsoledandd.h"
#include <QFileInfo>

PythonQtScriptingConsoleDandD::PythonQtScriptingConsoleDandD(QWidget *parent, const PythonQtObjectPtr &context, Qt::WindowFlags i)
    :NicePyConsole(parent,context)
{
    Q_UNUSED(i)
    this->setAcceptDrops(true);
    this->clear();
    this->insertPrompt(true);
}





/*taken from http://developer.qt.nokia.com/wiki/Drag_and_Drop_of_files*/
void PythonQtScriptingConsoleDandD::dropEvent(QDropEvent * event)
{
    const QMimeData* mimeData = event->mimeData();

    // check for our needed mime type, here a file or a list of files
    if (mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        QFileInfo fileinfo;

        // extract the local paths of the files
        for (int i = 0; i < urlList.size() && i < 32; ++i)
        {
            fileinfo.setFile(urlList.at(i).toLocalFile());
            if(!fileinfo.suffix().compare("py"))
            {
                QString CMD="execfile(\'"+urlList.at(i).toLocalFile()+"\')";
                this->executeCurrentCommand(CMD);
            }
        }

        // call a function to open the files

    }
}



void PythonQtScriptingConsoleDandD::dragMoveEvent(QDragMoveEvent *e)
{
    e->accept();
}

void PythonQtScriptingConsoleDandD::dragEnterEvent(QDragEnterEvent *e)
{
    const QMimeData* mimeData = e->mimeData();

    // check for our needed mime type, here a file or a list of files
    if (mimeData->hasUrls())
    {
        e->acceptProposedAction();
    }
}

