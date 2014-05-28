#include "PySocExplorer0.h"
#include <PythonQtConversion.h>
#include <PythonQtMethodInfo.h>
#include <PythonQtSignalReceiver.h>
#include <QVariant>
#include <elffile.h>

ElfFile* PythonQtWrapper_ElfFile::new_ElfFile(QObject*  parent)
{ 
return new ElfFile(parent); }

ElfFile* PythonQtWrapper_ElfFile::new_ElfFile(const QString&  File, QObject*  parent)
{ 
return new ElfFile(File, parent); }

int  PythonQtWrapper_ElfFile::closeFile(ElfFile* theWrappedObject)
{
  return ( theWrappedObject->closeFile());
}

bool  PythonQtWrapper_ElfFile::isopened(ElfFile* theWrappedObject)
{
  return ( theWrappedObject->isopened());
}

bool  PythonQtWrapper_ElfFile::openFile(ElfFile* theWrappedObject, const QString&  File)
{
  return ( theWrappedObject->openFile(File));
}



MemSizeWdgt* PythonQtWrapper_MemSizeWdgt::new_MemSizeWdgt(QWidget*  parent)
{ 
return new MemSizeWdgt(parent); }

MemSizeWdgt* PythonQtWrapper_MemSizeWdgt::new_MemSizeWdgt(int  defaultSize, QWidget*  parent)
{ 
return new MemSizeWdgt(defaultSize, parent); }

int  PythonQtWrapper_MemSizeWdgt::getsize(MemSizeWdgt* theWrappedObject)
{
  return ( theWrappedObject->getsize());
}

void PythonQtWrapper_MemSizeWdgt::setMaximum(MemSizeWdgt* theWrappedObject, unsigned int  max)
{
  ( theWrappedObject->setMaximum(max));
}

void PythonQtWrapper_MemSizeWdgt::show(MemSizeWdgt* theWrappedObject)
{
  ( theWrappedObject->show());
}

void PythonQtWrapper_MemSizeWdgt::updateSizeValue(MemSizeWdgt* theWrappedObject)
{
  ( theWrappedObject->updateSizeValue());
}



PythonQtShell_QHexEdit::~PythonQtShell_QHexEdit() {
  PythonQtPrivate* priv = PythonQt::priv();
  if (priv) { priv->shellClassDeleted(this); }
}
QHexEdit* PythonQtWrapper_QHexEdit::new_QHexEdit(QWidget*  parent)
{ 
return new PythonQtShell_QHexEdit(parent); }

QColor  PythonQtWrapper_QHexEdit::addressAreaColor(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->addressAreaColor());
}

int  PythonQtWrapper_QHexEdit::addressOffset(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->addressOffset());
}

int  PythonQtWrapper_QHexEdit::cursorPosition(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->cursorPosition());
}

QByteArray  PythonQtWrapper_QHexEdit::data(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->data());
}

const QFont*  PythonQtWrapper_QHexEdit::font(QHexEdit* theWrappedObject) const
{
  return &( theWrappedObject->font());
}

QColor  PythonQtWrapper_QHexEdit::highlightingColor(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->highlightingColor());
}

int  PythonQtWrapper_QHexEdit::indexOf(QHexEdit* theWrappedObject, const QByteArray&  ba, int  from) const
{
  return ( theWrappedObject->indexOf(ba, from));
}

void PythonQtWrapper_QHexEdit::insert(QHexEdit* theWrappedObject, int  i, char  ch)
{
  ( theWrappedObject->insert(i, ch));
}

void PythonQtWrapper_QHexEdit::insert(QHexEdit* theWrappedObject, int  i, const QByteArray&  ba)
{
  ( theWrappedObject->insert(i, ba));
}

bool  PythonQtWrapper_QHexEdit::isReadOnly(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->isReadOnly());
}

int  PythonQtWrapper_QHexEdit::lastIndexOf(QHexEdit* theWrappedObject, const QByteArray&  ba, int  from) const
{
  return ( theWrappedObject->lastIndexOf(ba, from));
}

bool  PythonQtWrapper_QHexEdit::overwriteMode(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->overwriteMode());
}

void PythonQtWrapper_QHexEdit::remove(QHexEdit* theWrappedObject, int  pos, int  len)
{
  ( theWrappedObject->remove(pos, len));
}

void PythonQtWrapper_QHexEdit::replace(QHexEdit* theWrappedObject, int  pos, int  len, const QByteArray&  after)
{
  ( theWrappedObject->replace(pos, len, after));
}

QColor  PythonQtWrapper_QHexEdit::selectionColor(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->selectionColor());
}

QString  PythonQtWrapper_QHexEdit::selectionToReadableString(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->selectionToReadableString());
}

void PythonQtWrapper_QHexEdit::setAddressAreaColor(QHexEdit* theWrappedObject, const QColor&  color)
{
  ( theWrappedObject->setAddressAreaColor(color));
}

void PythonQtWrapper_QHexEdit::setAddressOffset(QHexEdit* theWrappedObject, int  offset)
{
  ( theWrappedObject->setAddressOffset(offset));
}

void PythonQtWrapper_QHexEdit::setCursorPosition(QHexEdit* theWrappedObject, int  cusorPos)
{
  ( theWrappedObject->setCursorPosition(cusorPos));
}

void PythonQtWrapper_QHexEdit::setData(QHexEdit* theWrappedObject, const QByteArray&  data)
{
  ( theWrappedObject->setData(data));
}

void PythonQtWrapper_QHexEdit::setFont(QHexEdit* theWrappedObject, const QFont&  arg__1)
{
  ( theWrappedObject->setFont(arg__1));
}

void PythonQtWrapper_QHexEdit::setHighlightingColor(QHexEdit* theWrappedObject, const QColor&  color)
{
  ( theWrappedObject->setHighlightingColor(color));
}

void PythonQtWrapper_QHexEdit::setOverwriteMode(QHexEdit* theWrappedObject, bool  arg__1)
{
  ( theWrappedObject->setOverwriteMode(arg__1));
}

void PythonQtWrapper_QHexEdit::setReadOnly(QHexEdit* theWrappedObject, bool  arg__1)
{
  ( theWrappedObject->setReadOnly(arg__1));
}

void PythonQtWrapper_QHexEdit::setSelectionColor(QHexEdit* theWrappedObject, const QColor&  color)
{
  ( theWrappedObject->setSelectionColor(color));
}

QString  PythonQtWrapper_QHexEdit::toReadableString(QHexEdit* theWrappedObject)
{
  return ( theWrappedObject->toReadableString());
}



QHexSpinBox* PythonQtWrapper_QHexSpinBox::new_QHexSpinBox(QWidget*  parent)
{ 
return new QHexSpinBox(parent); }

void PythonQtWrapper_QHexSpinBox::show(QHexSpinBox* theWrappedObject)
{
  ( theWrappedObject->show());
}

QString  PythonQtWrapper_QHexSpinBox::textFromValue(QHexSpinBox* theWrappedObject, int  value) const
{
  return ( theWrappedObject->textFromValue(value));
}

QValidator::State  PythonQtWrapper_QHexSpinBox::validate(QHexSpinBox* theWrappedObject, QString&  input, int&  pos) const
{
  return ( theWrappedObject->validate(input, pos));
}

int  PythonQtWrapper_QHexSpinBox::valueFromText(QHexSpinBox* theWrappedObject, const QString&  text) const
{
  return ( theWrappedObject->valueFromText(text));
}



PythonQtShell_SocExplorerPlot::~PythonQtShell_SocExplorerPlot() {
  PythonQtPrivate* priv = PythonQt::priv();
  if (priv) { priv->shellClassDeleted(this); }
}
SocExplorerPlot* PythonQtWrapper_SocExplorerPlot::new_SocExplorerPlot(QWidget*  parent)
{ 
return new PythonQtShell_SocExplorerPlot(parent); }

int  PythonQtWrapper_SocExplorerPlot::addGraph(SocExplorerPlot* theWrappedObject)
{
  return ( theWrappedObject->addGraph());
}

void PythonQtWrapper_SocExplorerPlot::addGraphData(SocExplorerPlot* theWrappedObject, int  graphIndex, QList<QVariant >  x, QList<QVariant >  y)
{
  ( theWrappedObject->addGraphData(graphIndex, x, y));
}

void PythonQtWrapper_SocExplorerPlot::addGraphData(SocExplorerPlot* theWrappedObject, int  graphIndex, QVariant  x, QVariant  y)
{
  ( theWrappedObject->addGraphData(graphIndex, x, y));
}

QPen  PythonQtWrapper_SocExplorerPlot::getGraphPen(SocExplorerPlot* theWrappedObject, int  graphIndex)
{
  return ( theWrappedObject->getGraphPen(graphIndex));
}

void PythonQtWrapper_SocExplorerPlot::rescaleAxis(SocExplorerPlot* theWrappedObject)
{
  ( theWrappedObject->rescaleAxis());
}

void PythonQtWrapper_SocExplorerPlot::setAdaptativeSampling(SocExplorerPlot* theWrappedObject, int  graphIndex, bool  enable)
{
  ( theWrappedObject->setAdaptativeSampling(graphIndex, enable));
}

void PythonQtWrapper_SocExplorerPlot::setGraphData(SocExplorerPlot* theWrappedObject, int  graphIndex, QList<QVariant >  x, QList<QVariant >  y)
{
  ( theWrappedObject->setGraphData(graphIndex, x, y));
}

void PythonQtWrapper_SocExplorerPlot::setGraphLineStyle(SocExplorerPlot* theWrappedObject, int  graphIndex, QString  lineStyle)
{
  ( theWrappedObject->setGraphLineStyle(graphIndex, lineStyle));
}

void PythonQtWrapper_SocExplorerPlot::setGraphName(SocExplorerPlot* theWrappedObject, int  graphIndex, QString  name)
{
  ( theWrappedObject->setGraphName(graphIndex, name));
}

void PythonQtWrapper_SocExplorerPlot::setGraphPen(SocExplorerPlot* theWrappedObject, int  graphIndex, QPen  pen)
{
  ( theWrappedObject->setGraphPen(graphIndex, pen));
}

void PythonQtWrapper_SocExplorerPlot::setGraphScatterStyle(SocExplorerPlot* theWrappedObject, int  graphIndex, QString  scatterStyle)
{
  ( theWrappedObject->setGraphScatterStyle(graphIndex, scatterStyle));
}

void PythonQtWrapper_SocExplorerPlot::setLegendFont(SocExplorerPlot* theWrappedObject, QFont  font)
{
  ( theWrappedObject->setLegendFont(font));
}

void PythonQtWrapper_SocExplorerPlot::setLegendSelectedFont(SocExplorerPlot* theWrappedObject, QFont  font)
{
  ( theWrappedObject->setLegendSelectedFont(font));
}

void PythonQtWrapper_SocExplorerPlot::setTitle(SocExplorerPlot* theWrappedObject, QString  title)
{
  ( theWrappedObject->setTitle(title));
}

void PythonQtWrapper_SocExplorerPlot::setXaxisLabel(SocExplorerPlot* theWrappedObject, QString  label)
{
  ( theWrappedObject->setXaxisLabel(label));
}

void PythonQtWrapper_SocExplorerPlot::setXaxisRange(SocExplorerPlot* theWrappedObject, double  lower, double  upper)
{
  ( theWrappedObject->setXaxisRange(lower, upper));
}

void PythonQtWrapper_SocExplorerPlot::setYaxisLabel(SocExplorerPlot* theWrappedObject, QString  label)
{
  ( theWrappedObject->setYaxisLabel(label));
}

void PythonQtWrapper_SocExplorerPlot::setYaxisRange(SocExplorerPlot* theWrappedObject, double  lower, double  upper)
{
  ( theWrappedObject->setYaxisRange(lower, upper));
}

void PythonQtWrapper_SocExplorerPlot::show(SocExplorerPlot* theWrappedObject)
{
  ( theWrappedObject->show());
}



TCP_Terminal_Client* PythonQtWrapper_TCP_Terminal_Client::new_TCP_Terminal_Client(QObject*  parent)
{ 
return new TCP_Terminal_Client(parent); }

void PythonQtWrapper_TCP_Terminal_Client::connectToServer(TCP_Terminal_Client* theWrappedObject)
{
  ( theWrappedObject->connectToServer());
}

void PythonQtWrapper_TCP_Terminal_Client::connectToServer(TCP_Terminal_Client* theWrappedObject, const QString&  IP, int  port)
{
  ( theWrappedObject->connectToServer(IP, port));
}

bool  PythonQtWrapper_TCP_Terminal_Client::isConnected(TCP_Terminal_Client* theWrappedObject)
{
  return ( theWrappedObject->isConnected());
}

void PythonQtWrapper_TCP_Terminal_Client::sendText(TCP_Terminal_Client* theWrappedObject, const QString&  text)
{
  ( theWrappedObject->sendText(text));
}

void PythonQtWrapper_TCP_Terminal_Client::startServer(TCP_Terminal_Client* theWrappedObject)
{
  ( theWrappedObject->startServer());
}

void PythonQtWrapper_TCP_Terminal_Client::startServer(TCP_Terminal_Client* theWrappedObject, int  port)
{
  ( theWrappedObject->startServer(port));
}



XByteArray* PythonQtWrapper_XByteArray::new_XByteArray()
{ 
return new XByteArray(); }

int  PythonQtWrapper_XByteArray::addressOffset(XByteArray* theWrappedObject)
{
  return ( theWrappedObject->addressOffset());
}

int  PythonQtWrapper_XByteArray::addressWidth(XByteArray* theWrappedObject)
{
  return ( theWrappedObject->addressWidth());
}

QChar  PythonQtWrapper_XByteArray::asciiChar(XByteArray* theWrappedObject, int  index)
{
  return ( theWrappedObject->asciiChar(index));
}

QByteArray*  PythonQtWrapper_XByteArray::data(XByteArray* theWrappedObject)
{
  return &( theWrappedObject->data());
}

bool  PythonQtWrapper_XByteArray::dataChanged(XByteArray* theWrappedObject, int  i)
{
  return ( theWrappedObject->dataChanged(i));
}

QByteArray  PythonQtWrapper_XByteArray::dataChanged(XByteArray* theWrappedObject, int  i, int  len)
{
  return ( theWrappedObject->dataChanged(i, len));
}

QByteArray*  PythonQtWrapper_XByteArray::insert(XByteArray* theWrappedObject, int  i, char  ch)
{
  return &( theWrappedObject->insert(i, ch));
}

QByteArray*  PythonQtWrapper_XByteArray::insert(XByteArray* theWrappedObject, int  i, const QByteArray&  ba)
{
  return &( theWrappedObject->insert(i, ba));
}

int  PythonQtWrapper_XByteArray::realAddressNumbers(XByteArray* theWrappedObject)
{
  return ( theWrappedObject->realAddressNumbers());
}

QByteArray*  PythonQtWrapper_XByteArray::remove(XByteArray* theWrappedObject, int  pos, int  len)
{
  return &( theWrappedObject->remove(pos, len));
}

QByteArray*  PythonQtWrapper_XByteArray::replace(XByteArray* theWrappedObject, int  index, char  ch)
{
  return &( theWrappedObject->replace(index, ch));
}

QByteArray*  PythonQtWrapper_XByteArray::replace(XByteArray* theWrappedObject, int  index, const QByteArray&  ba)
{
  return &( theWrappedObject->replace(index, ba));
}

QByteArray*  PythonQtWrapper_XByteArray::replace(XByteArray* theWrappedObject, int  index, int  length, const QByteArray&  ba)
{
  return &( theWrappedObject->replace(index, length, ba));
}

void PythonQtWrapper_XByteArray::setAddressOffset(XByteArray* theWrappedObject, int  offset)
{
  ( theWrappedObject->setAddressOffset(offset));
}

void PythonQtWrapper_XByteArray::setAddressWidth(XByteArray* theWrappedObject, int  width)
{
  ( theWrappedObject->setAddressWidth(width));
}

void PythonQtWrapper_XByteArray::setData(XByteArray* theWrappedObject, QByteArray  data)
{
  ( theWrappedObject->setData(data));
}

void PythonQtWrapper_XByteArray::setDataChanged(XByteArray* theWrappedObject, int  i, bool  state)
{
  ( theWrappedObject->setDataChanged(i, state));
}

void PythonQtWrapper_XByteArray::setDataChanged(XByteArray* theWrappedObject, int  i, const QByteArray&  state)
{
  ( theWrappedObject->setDataChanged(i, state));
}

int  PythonQtWrapper_XByteArray::size(XByteArray* theWrappedObject)
{
  return ( theWrappedObject->size());
}

QString  PythonQtWrapper_XByteArray::toRedableString(XByteArray* theWrappedObject, int  start, int  end)
{
  return ( theWrappedObject->toRedableString(start, end));
}



elfFileWidget* PythonQtWrapper_elfFileWidget::new_elfFileWidget(QWidget*  parent)
{ 
return new elfFileWidget(parent); }



elfparser* PythonQtWrapper_elfparser::new_elfparser()
{ 
return new elfparser(); }

int  PythonQtWrapper_elfparser::closeFile(elfparser* theWrappedObject)
{
  return ( theWrappedObject->closeFile());
}

QString  PythonQtWrapper_elfparser::getABI(elfparser* theWrappedObject)
{
  return ( theWrappedObject->getABI());
}

QString  PythonQtWrapper_elfparser::getArchitecture(elfparser* theWrappedObject)
{
  return ( theWrappedObject->getArchitecture());
}

QString  PythonQtWrapper_elfparser::getClass(elfparser* theWrappedObject)
{
  return ( theWrappedObject->getClass());
}

QString  PythonQtWrapper_elfparser::getEndianness(elfparser* theWrappedObject)
{
  return ( theWrappedObject->getEndianness());
}

bool  PythonQtWrapper_elfparser::getSectionData(elfparser* theWrappedObject, int  index, char**  buffer)
{
  return ( theWrappedObject->getSectionData(index, buffer));
}

QString  PythonQtWrapper_elfparser::getSectionName(elfparser* theWrappedObject, int  index)
{
  return ( theWrappedObject->getSectionName(index));
}

QString  PythonQtWrapper_elfparser::getSectionType(elfparser* theWrappedObject, int  index)
{
  return ( theWrappedObject->getSectionType(index));
}

int  PythonQtWrapper_elfparser::getSectioncount(elfparser* theWrappedObject)
{
  return ( theWrappedObject->getSectioncount());
}

QString  PythonQtWrapper_elfparser::getSegmentFlags(elfparser* theWrappedObject, int  index)
{
  return ( theWrappedObject->getSegmentFlags(index));
}

QString  PythonQtWrapper_elfparser::getSegmentType(elfparser* theWrappedObject, int  index)
{
  return ( theWrappedObject->getSegmentType(index));
}

int  PythonQtWrapper_elfparser::getSegmentcount(elfparser* theWrappedObject)
{
  return ( theWrappedObject->getSegmentcount());
}

QString  PythonQtWrapper_elfparser::getType(elfparser* theWrappedObject)
{
  return ( theWrappedObject->getType());
}

bool  PythonQtWrapper_elfparser::static_elfparser_isElf(const QString&  File)
{
  return (elfparser::isElf(File));
}

bool  PythonQtWrapper_elfparser::iself(elfparser* theWrappedObject)
{
  return ( theWrappedObject->iself());
}

bool  PythonQtWrapper_elfparser::isopened(elfparser* theWrappedObject)
{
  return ( theWrappedObject->isopened());
}

int  PythonQtWrapper_elfparser::setFilename(elfparser* theWrappedObject, const QString&  name)
{
  return ( theWrappedObject->setFilename(name));
}


