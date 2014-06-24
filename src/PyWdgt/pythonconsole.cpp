#include "pythonconsole.h"
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QCustomPlot/qcustomplot.h>
#include "../common/pythonQtOut/generated_cpp/PySocExplorer/PySocExplorer0.h"

#include <PythonQt.h>
#include "pluginloader.h"
#include <socexplorer.h>

void PythonQt_init_PySocExplorer(PyObject* module);
void PythonQt_init_PySocExplorerEngine(PyObject* module) ;

PythonConsole::PythonConsole(socexplorerproxy *proxy, QWidget *parent) :
    QWidget(parent)
{
    //PythonQt::init();
    PythonQt::init(PythonQt::RedirectStdOut);
    PythonQt_QtAll::init();
    this->proxy = proxy;
    this->mainlayout = new QHBoxLayout;
    this->mainContext = new PythonQtObjectPtr(PythonQt::self()->getMainModule());
    this->mainContext->addVariable(QString("PYMODULES"),QVariant(QString(PYMODULES)));
    this->console = new PythonQtScriptingConsoleDandD(NULL, PythonQt::self()->getMainModule());
    this->mainlayout->addWidget(this->console);
    this->setWindowTitle(tr("Python Scripting Console"));
    this->bussdriver = 0;
    this->setAcceptDrops(true);
    this->setLayout(this->mainlayout);
    connect(this->console,SIGNAL(pyConsoleRunFiles(QStringList)),this,SLOT(pyConsoleRunFiles(QStringList)));
    this->mainContext->addObject("proxy", proxy);
    PythonQt_init_PySocExplorer(0);
    PythonQt_init_PySocExplorerEngine(0);
    this->mainContext->evalScript(QString("from PythonQt import *"));
}

void PythonConsole::addObject(const QString& name, QObject* object)
{
    this->mainContext->addObject(name, object);
}

void PythonConsole::setBussDriver(socexplorerplugin *driver)
{
    this->bussdriver = driver;
    this->mainContext->addObject("buss", this->bussdriver);
}

void PythonConsole::registerObject(QObject* object,const QString& instanceName)
{
    this->mainContext->addObject(instanceName,object);
}

void PythonConsole::changeSysDriverInstName(const QString newinstanceName,const QString previnstanceName)
{
    socexplorerplugin* obj= this->proxy->getSysDriver(previnstanceName);
    if(obj==NULL)obj= this->proxy->getSysDriver(newinstanceName);
    if(obj==NULL)return;
    this->mainContext->addObject(newinstanceName,obj->getPyObjectWrapper());
    this->mainContext->removeVariable(previnstanceName);
}

void PythonConsole::removeDriver(const QString& instanceName)
{
    this->mainContext->removeVariable(instanceName);
}

void PythonConsole::removeBussDriver()
{
    this->bussdriver = 0;
    this->mainContext->removeVariable("buss");
    emit this->rootDriverDelete();
}


void PythonConsole::pyConsoleRunFiles(const QStringList & pathList)
{
    for (int i = 0; i < pathList.size() && i < 32; ++i)
    {
        this->pyConsoleRunFile(pathList.at(i));
    }
}

void PythonConsole::pyConsoleRunFile(const QString& fileName)
{
    QString code;
    QFile file;
    QFileInfo fileinfo;

    code.clear();
    file.setFileName(fileName);
    fileinfo.setFile(fileName);
    if(!fileinfo.suffix().compare("py"))
    {
        QString CMD="execfile(\'"+fileName+"\')";
        this->console->executePythonCommand(CMD);
    }
}


QSize PythonConsole::sizeHint()
{
    return QSize(800,80);
}








