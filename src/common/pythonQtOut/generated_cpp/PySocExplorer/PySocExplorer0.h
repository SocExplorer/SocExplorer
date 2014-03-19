#include <PythonQt.h>
#include <QObject>
#include <QVariant>
#include <SocExplorerPlot.h>
#include <elfparser.h>
#include <memsizewdgt.h>
#include <qhexedit.h>
#include <qhexspinbox.h>
#include <tcp_terminal_client.h>
#include <xbytearray.h>



class PythonQtWrapper_MemSizeWdgt : public QObject
{ Q_OBJECT
public:
public slots:
MemSizeWdgt* new_MemSizeWdgt(QWidget*  parent = 0);
MemSizeWdgt* new_MemSizeWdgt(int  defaultSize, QWidget*  parent = 0);
void delete_MemSizeWdgt(MemSizeWdgt* obj) { delete obj; } 
   int  getsize(MemSizeWdgt* theWrappedObject);
   void setMaximum(MemSizeWdgt* theWrappedObject, unsigned int  max);
   void show(MemSizeWdgt* theWrappedObject);
   void updateSizeValue(MemSizeWdgt* theWrappedObject);
};





class PythonQtShell_QHexEdit : public QHexEdit
{
public:
    PythonQtShell_QHexEdit(QWidget*  parent = 0):QHexEdit(parent),_wrapper(NULL) {};

   ~PythonQtShell_QHexEdit();


  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtWrapper_QHexEdit : public QObject
{ Q_OBJECT
public:
public slots:
QHexEdit* new_QHexEdit(QWidget*  parent = 0);
void delete_QHexEdit(QHexEdit* obj) { delete obj; } 
   QColor  addressAreaColor(QHexEdit* theWrappedObject);
   int  addressOffset(QHexEdit* theWrappedObject);
   int  cursorPosition(QHexEdit* theWrappedObject);
   QByteArray  data(QHexEdit* theWrappedObject);
   const QFont*  font(QHexEdit* theWrappedObject) const;
   QColor  highlightingColor(QHexEdit* theWrappedObject);
   int  indexOf(QHexEdit* theWrappedObject, const QByteArray&  ba, int  from = 0) const;
   void insert(QHexEdit* theWrappedObject, int  i, char  ch);
   void insert(QHexEdit* theWrappedObject, int  i, const QByteArray&  ba);
   bool  isReadOnly(QHexEdit* theWrappedObject);
   int  lastIndexOf(QHexEdit* theWrappedObject, const QByteArray&  ba, int  from = 0) const;
   bool  overwriteMode(QHexEdit* theWrappedObject);
   void remove(QHexEdit* theWrappedObject, int  pos, int  len = 1);
   void replace(QHexEdit* theWrappedObject, int  pos, int  len, const QByteArray&  after);
   QColor  selectionColor(QHexEdit* theWrappedObject);
   QString  selectionToReadableString(QHexEdit* theWrappedObject);
   void setAddressAreaColor(QHexEdit* theWrappedObject, const QColor&  color);
   void setAddressOffset(QHexEdit* theWrappedObject, int  offset);
   void setCursorPosition(QHexEdit* theWrappedObject, int  cusorPos);
   void setData(QHexEdit* theWrappedObject, const QByteArray&  data);
   void setFont(QHexEdit* theWrappedObject, const QFont&  arg__1);
   void setHighlightingColor(QHexEdit* theWrappedObject, const QColor&  color);
   void setOverwriteMode(QHexEdit* theWrappedObject, bool  arg__1);
   void setReadOnly(QHexEdit* theWrappedObject, bool  arg__1);
   void setSelectionColor(QHexEdit* theWrappedObject, const QColor&  color);
   QString  toReadableString(QHexEdit* theWrappedObject);
};





class PythonQtWrapper_QHexSpinBox : public QObject
{ Q_OBJECT
public:
public slots:
QHexSpinBox* new_QHexSpinBox(QWidget*  parent = 0);
void delete_QHexSpinBox(QHexSpinBox* obj) { delete obj; } 
   void show(QHexSpinBox* theWrappedObject);
   QString  textFromValue(QHexSpinBox* theWrappedObject, int  value) const;
   QValidator::State  validate(QHexSpinBox* theWrappedObject, QString&  input, int&  pos) const;
   int  valueFromText(QHexSpinBox* theWrappedObject, const QString&  text) const;
};





class PythonQtShell_SocExplorerPlot : public SocExplorerPlot
{
public:
    PythonQtShell_SocExplorerPlot(QWidget*  parent = 0):SocExplorerPlot(parent),_wrapper(NULL) {};

   ~PythonQtShell_SocExplorerPlot();


  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtWrapper_SocExplorerPlot : public QObject
{ Q_OBJECT
public:
public slots:
SocExplorerPlot* new_SocExplorerPlot(QWidget*  parent = 0);
void delete_SocExplorerPlot(SocExplorerPlot* obj) { delete obj; } 
   int  addGraph(SocExplorerPlot* theWrappedObject);
   void addGraphData(SocExplorerPlot* theWrappedObject, int  graphIndex, QList<QVariant >  x, QList<QVariant >  y);
   void addGraphData(SocExplorerPlot* theWrappedObject, int  graphIndex, QVariant  x, QVariant  y);
   QPen  getGraphPen(SocExplorerPlot* theWrappedObject, int  graphIndex);
   void rescaleAxis(SocExplorerPlot* theWrappedObject);
   void setAdaptativeSampling(SocExplorerPlot* theWrappedObject, int  graphIndex, bool  enable);
   void setGraphData(SocExplorerPlot* theWrappedObject, int  graphIndex, QList<QVariant >  x, QList<QVariant >  y);
   void setGraphLineStyle(SocExplorerPlot* theWrappedObject, int  graphIndex, QString  lineStyle);
   void setGraphName(SocExplorerPlot* theWrappedObject, int  graphIndex, QString  name);
   void setGraphPen(SocExplorerPlot* theWrappedObject, int  graphIndex, QPen  pen);
   void setGraphScatterStyle(SocExplorerPlot* theWrappedObject, int  graphIndex, QString  scatterStyle);
   void setLegendFont(SocExplorerPlot* theWrappedObject, QFont  font);
   void setLegendSelectedFont(SocExplorerPlot* theWrappedObject, QFont  font);
   void setTitle(SocExplorerPlot* theWrappedObject, QString  title);
   void setXaxisLabel(SocExplorerPlot* theWrappedObject, QString  label);
   void setXaxisRange(SocExplorerPlot* theWrappedObject, double  lower, double  upper);
   void setYaxisLabel(SocExplorerPlot* theWrappedObject, QString  label);
   void setYaxisRange(SocExplorerPlot* theWrappedObject, double  lower, double  upper);
   void show(SocExplorerPlot* theWrappedObject);
};





class PythonQtWrapper_TCP_Terminal_Client : public QObject
{ Q_OBJECT
public:
public slots:
TCP_Terminal_Client* new_TCP_Terminal_Client(QObject*  parent = 0);
void delete_TCP_Terminal_Client(TCP_Terminal_Client* obj) { delete obj; } 
   void connectToServer(TCP_Terminal_Client* theWrappedObject);
   void connectToServer(TCP_Terminal_Client* theWrappedObject, const QString&  IP, int  port);
   bool  isConnected(TCP_Terminal_Client* theWrappedObject);
   void sendText(TCP_Terminal_Client* theWrappedObject, const QString&  text);
   void startServer(TCP_Terminal_Client* theWrappedObject);
   void startServer(TCP_Terminal_Client* theWrappedObject, int  port);
};





class PythonQtWrapper_XByteArray : public QObject
{ Q_OBJECT
public:
public slots:
XByteArray* new_XByteArray();
void delete_XByteArray(XByteArray* obj) { delete obj; } 
   int  addressOffset(XByteArray* theWrappedObject);
   int  addressWidth(XByteArray* theWrappedObject);
   QChar  asciiChar(XByteArray* theWrappedObject, int  index);
   QByteArray*  data(XByteArray* theWrappedObject);
   bool  dataChanged(XByteArray* theWrappedObject, int  i);
   QByteArray  dataChanged(XByteArray* theWrappedObject, int  i, int  len);
   QByteArray*  insert(XByteArray* theWrappedObject, int  i, char  ch);
   QByteArray*  insert(XByteArray* theWrappedObject, int  i, const QByteArray&  ba);
   int  realAddressNumbers(XByteArray* theWrappedObject);
   QByteArray*  remove(XByteArray* theWrappedObject, int  pos, int  len);
   QByteArray*  replace(XByteArray* theWrappedObject, int  index, char  ch);
   QByteArray*  replace(XByteArray* theWrappedObject, int  index, const QByteArray&  ba);
   QByteArray*  replace(XByteArray* theWrappedObject, int  index, int  length, const QByteArray&  ba);
   void setAddressOffset(XByteArray* theWrappedObject, int  offset);
   void setAddressWidth(XByteArray* theWrappedObject, int  width);
   void setData(XByteArray* theWrappedObject, QByteArray  data);
   void setDataChanged(XByteArray* theWrappedObject, int  i, bool  state);
   void setDataChanged(XByteArray* theWrappedObject, int  i, const QByteArray&  state);
   int  size(XByteArray* theWrappedObject);
   QString  toRedableString(XByteArray* theWrappedObject, int  start = 0, int  end = -1);
};





class PythonQtWrapper_elfparser : public QObject
{ Q_OBJECT
public:
public slots:
elfparser* new_elfparser();
void delete_elfparser(elfparser* obj) { delete obj; } 
   int  closeFile(elfparser* theWrappedObject);
   QString  getArchitecture(elfparser* theWrappedObject);
   bool  getSectionData(elfparser* theWrappedObject, int  index, char**  buffer);
   QString  getSectionName(elfparser* theWrappedObject, int  index);
   QString  getSectionType(elfparser* theWrappedObject, int  index);
   int  getSectioncount(elfparser* theWrappedObject);
   QString  getSegmentFlags(elfparser* theWrappedObject, int  index);
   QString  getSegmentType(elfparser* theWrappedObject, int  index);
   int  getSegmentcount(elfparser* theWrappedObject);
   QString  getType(elfparser* theWrappedObject);
   bool  static_elfparser_isElf(const QString&  File);
   bool  iself(elfparser* theWrappedObject);
   bool  isopened(elfparser* theWrappedObject);
   int  setFilename(elfparser* theWrappedObject, const QString&  name);
};


