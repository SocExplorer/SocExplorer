#-------------------------------------------------
#
# Project created by QtCreator 2011-09-19T22:52:10
#
#-------------------------------------------------

TEMPLATE = subdirs
CONFIG   += ordered release

SUBDIRS = \
    src/common \
    src/SocExplorerEngine \
    src \
    src/SocExplorer_TCP_Terminal


socexplorercfg.path = $$[QT_INSTALL_PREFIX]/mkspecs/features
socexplorercfg.files = \
    src/SocExplorerEngine/plugins/socexplorerplugin.prf


unix{
    SocExplorer.path = /usr/share/applications/
    SocExplorer.files = unixcfg/SocExplorer.desktop
    icon.path = /etc/SocExplorer
    icon.files = ressources/images/logo-lpp-cutted.png
    Wizard.path = /usr/share/qtcreator/templates/wizards/SocExplorerPlugin
    Wizard.files = Qt_Creator_Wizard/SocExplorerPlugin/logo-lpp-cutted.png \
                    Qt_Creator_Wizard/SocExplorerPlugin/plugin.cpp \
                    Qt_Creator_Wizard/SocExplorerPlugin/plugin.h \
                    Qt_Creator_Wizard/SocExplorerPlugin/project.pro \
                    Qt_Creator_Wizard/SocExplorerPlugin/wizard.xml
    INSTALLS+=Wizard SocExplorer icon
}
    INSTALLS+=socexplorercfg



















































