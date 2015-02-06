#include <PythonQt.h>
#include <QObject>
#include <QVariant>
#include <qaction.h>
#include <qbackingstore.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdockwidget.h>
#include <qevent.h>
#include <qfont.h>
#include <qgraphicseffect.h>
#include <qgraphicsproxywidget.h>
#include <qicon.h>
#include <qkeysequence.h>
#include <qlayout.h>
#include <qlist.h>
#include <qlocale.h>
#include <qmargins.h>
#include <qmenu.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qstyleoption.h>
#include <qwidget.h>
#include <qwindow.h>
#include <socexplorerplugin.h>



class PythonQtShell_socexplorerplugin : public socexplorerplugin
{
public:
    PythonQtShell_socexplorerplugin(QWidget*  parent = 0, bool  createPyObject = true):socexplorerplugin(parent, createPyObject),_wrapper(NULL) {  };

   ~PythonQtShell_socexplorerplugin();

virtual int  PID();
virtual unsigned int  Read(unsigned int*  Value, unsigned int  count, unsigned int  address);
virtual int  VID();
virtual unsigned int  Write(unsigned int*  Value, unsigned int  count, unsigned int  address);
virtual void actionEvent(QActionEvent*  arg__1);
virtual void activate(bool  flag);
virtual int  baseAddress();
virtual QString  baseName();
virtual void changeEvent(QEvent*  event);
virtual void childEvent(QChildEvent*  arg__1);
virtual void closeEvent(QCloseEvent*  event);
virtual void closeMe();
virtual void contextMenuEvent(QContextMenuEvent*  arg__1);
virtual void customEvent(QEvent*  arg__1);
virtual int  devType() const;
virtual void dragEnterEvent(QDragEnterEvent*  arg__1);
virtual void dragLeaveEvent(QDragLeaveEvent*  arg__1);
virtual void dragMoveEvent(QDragMoveEvent*  arg__1);
virtual void dropEvent(QDropEvent*  arg__1);
virtual bool  dumpMemory(unsigned int  address, unsigned int  count, QString  file);
virtual bool  dumpMemory(unsigned int  address, unsigned int  count, QString  file, const QString&  format);
virtual void enterEvent(QEvent*  arg__1);
virtual bool  event(QEvent*  event);
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
virtual int  isConnected();
virtual void keyPressEvent(QKeyEvent*  arg__1);
virtual void keyReleaseEvent(QKeyEvent*  arg__1);
virtual void leaveEvent(QEvent*  arg__1);
virtual bool  loadbin(unsigned int  address, QString  file);
virtual bool  memSet(unsigned int  address, int  value, unsigned int  count);
virtual int  metric(QPaintDevice::PaintDeviceMetric  arg__1) const;
virtual QSize  minimumSizeHint() const;
virtual void mouseDoubleClickEvent(QMouseEvent*  arg__1);
virtual void mouseMoveEvent(QMouseEvent*  arg__1);
virtual void mousePressEvent(QMouseEvent*  arg__1);
virtual void mouseReleaseEvent(QMouseEvent*  arg__1);
virtual void moveEvent(QMoveEvent*  arg__1);
virtual bool  nativeEvent(const QByteArray&  eventType, void*  message, long*  result);
virtual QPaintEngine*  paintEngine() const;
virtual void paintEvent(QPaintEvent*  event);
virtual void postInstantiationTrigger();
virtual QPaintDevice*  redirected(QPoint*  offset) const;
virtual int  registermenu(QMenu*  menu);
virtual void resizeEvent(QResizeEvent*  arg__1);
virtual void setBaseAddress(unsigned int  baseAddress);
virtual void setInstanceName(const QString&  newName);
virtual QPainter*  sharedPainter() const;
virtual void showEvent(QShowEvent*  arg__1);
virtual QSize  sizeHint() const;
virtual void tabletEvent(QTabletEvent*  arg__1);
virtual void timerEvent(QTimerEvent*  arg__1);
virtual void wheelEvent(QWheelEvent*  arg__1);

  PythonQtInstanceWrapper* _wrapper; 
};

class PythonQtPublicPromoter_socexplorerplugin : public socexplorerplugin
{ public:
inline int  promoted_PID() { return socexplorerplugin::PID(); }
inline unsigned int  promoted_Read(unsigned int*  Value, unsigned int  count, unsigned int  address) { return socexplorerplugin::Read(Value, count, address); }
inline int  promoted_VID() { return socexplorerplugin::VID(); }
inline unsigned int  promoted_Write(unsigned int*  Value, unsigned int  count, unsigned int  address) { return socexplorerplugin::Write(Value, count, address); }
inline void promoted_activate(bool  flag) { socexplorerplugin::activate(flag); }
inline int  promoted_baseAddress() { return socexplorerplugin::baseAddress(); }
inline QString  promoted_baseName() { return socexplorerplugin::baseName(); }
inline void promoted_closeMe() { socexplorerplugin::closeMe(); }
inline bool  promoted_dumpMemory(unsigned int  address, unsigned int  count, QString  file) { return socexplorerplugin::dumpMemory(address, count, file); }
inline bool  promoted_dumpMemory(unsigned int  address, unsigned int  count, QString  file, const QString&  format) { return socexplorerplugin::dumpMemory(address, count, file, format); }
inline int  promoted_isConnected() { return socexplorerplugin::isConnected(); }
inline bool  promoted_loadbin(unsigned int  address, QString  file) { return socexplorerplugin::loadbin(address, file); }
inline void promoted_makeGenericPyWrapper() { socexplorerplugin::makeGenericPyWrapper(); }
inline bool  promoted_memSet(unsigned int  address, int  value, unsigned int  count) { return socexplorerplugin::memSet(address, value, count); }
inline void promoted_postInstantiationTrigger() { socexplorerplugin::postInstantiationTrigger(); }
inline int  promoted_registermenu(QMenu*  menu) { return socexplorerplugin::registermenu(menu); }
inline void promoted_setBaseAddress(unsigned int  baseAddress) { socexplorerplugin::setBaseAddress(baseAddress); }
inline void promoted_setInstanceName(const QString&  newName) { socexplorerplugin::setInstanceName(newName); }
};

class PythonQtWrapper_socexplorerplugin : public QObject
{ Q_OBJECT
public:
public slots:
socexplorerplugin* new_socexplorerplugin(QWidget*  parent = 0, bool  createPyObject = true);
void delete_socexplorerplugin(socexplorerplugin* obj) { delete obj; } 
   int  PID(socexplorerplugin* theWrappedObject);
   unsigned int  Read(socexplorerplugin* theWrappedObject, unsigned int*  Value, unsigned int  count, unsigned int  address);
   int  VID(socexplorerplugin* theWrappedObject);
   unsigned int  Write(socexplorerplugin* theWrappedObject, unsigned int*  Value, unsigned int  count, unsigned int  address);
   void activate(socexplorerplugin* theWrappedObject, bool  flag);
   int  baseAddress(socexplorerplugin* theWrappedObject);
   QString  baseName(socexplorerplugin* theWrappedObject);
   void closeMe(socexplorerplugin* theWrappedObject);
   bool  dumpMemory(socexplorerplugin* theWrappedObject, unsigned int  address, unsigned int  count, QString  file);
   bool  dumpMemory(socexplorerplugin* theWrappedObject, unsigned int  address, unsigned int  count, QString  file, const QString&  format);
   QString  instanceName(socexplorerplugin* theWrappedObject);
   int  isConnected(socexplorerplugin* theWrappedObject);
   bool  loadbin(socexplorerplugin* theWrappedObject, unsigned int  address, QString  file);
   void makeGenericPyWrapper(socexplorerplugin* theWrappedObject);
   bool  memSet(socexplorerplugin* theWrappedObject, unsigned int  address, int  value, unsigned int  count);
   void postInstantiationTrigger(socexplorerplugin* theWrappedObject);
   int  registermenu(socexplorerplugin* theWrappedObject, QMenu*  menu);
   void setBaseAddress(socexplorerplugin* theWrappedObject, unsigned int  baseAddress);
   void setInstanceName(socexplorerplugin* theWrappedObject, const QString&  newName);
void py_set_ChildsMenu(socexplorerplugin* theWrappedObject, QMenu*  ChildsMenu){ theWrappedObject->ChildsMenu = ChildsMenu; }
QMenu*  py_get_ChildsMenu(socexplorerplugin* theWrappedObject){ return theWrappedObject->ChildsMenu; }
void py_set_childs(socexplorerplugin* theWrappedObject, QList<socexplorerplugin* >  childs){ theWrappedObject->childs = childs; }
QList<socexplorerplugin* >  py_get_childs(socexplorerplugin* theWrappedObject){ return theWrappedObject->childs; }
void py_set_closeAction(socexplorerplugin* theWrappedObject, QAction*  closeAction){ theWrappedObject->closeAction = closeAction; }
QAction*  py_get_closeAction(socexplorerplugin* theWrappedObject){ return theWrappedObject->closeAction; }
void py_set_menu(socexplorerplugin* theWrappedObject, QMenu*  menu){ theWrappedObject->menu = menu; }
QMenu*  py_get_menu(socexplorerplugin* theWrappedObject){ return theWrappedObject->menu; }
void py_set_parent(socexplorerplugin* theWrappedObject, socexplorerplugin*  parent){ theWrappedObject->parent = parent; }
socexplorerplugin*  py_get_parent(socexplorerplugin* theWrappedObject){ return theWrappedObject->parent; }
};


