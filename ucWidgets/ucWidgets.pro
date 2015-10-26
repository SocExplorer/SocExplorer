#-------------------------------------------------
#
# Project created by QtCreator 2013-03-25T22:45:34
#
#-------------------------------------------------

CONFIG(debug, debug|release) {
  DEBUG_EXT = _d
} else {
  DEBUG_EXT =
}

QT += core gui opengl script scripttools svg

TARGET = ucWidgets$${DEBUG_EXT}

TEMPLATE = lib
win32:CONFIG += dll

CONFIG += xml

OBJECTS_DIR = obj
MOC_DIR = moc
DESTDIR = bin
QMAKE_LFLAGS_RELEASE += --enable-auto-import
QMAKE_LFLAGS_DEBUG += --enable-auto-import

target.path = $$[QT_INSTALL_LIBS]
isEmpty(target.path) {
        target.path = $(QTDIR)/lib
}

header.path = $$[QT_INSTALL_HEADERS]/lppmon/common
header.files = \
    ucwidgets.h \
    RegisterData/registersdata.h \
    RegisterModel/registermodel.h


isEmpty(header.path) {
        header.path = $(QTDIR)/include
}

INSTALLS += target header

INCLUDEPATH += RegisterData

HEADERS += \
    ucwidgets.h \
    RegisterData/registerdata.h \
    RegisterModel/registermodel.h


SOURCES += \
    ucwidgets.cpp \
    RegisterData/registerdata.cpp \
    RegisterModel/registermodel.cpp
