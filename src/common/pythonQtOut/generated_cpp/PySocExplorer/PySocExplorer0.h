#include <PythonQt.h>
#include <QIconEngine>
#include <QObject>
#include <QSpinBox>
#include <QVariant>
#include <QWidget>
#include <SocExplorerPlot.h>
#include <abstractexecfile.h>
#include <elffile.h>
#include <elffilewidget.h>
#include <elfinfowdgt.h>
#include <elfparser.h>
#include <memsizewdgt.h>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcolor.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qevent.h>
#include <qfont.h>
#include <qgraphicseffect.h>
#include <qgraphicsproxywidget.h>
#include <qhexedit.h>
#include <qhexspinbox.h>
#include <qkeysequence.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlist.h>
#include <qlocale.h>
#include <qmargins.h>
#include <qobject.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpen.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qscrollarea.h>
#include <qscrollbar.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qspinbox.h>
#include <qstringlist.h>
#include <qstyle.h>
#include <qstyleoption.h>
#include <qwidget.h>
#include <tcp_terminal_client.h>
#include <xbytearray.h>



class PythonQtShell_ElfFile : public ElfFile
{
public:
    PythonQtShell_ElfFile():ElfFile(),_wrapper(NULL) {};
    PythonQtShell_ElfFile(const QString&  File):ElfFile(File),_wrapper(NULL) {};

   ~PythonQtShell_ElfFile();

virtual int  closeFile();
virtual QList<codeFragment* >  getFragments();
virtual bool  isopened();
virtual bool  openFile(const QString&  File);

  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtPublicPromoter_ElfFile : public ElfFile
{ public:
inline int  promoted_closeFile() { return ElfFile::closeFile(); }
inline QList<codeFragment* >  promoted_getFragments() { return ElfFile::getFragments(); }
inline bool  promoted_isopened() { return ElfFile::isopened(); }
inline bool  promoted_openFile(const QString&  File) { return ElfFile::openFile(File); }
};

class PythonQtWrapper_ElfFile : public QObject
{ Q_OBJECT
public:
public slots:
ElfFile* new_ElfFile();
ElfFile* new_ElfFile(const QString&  File);
void delete_ElfFile(ElfFile* obj) { delete obj; } 
   int  closeFile(ElfFile* theWrappedObject);
   QString  getABI(ElfFile* theWrappedObject);
   QString  getArchitecture(ElfFile* theWrappedObject);
   QString  getClass(ElfFile* theWrappedObject);
   QString  getEndianness(ElfFile* theWrappedObject);
   qint64  getEntryPointAddress(ElfFile* theWrappedObject);
   QList<codeFragment* >  getFragments(ElfFile* theWrappedObject);
   QList<codeFragment* >  getFragments(ElfFile* theWrappedObject, QStringList  fragmentList);
   int  getSectionCount(ElfFile* theWrappedObject);
   bool  getSectionData(ElfFile* theWrappedObject, int  index, char**  buffer);
   qint64  getSectionDatasz(ElfFile* theWrappedObject, int  index);
   int  getSectionIndex(ElfFile* theWrappedObject, QString  name);
   qint64  getSectionMemsz(ElfFile* theWrappedObject, int  index);
   QString  getSectionName(ElfFile* theWrappedObject, int  index);
   qint64  getSectionPaddr(ElfFile* theWrappedObject, int  index);
   QString  getSectionType(ElfFile* theWrappedObject, int  index);
   int  getSegmentCount(ElfFile* theWrappedObject);
   qint64  getSegmentFilesz(ElfFile* theWrappedObject, int  index);
   QString  getSegmentFlags(ElfFile* theWrappedObject, int  index);
   qint64  getSegmentMemsz(ElfFile* theWrappedObject, int  index);
   qint64  getSegmentOffset(ElfFile* theWrappedObject, int  index);
   qint64  getSegmentPaddr(ElfFile* theWrappedObject, int  index);
   QString  getSegmentType(ElfFile* theWrappedObject, int  index);
   qint64  getSegmentVaddr(ElfFile* theWrappedObject, int  index);
   quint64  getSymbolAddress(ElfFile* theWrappedObject, int  index);
   int  getSymbolCount(ElfFile* theWrappedObject);
   QString  getSymbolLinkType(ElfFile* theWrappedObject, int  index);
   QString  getSymbolName(ElfFile* theWrappedObject, int  index);
   int  getSymbolSectionIndex(ElfFile* theWrappedObject, int  index);
   QString  getSymbolSectionName(ElfFile* theWrappedObject, int  index);
   quint64  getSymbolSize(ElfFile* theWrappedObject, int  index);
   QString  getSymbolType(ElfFile* theWrappedObject, int  index);
   QString  getType(ElfFile* theWrappedObject);
   qint64  getVersion(ElfFile* theWrappedObject);
   bool  static_ElfFile_isElf(const QString&  File);
   bool  iself(ElfFile* theWrappedObject);
   bool  isopened(ElfFile* theWrappedObject);
   bool  openFile(ElfFile* theWrappedObject, const QString&  File);
};





class PythonQtShell_MemSizeWdgt : public MemSizeWdgt
{
public:
    PythonQtShell_MemSizeWdgt(QWidget*  parent = 0):MemSizeWdgt(parent),_wrapper(NULL) {};
    PythonQtShell_MemSizeWdgt(int  defaultSize, QWidget*  parent = 0):MemSizeWdgt(defaultSize, parent),_wrapper(NULL) {};

   ~PythonQtShell_MemSizeWdgt();

virtual void actionEvent(QActionEvent*  arg__1);
virtual void changeEvent(QEvent*  arg__1);
virtual void childEvent(QChildEvent*  arg__1);
virtual void closeEvent(QCloseEvent*  arg__1);
virtual void contextMenuEvent(QContextMenuEvent*  arg__1);
virtual void customEvent(QEvent*  arg__1);
virtual int  devType() const;
virtual void dragEnterEvent(QDragEnterEvent*  arg__1);
virtual void dragLeaveEvent(QDragLeaveEvent*  arg__1);
virtual void dragMoveEvent(QDragMoveEvent*  arg__1);
virtual void dropEvent(QDropEvent*  arg__1);
virtual void enterEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  arg__1);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual void focusInEvent(QFocusEvent*  arg__1);
virtual bool  focusNextPrevChild(bool  next);
virtual void focusOutEvent(QFocusEvent*  arg__1);
virtual bool  hasHeightForWidth() const;
virtual int  heightForWidth(int  arg__1) const;
virtual void hideEvent(QHideEvent*  arg__1);
virtual void initPainter(QPainter*  painter) const;
virtual void inputMethodEvent(QInputMethodEvent*  arg__1);
virtual QVariant  inputMethodQuery(Qt::InputMethodQuery  arg__1) const;
virtual void keyPressEvent(QKeyEvent*  arg__1);
virtual void keyReleaseEvent(QKeyEvent*  arg__1);
virtual void leaveEvent(QEvent*  arg__1);
virtual int  metric(QPaintDevice::PaintDeviceMetric  arg__1) const;
virtual QSize  minimumSizeHint() const;
virtual void mouseDoubleClickEvent(QMouseEvent*  arg__1);
virtual void mouseMoveEvent(QMouseEvent*  arg__1);
virtual void mousePressEvent(QMouseEvent*  arg__1);
virtual void mouseReleaseEvent(QMouseEvent*  arg__1);
virtual void moveEvent(QMoveEvent*  arg__1);
virtual bool  nativeEvent(const QByteArray&  eventType, void*  message, long*  result);
virtual QPaintEngine*  paintEngine() const;
virtual void paintEvent(QPaintEvent*  arg__1);
virtual QPaintDevice*  redirected(QPoint*  offset) const;
virtual void resizeEvent(QResizeEvent*  arg__1);
virtual QPainter*  sharedPainter() const;
virtual void showEvent(QShowEvent*  arg__1);
virtual QSize  sizeHint() const;
virtual void tabletEvent(QTabletEvent*  arg__1);
virtual void timerEvent(QTimerEvent*  arg__1);
virtual void wheelEvent(QWheelEvent*  arg__1);

  PythonQtInstanceWrapper* _wrapper; 
};

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

virtual void actionEvent(QActionEvent*  arg__1);
virtual void changeEvent(QEvent*  arg__1);
virtual void childEvent(QChildEvent*  arg__1);
virtual void closeEvent(QCloseEvent*  arg__1);
virtual void contextMenuEvent(QContextMenuEvent*  arg__1);
virtual void customEvent(QEvent*  arg__1);
virtual int  devType() const;
virtual void dragEnterEvent(QDragEnterEvent*  arg__1);
virtual void dragLeaveEvent(QDragLeaveEvent*  arg__1);
virtual void dragMoveEvent(QDragMoveEvent*  arg__1);
virtual void dropEvent(QDropEvent*  arg__1);
virtual void enterEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  arg__1);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual void focusInEvent(QFocusEvent*  arg__1);
virtual bool  focusNextPrevChild(bool  next);
virtual void focusOutEvent(QFocusEvent*  arg__1);
virtual bool  hasHeightForWidth() const;
virtual int  heightForWidth(int  arg__1) const;
virtual void hideEvent(QHideEvent*  arg__1);
virtual void initPainter(QPainter*  painter) const;
virtual void inputMethodEvent(QInputMethodEvent*  arg__1);
virtual QVariant  inputMethodQuery(Qt::InputMethodQuery  arg__1) const;
virtual void keyPressEvent(QKeyEvent*  arg__1);
virtual void keyReleaseEvent(QKeyEvent*  arg__1);
virtual void leaveEvent(QEvent*  arg__1);
virtual int  metric(QPaintDevice::PaintDeviceMetric  arg__1) const;
virtual void mouseDoubleClickEvent(QMouseEvent*  arg__1);
virtual void mouseMoveEvent(QMouseEvent*  arg__1);
virtual void mousePressEvent(QMouseEvent*  arg__1);
virtual void mouseReleaseEvent(QMouseEvent*  arg__1);
virtual void moveEvent(QMoveEvent*  arg__1);
virtual bool  nativeEvent(const QByteArray&  eventType, void*  message, long*  result);
virtual QPaintEngine*  paintEngine() const;
virtual void paintEvent(QPaintEvent*  arg__1);
virtual QPaintDevice*  redirected(QPoint*  offset) const;
virtual void resizeEvent(QResizeEvent*  arg__1);
virtual void scrollContentsBy(int  dx, int  dy);
virtual void setupViewport(QWidget*  viewport);
virtual QPainter*  sharedPainter() const;
virtual void showEvent(QShowEvent*  arg__1);
virtual void tabletEvent(QTabletEvent*  arg__1);
virtual void timerEvent(QTimerEvent*  arg__1);
virtual bool  viewportEvent(QEvent*  arg__1);
virtual QSize  viewportSizeHint() const;
virtual void wheelEvent(QWheelEvent*  arg__1);

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





class PythonQtShell_QHexSpinBox : public QHexSpinBox
{
public:
    PythonQtShell_QHexSpinBox(QWidget*  parent = 0):QHexSpinBox(parent),_wrapper(NULL) {};

   ~PythonQtShell_QHexSpinBox();

virtual void actionEvent(QActionEvent*  arg__1);
virtual void changeEvent(QEvent*  event);
virtual void childEvent(QChildEvent*  arg__1);
virtual void clear();
virtual void closeEvent(QCloseEvent*  event);
virtual void contextMenuEvent(QContextMenuEvent*  event);
virtual void customEvent(QEvent*  arg__1);
virtual int  devType() const;
virtual void dragEnterEvent(QDragEnterEvent*  arg__1);
virtual void dragLeaveEvent(QDragLeaveEvent*  arg__1);
virtual void dragMoveEvent(QDragMoveEvent*  arg__1);
virtual void dropEvent(QDropEvent*  arg__1);
virtual void enterEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  event);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual void fixup(QString&  str) const;
virtual void focusInEvent(QFocusEvent*  event);
virtual bool  focusNextPrevChild(bool  next);
virtual void focusOutEvent(QFocusEvent*  event);
virtual bool  hasHeightForWidth() const;
virtual int  heightForWidth(int  arg__1) const;
virtual void hideEvent(QHideEvent*  event);
virtual void initPainter(QPainter*  painter) const;
virtual void inputMethodEvent(QInputMethodEvent*  arg__1);
virtual QVariant  inputMethodQuery(Qt::InputMethodQuery  arg__1) const;
virtual void keyPressEvent(QKeyEvent*  event);
virtual void keyReleaseEvent(QKeyEvent*  event);
virtual void leaveEvent(QEvent*  arg__1);
virtual int  metric(QPaintDevice::PaintDeviceMetric  arg__1) const;
virtual void mouseDoubleClickEvent(QMouseEvent*  arg__1);
virtual void mouseMoveEvent(QMouseEvent*  event);
virtual void mousePressEvent(QMouseEvent*  event);
virtual void mouseReleaseEvent(QMouseEvent*  event);
virtual void moveEvent(QMoveEvent*  arg__1);
virtual bool  nativeEvent(const QByteArray&  eventType, void*  message, long*  result);
virtual QPaintEngine*  paintEngine() const;
virtual void paintEvent(QPaintEvent*  event);
virtual QPaintDevice*  redirected(QPoint*  offset) const;
virtual void resizeEvent(QResizeEvent*  event);
virtual QPainter*  sharedPainter() const;
virtual void showEvent(QShowEvent*  event);
virtual void stepBy(int  steps);
virtual QAbstractSpinBox::StepEnabled  stepEnabled() const;
virtual void tabletEvent(QTabletEvent*  arg__1);
virtual QString  textFromValue(int  value) const;
virtual void timerEvent(QTimerEvent*  event);
virtual QValidator::State  validate(QString&  input, int&  pos) const;
virtual int  valueFromText(const QString&  text) const;
virtual void wheelEvent(QWheelEvent*  event);

  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtPublicPromoter_QHexSpinBox : public QHexSpinBox
{ public:
inline QString  promoted_textFromValue(int  value) const { return QHexSpinBox::textFromValue(value); }
inline QValidator::State  promoted_validate(QString&  input, int&  pos) const { return QHexSpinBox::validate(input, pos); }
inline int  promoted_valueFromText(const QString&  text) const { return QHexSpinBox::valueFromText(text); }
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

virtual void actionEvent(QActionEvent*  arg__1);
virtual void changeEvent(QEvent*  arg__1);
virtual void childEvent(QChildEvent*  arg__1);
virtual void closeEvent(QCloseEvent*  arg__1);
virtual void contextMenuEvent(QContextMenuEvent*  arg__1);
virtual void customEvent(QEvent*  arg__1);
virtual int  devType() const;
virtual void dragEnterEvent(QDragEnterEvent*  arg__1);
virtual void dragLeaveEvent(QDragLeaveEvent*  arg__1);
virtual void dragMoveEvent(QDragMoveEvent*  arg__1);
virtual void dropEvent(QDropEvent*  arg__1);
virtual void enterEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  arg__1);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual void focusInEvent(QFocusEvent*  arg__1);
virtual bool  focusNextPrevChild(bool  next);
virtual void focusOutEvent(QFocusEvent*  arg__1);
virtual bool  hasHeightForWidth() const;
virtual int  heightForWidth(int  arg__1) const;
virtual void hideEvent(QHideEvent*  arg__1);
virtual void initPainter(QPainter*  painter) const;
virtual void inputMethodEvent(QInputMethodEvent*  arg__1);
virtual QVariant  inputMethodQuery(Qt::InputMethodQuery  arg__1) const;
virtual void keyPressEvent(QKeyEvent*  arg__1);
virtual void keyReleaseEvent(QKeyEvent*  arg__1);
virtual void leaveEvent(QEvent*  arg__1);
virtual int  metric(QPaintDevice::PaintDeviceMetric  arg__1) const;
virtual QSize  minimumSizeHint() const;
virtual void mouseDoubleClickEvent(QMouseEvent*  arg__1);
virtual void mouseMoveEvent(QMouseEvent*  arg__1);
virtual void mousePressEvent(QMouseEvent*  arg__1);
virtual void mouseReleaseEvent(QMouseEvent*  arg__1);
virtual void moveEvent(QMoveEvent*  arg__1);
virtual bool  nativeEvent(const QByteArray&  eventType, void*  message, long*  result);
virtual QPaintEngine*  paintEngine() const;
virtual void paintEvent(QPaintEvent*  arg__1);
virtual QPaintDevice*  redirected(QPoint*  offset) const;
virtual void resizeEvent(QResizeEvent*  arg__1);
virtual QPainter*  sharedPainter() const;
virtual void showEvent(QShowEvent*  arg__1);
virtual QSize  sizeHint() const;
virtual void tabletEvent(QTabletEvent*  arg__1);
virtual void timerEvent(QTimerEvent*  arg__1);
virtual void wheelEvent(QWheelEvent*  arg__1);

  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtPublicPromoter_SocExplorerPlot : public SocExplorerPlot
{ public:
inline void promoted_keyPressEvent(QKeyEvent*  arg__1) { SocExplorerPlot::keyPressEvent(arg__1); }
inline void promoted_keyReleaseEvent(QKeyEvent*  arg__1) { SocExplorerPlot::keyReleaseEvent(arg__1); }
inline void promoted_mouseMoveEvent(QMouseEvent*  arg__1) { SocExplorerPlot::mouseMoveEvent(arg__1); }
inline void promoted_mousePressEvent(QMouseEvent*  arg__1) { SocExplorerPlot::mousePressEvent(arg__1); }
inline void promoted_mouseReleaseEvent(QMouseEvent*  arg__1) { SocExplorerPlot::mouseReleaseEvent(arg__1); }
inline void promoted_wheelEvent(QWheelEvent*  arg__1) { SocExplorerPlot::wheelEvent(arg__1); }
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
   void keyPressEvent(SocExplorerPlot* theWrappedObject, QKeyEvent*  arg__1);
   void keyReleaseEvent(SocExplorerPlot* theWrappedObject, QKeyEvent*  arg__1);
   void mouseMoveEvent(SocExplorerPlot* theWrappedObject, QMouseEvent*  arg__1);
   void mousePressEvent(SocExplorerPlot* theWrappedObject, QMouseEvent*  arg__1);
   void mouseReleaseEvent(SocExplorerPlot* theWrappedObject, QMouseEvent*  arg__1);
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
   void wheelEvent(SocExplorerPlot* theWrappedObject, QWheelEvent*  arg__1);
};





class PythonQtShell_TCP_Terminal_Client : public TCP_Terminal_Client
{
public:
    PythonQtShell_TCP_Terminal_Client(QObject*  parent = 0):TCP_Terminal_Client(parent),_wrapper(NULL) {};

   ~PythonQtShell_TCP_Terminal_Client();

virtual void childEvent(QChildEvent*  arg__1);
virtual void customEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  arg__1);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual void timerEvent(QTimerEvent*  arg__1);

  PythonQtInstanceWrapper* _wrapper; 
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





class PythonQtShell_abstractExecFile : public abstractExecFile
{
public:
    PythonQtShell_abstractExecFile():abstractExecFile(),_wrapper(NULL) {};

   ~PythonQtShell_abstractExecFile();

virtual void childEvent(QChildEvent*  arg__1);
virtual int  closeFile();
virtual void customEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  arg__1);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual QList<codeFragment* >  getFragments();
virtual bool  isopened();
virtual bool  openFile(const QString&  File);
virtual void timerEvent(QTimerEvent*  arg__1);

  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtWrapper_abstractExecFile : public QObject
{ Q_OBJECT
public:
public slots:
abstractExecFile* new_abstractExecFile();
void delete_abstractExecFile(abstractExecFile* obj) { delete obj; } 
};





class PythonQtShell_codeFragment : public codeFragment
{
public:
    PythonQtShell_codeFragment():codeFragment(),_wrapper(NULL) {};
    PythonQtShell_codeFragment(char*  data, unsigned int  size, unsigned int  address):codeFragment(data, size, address),_wrapper(NULL) {};

   ~PythonQtShell_codeFragment();


  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtWrapper_codeFragment : public QObject
{ Q_OBJECT
public:
public slots:
codeFragment* new_codeFragment();
codeFragment* new_codeFragment(char*  data, unsigned int  size, unsigned int  address);
void delete_codeFragment(codeFragment* obj) { delete obj; } 
void py_set_address(codeFragment* theWrappedObject, unsigned int  address){ theWrappedObject->address = address; }
unsigned int  py_get_address(codeFragment* theWrappedObject){ return theWrappedObject->address; }
void py_set_data(codeFragment* theWrappedObject, char*  data){ theWrappedObject->data = data; }
char*  py_get_data(codeFragment* theWrappedObject){ return theWrappedObject->data; }
void py_set_size(codeFragment* theWrappedObject, unsigned int  size){ theWrappedObject->size = size; }
unsigned int  py_get_size(codeFragment* theWrappedObject){ return theWrappedObject->size; }
};





class PythonQtShell_elfFileWidget : public elfFileWidget
{
public:
    PythonQtShell_elfFileWidget(QWidget*  parent = 0):elfFileWidget(parent),_wrapper(NULL) {};

   ~PythonQtShell_elfFileWidget();

virtual void actionEvent(QActionEvent*  arg__1);
virtual void changeEvent(QEvent*  arg__1);
virtual void childEvent(QChildEvent*  arg__1);
virtual void closeEvent(QCloseEvent*  arg__1);
virtual void contextMenuEvent(QContextMenuEvent*  arg__1);
virtual void customEvent(QEvent*  arg__1);
virtual int  devType() const;
virtual void dragEnterEvent(QDragEnterEvent*  arg__1);
virtual void dragLeaveEvent(QDragLeaveEvent*  arg__1);
virtual void dragMoveEvent(QDragMoveEvent*  arg__1);
virtual void dropEvent(QDropEvent*  arg__1);
virtual void enterEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  arg__1);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual void focusInEvent(QFocusEvent*  arg__1);
virtual bool  focusNextPrevChild(bool  next);
virtual void focusOutEvent(QFocusEvent*  arg__1);
virtual bool  hasHeightForWidth() const;
virtual int  heightForWidth(int  arg__1) const;
virtual void hideEvent(QHideEvent*  arg__1);
virtual void initPainter(QPainter*  painter) const;
virtual void inputMethodEvent(QInputMethodEvent*  arg__1);
virtual QVariant  inputMethodQuery(Qt::InputMethodQuery  arg__1) const;
virtual void keyPressEvent(QKeyEvent*  arg__1);
virtual void keyReleaseEvent(QKeyEvent*  arg__1);
virtual void leaveEvent(QEvent*  arg__1);
virtual int  metric(QPaintDevice::PaintDeviceMetric  arg__1) const;
virtual QSize  minimumSizeHint() const;
virtual void mouseDoubleClickEvent(QMouseEvent*  arg__1);
virtual void mouseMoveEvent(QMouseEvent*  arg__1);
virtual void mousePressEvent(QMouseEvent*  arg__1);
virtual void mouseReleaseEvent(QMouseEvent*  arg__1);
virtual void moveEvent(QMoveEvent*  arg__1);
virtual bool  nativeEvent(const QByteArray&  eventType, void*  message, long*  result);
virtual QPaintEngine*  paintEngine() const;
virtual void paintEvent(QPaintEvent*  arg__1);
virtual QPaintDevice*  redirected(QPoint*  offset) const;
virtual void resizeEvent(QResizeEvent*  arg__1);
virtual QPainter*  sharedPainter() const;
virtual void showEvent(QShowEvent*  arg__1);
virtual QSize  sizeHint() const;
virtual void tabletEvent(QTabletEvent*  arg__1);
virtual void timerEvent(QTimerEvent*  arg__1);
virtual void wheelEvent(QWheelEvent*  arg__1);

  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtWrapper_elfFileWidget : public QObject
{ Q_OBJECT
public:
public slots:
elfFileWidget* new_elfFileWidget(QWidget*  parent = 0);
void delete_elfFileWidget(elfFileWidget* obj) { delete obj; } 
};





class PythonQtShell_elfInfoWdgt : public elfInfoWdgt
{
public:
    PythonQtShell_elfInfoWdgt(QWidget*  parent = 0):elfInfoWdgt(parent),_wrapper(NULL) {};

   ~PythonQtShell_elfInfoWdgt();

virtual void actionEvent(QActionEvent*  arg__1);
virtual void changeEvent(QEvent*  arg__1);
virtual void childEvent(QChildEvent*  arg__1);
virtual void closeEvent(QCloseEvent*  arg__1);
virtual void contextMenuEvent(QContextMenuEvent*  arg__1);
virtual void customEvent(QEvent*  arg__1);
virtual int  devType() const;
virtual void dragEnterEvent(QDragEnterEvent*  arg__1);
virtual void dragLeaveEvent(QDragLeaveEvent*  arg__1);
virtual void dragMoveEvent(QDragMoveEvent*  arg__1);
virtual void dropEvent(QDropEvent*  arg__1);
virtual void enterEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  arg__1);
virtual bool  eventFilter(QObject*  arg__1, QEvent*  arg__2);
virtual void focusInEvent(QFocusEvent*  arg__1);
virtual bool  focusNextPrevChild(bool  next);
virtual void focusOutEvent(QFocusEvent*  arg__1);
virtual bool  hasHeightForWidth() const;
virtual int  heightForWidth(int  arg__1) const;
virtual void hideEvent(QHideEvent*  arg__1);
virtual void initPainter(QPainter*  painter) const;
virtual void inputMethodEvent(QInputMethodEvent*  arg__1);
virtual QVariant  inputMethodQuery(Qt::InputMethodQuery  arg__1) const;
virtual void keyPressEvent(QKeyEvent*  arg__1);
virtual void keyReleaseEvent(QKeyEvent*  arg__1);
virtual void leaveEvent(QEvent*  arg__1);
virtual int  metric(QPaintDevice::PaintDeviceMetric  arg__1) const;
virtual QSize  minimumSizeHint() const;
virtual void mouseDoubleClickEvent(QMouseEvent*  arg__1);
virtual void mouseMoveEvent(QMouseEvent*  arg__1);
virtual void mousePressEvent(QMouseEvent*  arg__1);
virtual void mouseReleaseEvent(QMouseEvent*  arg__1);
virtual void moveEvent(QMoveEvent*  arg__1);
virtual bool  nativeEvent(const QByteArray&  eventType, void*  message, long*  result);
virtual QPaintEngine*  paintEngine() const;
virtual void paintEvent(QPaintEvent*  arg__1);
virtual QPaintDevice*  redirected(QPoint*  offset) const;
virtual void resizeEvent(QResizeEvent*  arg__1);
virtual QPainter*  sharedPainter() const;
virtual void showEvent(QShowEvent*  arg__1);
virtual QSize  sizeHint() const;
virtual void tabletEvent(QTabletEvent*  arg__1);
virtual void timerEvent(QTimerEvent*  arg__1);
virtual void wheelEvent(QWheelEvent*  arg__1);

  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtWrapper_elfInfoWdgt : public QObject
{ Q_OBJECT
public:
public slots:
elfInfoWdgt* new_elfInfoWdgt(QWidget*  parent = 0);
void delete_elfInfoWdgt(elfInfoWdgt* obj) { delete obj; } 
};





class PythonQtWrapper_elfparser : public QObject
{ Q_OBJECT
public:
public slots:
elfparser* new_elfparser();
void delete_elfparser(elfparser* obj) { delete obj; } 
   int  closeFile(elfparser* theWrappedObject);
   QString  getABI(elfparser* theWrappedObject);
   QString  getArchitecture(elfparser* theWrappedObject);
   QString  getClass(elfparser* theWrappedObject);
   QString  getEndianness(elfparser* theWrappedObject);
   qint64  getEntryPointAddress(elfparser* theWrappedObject);
   bool  getSectionData(elfparser* theWrappedObject, int  index, char**  buffer);
   qint64  getSectionDatasz(elfparser* theWrappedObject, int  index);
   qint64  getSectionMemsz(elfparser* theWrappedObject, int  index);
   QString  getSectionName(elfparser* theWrappedObject, int  index);
   qint64  getSectionPaddr(elfparser* theWrappedObject, int  index);
   QString  getSectionType(elfparser* theWrappedObject, int  index);
   int  getSectioncount(elfparser* theWrappedObject);
   qint64  getSegmentFilesz(elfparser* theWrappedObject, int  index);
   QString  getSegmentFlags(elfparser* theWrappedObject, int  index);
   qint64  getSegmentMemsz(elfparser* theWrappedObject, int  index);
   qint64  getSegmentOffset(elfparser* theWrappedObject, int  index);
   qint64  getSegmentPaddr(elfparser* theWrappedObject, int  index);
   QString  getSegmentType(elfparser* theWrappedObject, int  index);
   qint64  getSegmentVaddr(elfparser* theWrappedObject, int  index);
   int  getSegmentcount(elfparser* theWrappedObject);
   QString  getType(elfparser* theWrappedObject);
   qint64  getVersion(elfparser* theWrappedObject);
   bool  static_elfparser_isElf(const QString&  File);
   bool  iself(elfparser* theWrappedObject);
   bool  isopened(elfparser* theWrappedObject);
   int  setFilename(elfparser* theWrappedObject, const QString&  name);
};


