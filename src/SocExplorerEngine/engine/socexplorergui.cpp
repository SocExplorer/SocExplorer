#include "socexplorergui.h"

SocExplorerGUI* SocExplorerGUI::_self=NULL;
QMenuBar* SocExplorerGUI::m_mainMenuBar=NULL;
QMenu* SocExplorerGUI::m_fileMenu=NULL;
QMenu* SocExplorerGUI::m_SettingsMenu=NULL;
QList<QAction*>* SocExplorerGUI::m_queuedSettingActions=NULL;
QList<QAction*>* SocExplorerGUI::m_queuedFileMenuActions=NULL;

#define INIT() \
    if(Q_UNLIKELY(_self==NULL))\
    {\
        init();\
    }

SocExplorerGUI::SocExplorerGUI(QObject *parent) : QObject(parent)
{
    m_queuedFileMenuActions = new QList<QAction*>();
    m_queuedSettingActions = new QList<QAction*>();
}

void SocExplorerGUI::init()
{
    _self=new SocExplorerGUI();
}

void SocExplorerGUI::registerMenuBar(QMenuBar *menuBar, QMenu *fileMenu, QMenu *SettingsMenu)
{
    INIT();
    m_mainMenuBar = menuBar;
    if(m_mainMenuBar)
    {
        if(fileMenu==NULL)
            m_fileMenu = m_mainMenuBar->addMenu(tr("File"));
        else
            m_fileMenu = fileMenu;
        if(SettingsMenu==NULL)
            m_SettingsMenu = m_mainMenuBar->addMenu(tr("Settings"));
        else
            m_SettingsMenu = SettingsMenu;
    }

    QAction* action;
    foreach (action, *m_queuedSettingActions)
    {
        m_SettingsMenu->addAction(action);
    }
    foreach (action, *m_queuedFileMenuActions)
    {
        m_fileMenu->addAction(action);
    }
}

QMenu *SocExplorerGUI::addMenu(const QString &title)
{
    INIT();
    if(m_mainMenuBar)
    {
        return m_mainMenuBar->addMenu(title);
    }
    return NULL;
}

bool SocExplorerGUI::addFileAction(QAction *action)
{
    INIT();
        if(m_fileMenu)
        {
            m_fileMenu->addAction(action);
            return true;
        }
        else
        {
            m_queuedFileMenuActions->append(action);
        }
        return false;
}

bool SocExplorerGUI::addSettingsAction(QAction *action)
{
    INIT();
    if(m_SettingsMenu)
    {
        m_SettingsMenu->addAction(action);
        return true;
    }
    else
    {
        m_queuedSettingActions->append(action);
    }
    return false;
}

