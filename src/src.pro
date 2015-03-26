#-------------------------------------------------
#
# Project created by QtCreator 2011-09-19T22:52:10
#
#-------------------------------------------------
SOCEXPLORER_ROOT = $${PWD}/..
include(../build_cfg/socexplorer.pri)

TARGET = socexplorer$${DEBUG_EXT}
TEMPLATE = app
CONFIG += pythonqt


QMAKE_LFLAGS_RELEASE += --enable-auto-import -mstackrealign
QMAKE_LFLAGS_DEBUG += --enable-auto-import -mstackrealign

include ( common/pythonQtOut/generated_cpp/PySocExplorer/PySocExplorer.pri )
include ( SocExplorerEngine/pythonQtOut/generated_cpp/PySocExplorerEngine/PySocExplorerEngine.pri )
include ( SocExplorerEngine/plugins/socexplorerplugin.prf )

INCLUDEPATH+=$${PWD} \
            $${PWD}/common \
            $${PWD}/common/qhexedit \
            $${PWD}/common/QCustomPlot \
            $${PWD}/common/genericBinaryFiles \
            $${PWD}/common/genericBinaryFiles/elf \
            $${PWD}/common/genericBinaryFiles/srec \
            $${PWD}/common/genericBinaryFiles/BinFile \
            SocExplorerEngine/engine \
            SocExplorerEngine/pluginloader \
            SocExplorerEngine/pluginsInterface \
            SocExplorerEngine/proxy \
            SocExplorerEngine/pluginManagerWdgt \
            SocExplorerEngine/plugins \
            SocExplorerEngine/RegisterMVS \
            SocExplorerEngine/XmlEngine \
            SocExplorerEngine/SOC \
            SocExplorerEngine/PeripheralWidget/src \
            SocExplorerEngine/memtester

win32:INCLUDEPATH+= \
            $${PWD}/common/genericBinaryFiles/elf/libelfWin32/include \
            $${PWD}/common/genericBinaryFiles/elf/libelfWin32/include/libelf \


RC_FILE = ../win32cfg/socexplorer.rc


unix:LIBS+=-L$${SOCEXPLORER_ROOT}/bin/linux -lsocexplorercommon$${DEBUG_EXT} -L$${SOCEXPLORER_ROOT}/bin/linux -lsocexplorerengine$${DEBUG_EXT}

win32-g++:LIBS += $${SOCEXPLORER_ROOT}/bin/win32/socexplorercommon$${DEBUG_EXT}.dll $${SOCEXPLORER_ROOT}/bin/win32/socexplorerengine$${DEBUG_EXT}.dll


unix{
    translation.files = $${SOCEXPLORER_ROOT}/translations/socexplorer_fr.qm \
                        $${SOCEXPLORER_ROOT}/translations/socexplorer_en.qm
    translation.path = $${SOCEXPLORER_TRANSLATION_INSTALL_PATH}
    target.path    = /usr/bin
    INSTALLS += translation target
}

header.path = $$[QT_INSTALL_HEADERS]/SocExplorer/common
header.files = \
            socexplorer.h
INSTALLS += header


SOURCES += main.cpp\
        mainwindow.cpp \
    PyWdgt/pythonconsole.cpp \
    PyWdgt/pythonqtscriptingconsoledandd.cpp \
    dockablepluginmanager.cpp \
    toolbar.cpp \
    toolbarcontainer.cpp \
    regsExplorer/regsexplorer.cpp \
    regsExplorer/regsviewer.cpp \
    regsExplorer/regsexplorercfg.cpp \
    aboutsocexplorer.cpp

HEADERS  += mainwindow.h \
    PyWdgt/pythonconsole.h \
    PyWdgt/pythonqtscriptingconsoledandd.h \
    dockablepluginmanager.h \
    toolbar.h \
    toolbarcontainer.h \
    regsExplorer/regsexplorer.h \
    regsExplorer/regsviewer.h \
    regsExplorer/regsexplorercfg.h \
    socexplorer.h \
    SocExplorerEngine/plugins/socexplorerplugin.h \
    aboutsocexplorer.h


include ( NicePyConsole/NicePyConsole.pri)

win32{
    RESOURCES = ../ressources/SocExplorer.qrc
}

unix{
    RESOURCES = ../ressources/SocExplorer.qrc
}

TRANSLATIONS = ../translations/socexplorer_fr.ts \
    ../translations/socexplorer_en.ts








