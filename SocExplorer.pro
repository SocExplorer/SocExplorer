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
    SocExplorerLauncher.path = /usr/share/applications/
    SocExplorerLauncher.files = unixcfg/SocExplorer.desktop
    SocExplorerAppData.path = /usr/share/appdata/
    SocExplorerAppData.files = unixcfg/SocExplorer.appdata.xml
    PluginConfPath.path = /etc/SocExplorer/plugin.conf.d/
    PluginConfPath.files = unixcfg/plugins.conf
    share.path = /usr/share/SocExplorer
    share.files = ressources/images/Indiana_Jones_cappello.png \
                ressources/Grlib.xml
    Wizard.path = /usr/share/qtcreator/templates/wizards/SocExplorerPlugin
    Wizard.files = Qt_Creator_Wizard/SocExplorerPlugin/logo-lpp-cutted.png \
                    Qt_Creator_Wizard/SocExplorerPlugin/plugin.cpp \
                    Qt_Creator_Wizard/SocExplorerPlugin/plugin.h \
                    Qt_Creator_Wizard/SocExplorerPlugin/project.pro \
                    Qt_Creator_Wizard/SocExplorerPlugin/wizard.xml
    INSTALLS+=Wizard SocExplorerLauncher share PluginConfPath SocExplorerAppData
}
    INSTALLS+=socexplorercfg



















































