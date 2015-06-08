#ifndef SOCEXPLORERGUI_H
#define SOCEXPLORERGUI_H

#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class SocExplorerGUI : public QObject
{
    Q_OBJECT
    static SocExplorerGUI* _self;
    static QMenuBar* m_mainMenuBar;
    static QMenu* m_fileMenu;
    static QMenu* m_SettingsMenu;
    static QList<QAction*>* m_queuedSettingActions;
    static QList<QAction*>* m_queuedFileMenuActions;
    SocExplorerGUI(QObject *parent = 0);
    static void init();
public:
    static SocExplorerGUI* self(){ if(!_self){_self= new SocExplorerGUI;}return _self;}
    static void registerMenuBar(QMenuBar* menuBar,  QMenu* fileMenu=NULL, QMenu* SettingsMenu=NULL);
    static QMenu* addMenu(const QString & title);
    static bool addFileAction(QAction * action);
    static bool addSettingsAction(QAction * action);
signals:

public slots:
};

#endif // SOCEXPLORERGUI_H
