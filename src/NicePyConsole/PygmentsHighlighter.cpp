/*! \file PygmentsHighlighter.cpp
 * \brief implements PygmentsHighlighter
 * \author "Melven Zoellner" <melven@topen.org>
 *
*/
#include "PygmentsHighlighter.h"
#include <QApplication>

#include <PythonQt.h>
#include <socexplorer.h>
#include <QFile>
#include <QFileInfo>

PygmentsHighlighter::PygmentsHighlighter(QTextDocument *parentDoc) :
    QSyntaxHighlighter(parentDoc)
{
    // create an own pythonqt context for the highlighter
    _context = PythonQt::self()->createUniqueModule();

    // name this object
    setObjectName("pygmentsHighlighter");

    // make it accessable in pythonqt,
    // this allows to delegate the work in highlightBlock
    // to a python function
    _context.addObject(objectName(),this);

    // initialize python
    QString fileName = QString(PYMODULES)+"/PygmentsHighlighter.py";
    QString code;
    QFile file;
    QFileInfo fileinfo;

    code.clear();
    file.setFileName(fileName);
    fileinfo.setFile(fileName);
    if(!fileinfo.suffix().compare("py"))
    {
        file.open(QIODevice::ReadOnly);
        QTextStream filestrm(&file);
        while(!filestrm.atEnd())code.append(filestrm.readLine()+"\n");
        _context.evalScript(code);
        file.close();
        // this->mainContext->evalFile(pathList.at(i));
    }
    //_context.evalFile(QString(PYMODULES)+"/PygmentsHighlighter.py");
}


// just delegate the protected method setFormat from base class
void PygmentsHighlighter::_setFormat(int start, int count, const QTextCharFormat &format)
{
    setFormat(start, count, format);
}


void PygmentsHighlighter::highlightBlock(const QString &text)
{
    // call python function to do everything
    QVariantList args;
    args.append(text);
    _context.call("highlightCode", args);
}
