#
# Project created by QtCreator 2011-09-20T08:15:30
#
#-------------------------------------------------

CONFIG += socexplorerplugin
win32:CONFIG += dll
win32:CONFIG -= static
VERSION=0.1.0
TARGET = %ProjectName%$${DEBUG_EXT}
DEFINES += PLUGIN=%ProjectName%
DEFINES += PLUGINHEADER="\"\\\"%ProjectName%.h"\\\"\"
DEFINES += driver_Name="\"\\\"%driver_Name%"\\\"\"
DEFINES += driver_Author="\"\\\"%driver_Author% %driver_Mail%"\\\"\"
DEFINES += driver_Description="\"\\\"%driver_Description%"\\\"\"
DEFINES += driver_can_be_root=%ISROOT%
DEFINES += driver_can_be_child=%ISCHILD%
DEFINES += driver_VID=%driver_VID%
DEFINES += driver_PID=%driver_PID%


INCLUDEPATH += \
        $${PWD}

HEADERS += \
    %ProjectName%.h


SOURCES += \
    %ProjectName%.cpp 























