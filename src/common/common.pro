SOCEXPLORER_ROOT = \"$${PWD}/../..\"
include($${PWD}/../../build_cfg/socexplorer.pri)


TEMPLATE = lib
TARGET = socexplorercommon$${DEBUG_EXT}

win32:CONFIG += dll
win32:CONFIG -= static

win32:INCLUDEPATH += $${PWD}/elf/libelfWin32/include
win32:INCLUDEPATH += $${PWD}/elf/libelfWin32/include/libelf
win32:DEFINES+=_ELF_WINDOWS_

win32:LIBS += $${PWD}/elf/libelfWin32/bin/libelf.a
unix:LIBS += -lelf

QMAKE_LFLAGS_RELEASE += --enable-auto-import
QMAKE_LFLAGS_DEBUG += --enable-auto-import

target.path = $$[QT_INSTALL_LIBS]
isEmpty(target.path) {
   error(can\'t get QT_INSTALL_LIBS)
}

header.path = $$[QT_INSTALL_HEADERS]/SocExplorer/common
header.files = \
    memsizewdgt.h \
    qhexspinbox.h \
    qsvgicon.h \
    qhexedit/qhexedit_p.h \
    qhexedit/qhexedit.h \
    qhexedit/xbytearray.h \
    QCustomPlot/qcustomplot.h \
    SocExplorerPlot.h \
    tcp_terminal_client.h \
    elf/elfinfowdgt.h \
    elf/elfparser.h \
    elf/elffile.h \
    qipdialogbox.h


win32{
    elfheader.path = $$[QT_INSTALL_HEADERS]/SocExplorer/common/libelf
    elfheader.files += \
        elf/libelfWin32/include/libelf/byteswap.h  \
        elf/libelfWin32/include/libelf/errors.h     \
        elf/libelfWin32/include/libelf/gelf.h    \
        elf/libelfWin32/include/libelf/nlist.h    \
        elf/libelfWin32/include/libelf/sys_elf.h  \
        elf/libelfWin32/include/libelf/verneed.h \
        elf/libelfWin32/include/libelf/elf_repl.h \
        elf/libelfWin32/include/libelf/ext_types.h \
        elf/libelfWin32/include/libelf/libelf.h  \
        elf/libelfWin32/include/libelf/private.h  \
        elf/libelfWin32/include/libelf/verdef.h
    INSTALLS += elfheader
}


isEmpty(header.path) {
   error(can\'t get QT_INSTALL_HEADERS)
}

INSTALLS += target header

INCLUDEPATH += QCustomPlot qhexedit

HEADERS += \
    memsizewdgt.h \
    qhexspinbox.h \
    qsvgicon.h \
    qhexedit/qhexedit_p.h \
    qhexedit/qhexedit.h \
    qhexedit/xbytearray.h \
    qhexedit/commands.h \
    QCustomPlot/qcustomplot.h \
    tcp_terminal_client.h \
    elf/elfinfowdgt.h \
    elf/elfparser.h \
    abstractexecfile.h \
    elf/elffile.h \
    qipdialogbox.h \
    PySocExplorer.h \
    SocExplorerPlot.h


SOURCES += \
    memsizewdgt.cpp \
    qhexspinbox.cpp \
    qsvgicon.cpp \
    qhexedit/qhexedit_p.cpp \
    qhexedit/qhexedit.cpp \
    qhexedit/xbytearray.cpp \
    qhexedit/commands.cpp \
    QCustomPlot/qcustomplot.cpp \
    tcp_terminal_client.cpp \
    elf/elfinfowdgt.cpp \
    elf/elfparser.cpp \
    abstractexecfile.cpp \
    elf/elffile.cpp \
    qipdialogbox.cpp \
    SocExplorerPlot.cpp



