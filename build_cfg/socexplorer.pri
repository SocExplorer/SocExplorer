
QT += core gui xml svg network
contains(QT_MAJOR_VERSION, 5) {
  QT += widgets
  QT += printsupport
}
CONFIG(debug, debug|release) {
  DEBUG_EXT = _d
} else {
  DEBUG_EXT =
}

SOCEXPLORER_SDK_BUILD="SOCEXPLORER_SDK_BUILD"
DEFINES += SOCEXPLORER_SDK_BUILD

MOC_DIR      = moc
RCC_DIR      = resources
OBJECTS_DIR = obj

win32:DESTDIR = $${SOCEXPLORER_ROOT}/bin/win32/
unix:DESTDIR = $${SOCEXPLORER_ROOT}/bin/linux/


metrics_cccc.target = metrics_cccc
metrics_cccc.commands = cccc $(SOURCES) $(HEADERS)

QMAKE_EXTRA_TARGETS += metrics_cccc
