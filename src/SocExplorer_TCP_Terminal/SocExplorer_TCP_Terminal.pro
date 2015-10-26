#-------------------------------------------------
#
# Project created by QtCreator 2013-03-18T17:16:23
#
#-------------------------------------------------

QT       += core gui network
SOCEXPLORER_ROOT = $${PWD}/../..
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SocExplorer_TCP_Terminal
TEMPLATE = app

win32:DESTDIR = $${SOCEXPLORER_ROOT}/bin/win32/
unix:DESTDIR = $${SOCEXPLORER_ROOT}/bin/linux/

unix{
    target.path    = /usr/bin
    INSTALLS += target
}

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
