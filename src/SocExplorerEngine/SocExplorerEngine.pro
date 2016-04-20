SOCEXPLORER_ROOT = \"$${PWD}/../..\"

include($${PWD}/../../build_cfg/socexplorer.pri)

TARGET = socexplorerengine$${DEBUG_EXT}
TEMPLATE = lib

#more verbose plugin loader to debug plugin loading issues such as dependencies issues
SOCEXPLORER_PLUGIN_LOADER="custom"

SOCEXPLORER_CHAGESETNUM=$$system(hg id)
isEmpty(SOCEXPLORER_CHAGESETNUM){
    SOCEXPLORER_CHAGESETNUM=c459540a6dbdcbb4e17f204685fce02c070ba971+
}
SOCEXPLORER_CHAGESETNUMSTR = '\\"$${SOCEXPLORER_CHAGESETNUM}\\"'
SOCEXPLORER_BRANCH=$$system(hg branch)
isEmpty(SOCEXPLORER_BRANCH){
    SOCEXPLORER_BRANCH=default
}
SOCEXPLORER_BRANCHSTR = '\\"$${SOCEXPLORER_BRANCH}\\"'

DEFINES += SOCEXPLORER_VERSION="\"\\\"0.7.0"\\\"\"
DEFINES += SOCEXPLORER_CHAGESET=\"$${SOCEXPLORER_CHAGESETNUMSTR}\"
DEFINES += SOCEXPLORER_BRANCH=\"$${SOCEXPLORER_BRANCHSTR}\"


message("Building SOCEXPLORER changeset $${SOCEXPLORER_CHAGESETNUM}")

DEFINES += SOCEXPLORER_EXPORTS

include ( plugins/socexplorerplugin.prf )
include ( PeripheralWidget/PeripheralWidget.pri)

win32:CONFIG += dll
win32:CONFIG -= static
win32:LIBS+=-L$${SOCEXPLORER_ROOT}/bin/win32 -lsocexplorercommon$${DEBUG_EXT}

contains(SOCEXPLORER_PLUGIN_LOADER,"custom")
{
    unix:LIBS+= -ldl
    unix:DEFINES += SOCEXPLORER_CUSTOM_PLUGIN_LOADER
    unix:HEADERS += \
    pluginloader/unix/unixpluginloader.h
    unix:SOURCES += \
    pluginloader/unix/unixpluginloader.cpp
}

target.path = $$[QT_INSTALL_LIBS]
isEmpty(target.path) {
        error(can\'t get QT_INSTALL_LIBS)
}

header.path = $$[QT_INSTALL_HEADERS]/SocExplorer
header.files = engine/socexplorerengine.h \
                pluginloader/pluginscache.h \
                plugins/socexplorerplugin.h \
                proxy/socexplorerproxy.h \
                engine/socexplorerxmlfile.h \
                SOC/socexplorerenumdevice.h \
                XmlEngine/XMLmodel.h \
                XmlEngine/XMLdata.h \
                XmlEngine/xmldriver.h \
                SOC/socmodel.h \
                SOC/registerdata.h \
                SOC/socclk.h \
                PeripheralWidget/src/peripheralwidget.h \
                PeripheralWidget/src/registerwidget.h \
                PeripheralWidget/src/socregsviewer.h \
                PeripheralWidget/src/socregsviewernew.h \
                memtester/memtester.h \
                engine/socexplorersettings.h \
                engine/socexplorersettingsdialog.h \
                engine/socexplorergui.h\
                engine/socexplorerconfigkeys.h



isEmpty(header.path) {
        error(can\'t get QT_INSTALL_HEADERS)
}

pluginif.files = pluginsInterface/*.h \
                pluginsInterface/*.cpp

pluginif.path = $$[QT_INSTALL_HEADERS]/SocExplorer/pluginsInterface


INSTALLS += target header pluginif

INCLUDEPATH += engine \
    pluginloader \
    pluginsInterface \
    proxy \
    plugins \
    pluginManagerWdgt \
    ../common \
    ../common/genericBinaryFiles \
    ../ \
    RegisterMVS \
    XmlEngine \
    SOC \
    PeripheralWidget/src \
    memtester


HEADERS += \ 
    pluginloader/pluginscache.h \
    pluginloader/pluginloader.h \
    pluginManagerWdgt/plugintree.h \
    pluginManagerWdgt/pluginmanagerWDGT.h \
    pluginManagerWdgt/pluginlist.h \
    pluginManagerWdgt/plugininfoswdgt.h \
    XmlEngine/XMLmodel.h \
    XmlEngine/XMLdata.h \
    SOC/socmodel.h  \
    SOC/registerdata.h \
    XmlEngine/xmldriver.h \
    PeripheralWidget/src/peripheralwidget.h \
    PeripheralWidget/src/registerwidget.h \
    PeripheralWidget/src/socregsviewer.h \
    SOC/socclk.h \
    engine/socexplorerengine.h \
    engine/socexplorerxmlfile.h \
    plugins/socexplorerplugin.h \
    pluginsInterface/socexplorerplugininterface.h \
    pluginsInterface/socexplorerplugininterface_global.h \
    proxy/socexplorerproxy.h \
    SOC/socexplorerenumdevice.h \
    PySocExplorerEngine.h \
    memtester/memtester.h\
    PeripheralWidget/src/socregsviewernew.h \
    PeripheralWidget/src/collapsableperipheralwidget.h \
    engine/socexplorersettings.h \
    engine/socexplorersettingsdialog.h \
    engine/socexplorergui.h \
    engine/socexplorerconfigkeys.h






SOURCES += \ 
    pluginloader/pluginscache.cpp \
    pluginloader/pluginloader.cpp \
    pluginManagerWdgt/plugintree.cpp \
    pluginManagerWdgt/pluginmanagerWDGT.cpp \
    pluginManagerWdgt/pluginlist.cpp \
    pluginManagerWdgt/plugininfoswdgt.cpp \
    XmlEngine/XMLmodel.cpp \
    XmlEngine/XMLdata.cpp \
    SOC/socmodel.cpp \
    SOC/registerdata.cpp \
    XmlEngine/xmldriver.cpp \
    PeripheralWidget/src/peripheralwidget.cpp \
    PeripheralWidget/src/registerwidget.cpp \
    PeripheralWidget/src/socregsviewer.cpp \
    SOC/socclk.cpp \
    engine/socexplorerengine.cpp \
    engine/socexplorerxmlfile.cpp \
    proxy/socexplorerproxy.cpp \
    SOC/socexplorerenumdevice.cpp \
    plugins/socexplorerplugin.cpp \
    memtester/memtester.cpp \
    PeripheralWidget/src/socregsviewernew.cpp \
    PeripheralWidget/src/collapsableperipheralwidget.cpp \
    engine/socexplorersettings.cpp \
    engine/socexplorersettingsdialog.cpp \
    engine/socexplorergui.cpp


OTHER_FILES += \
    plugins/socexplorerplugin.cpp \
    pluginsInterface/socexplorerplugininterface.cpp \
    plugins/socexplorerplugin.prf \
    pythongenerator.sh \
    pythonQtgeneratorCfg.txt

FORMS += \
    PeripheralWidget/src/socregsviewernew.ui \
    PeripheralWidget/src/collapsableperipheralwidget.ui \
    engine/socexplorersettingsdialog.ui


RESOURCES += \
    PeripheralWidget/ressources/peripheralwidget.qrc
