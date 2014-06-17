SOCEXPLORER_ROOT = \"$${PWD}/../..\"
include($${PWD}/../../build_cfg/socexplorer.pri)
include($${PWD}/lppserial/lppserial.pri)

TEMPLATE = lib
TARGET = socexplorercommon$${DEBUG_EXT}

win32:CONFIG += dll
win32:CONFIG -= static

win32:INCLUDEPATH += $${PWD}/genericBinaryFiles/elf/libelfWin32/include
win32:INCLUDEPATH += $${PWD}/genericBinaryFiles/elf/libelfWin32/include/libelf
win32:DEFINES+=_ELF_WINDOWS_
DEFINES+=RS232_debug

win32:LIBS += $${PWD}/genericBinaryFiles/elf/libelfWin32/bin/libelf.a
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
    genericBinaryFiles/elf/elfinfowdgt.h \
    genericBinaryFiles/elf/elfparser.h \
    genericBinaryFiles/elf/elffile.h \
    genericBinaryFiles/elf/elffilewidget.h \
    qipdialogbox.h \
    lppserial/src/RS232.h \
    qtablewidgetintitem.h \
    genericBinaryFiles/srec/srecfile.h \
    genericBinaryFiles/srec/srecfilewidget.h \
    genericBinaryFiles/BinFile/binaryfile.h \
    genericBinaryFiles/BinFile/binaryfilewidget.h \
    genericBinaryFiles/abstractbinfile.h

win32{
    elfheader.path = $$[QT_INSTALL_HEADERS]/SocExplorer/common/genericBinaryFiles/libelf
    elfheader.files += \
        genericBinaryFiles/elf/libelfWin32/include/libelf/byteswap.h  \
        genericBinaryFiles/elf/libelfWin32/include/libelf/errors.h     \
        genericBinaryFiles/elf/libelfWin32/include/libelf/gelf.h    \
        genericBinaryFiles/elf/libelfWin32/include/libelf/nlist.h    \
        genericBinaryFiles/elf/libelfWin32/include/libelf/sys_elf.h  \
        genericBinaryFiles/elf/libelfWin32/include/libelf/verneed.h \
        genericBinaryFiles/elf/libelfWin32/include/libelf/elf_repl.h \
        genericBinaryFiles/elf/libelfWin32/include/libelf/ext_types.h \
        genericBinaryFiles/elf/libelfWin32/include/libelf/libelf.h  \
        genericBinaryFiles/elf/libelfWin32/include/libelf/private.h  \
        genericBinaryFiles/elf/libelfWin32/include/libelf/verdef.h
    INSTALLS += elfheader
}


isEmpty(header.path) {
   error(can\'t get QT_INSTALL_HEADERS)
}

INSTALLS += target header

INCLUDEPATH += QCustomPlot qhexedit   genericBinaryFiles genericBinaryFiles/srec  genericBinaryFiles/BinFile

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
    genericBinaryFiles/elf/elfinfowdgt.h \
    genericBinaryFiles/elf/elfparser.h \
    genericBinaryFiles/elf/elffile.h \
    qipdialogbox.h \
    PySocExplorer.h \
    SocExplorerPlot.h \
    genericBinaryFiles/elf/elffilewidget.h \
    genericBinaryFiles/srec/srecfile.h \
    genericBinaryFiles/srec/srecfilewidget.h \
    genericBinaryFiles/abstractbinfile.h \
    genericBinaryFiles/BinFile/binaryfile.h \
    genericBinaryFiles/BinFile/binaryfilewidget.h \
    genericBinaryFiles/genericbinaryfilewidget.h


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
    genericBinaryFiles/elf/elfinfowdgt.cpp \
    genericBinaryFiles/elf/elfparser.cpp \
    genericBinaryFiles/elf/elffile.cpp \
    qipdialogbox.cpp \
    SocExplorerPlot.cpp \
    genericBinaryFiles/elf/elffilewidget.cpp \
    genericBinaryFiles/srec/srecfile.cpp \
    genericBinaryFiles/srec/srecfilewidget.cpp \
    genericBinaryFiles/abstractbinfile.cpp \
    genericBinaryFiles/BinFile/binaryfile.cpp \
    genericBinaryFiles/BinFile/binaryfilewidget.cpp \
    genericBinaryFiles/genericbinaryfilewidget.cpp

FORMS += \
    genericBinaryFiles/elf/elffilewidget.ui \
    genericBinaryFiles/srec/srecfilewidget.ui \
    genericBinaryFiles/BinFile/binaryfilewidget.ui \
    genericBinaryFiles/genericbinaryfilewidget.ui

OTHER_FILES += \
    ./pythongenerator.sh \
    ./pythonQtgeneratorCfg.txt





