#include "mainwindowsmenubar.h"

mainwindowsmenubar::mainwindowsmenubar(QWidget *parent)
: QMenuBar(parent)
{
    this->pluginMenu0 = new pluginMenu;
    this->addMenu(this->pluginMenu0);
    this->connectionMenu0 = new connectionMenu;
}



pluginMenu::pluginMenu(QWidget *parent)
: QMenu(parent)
{
    this->managePlugins = new QAction(tr("&Manage Plugins"),parent);
    this->addAction(this->managePlugins);
}

connectionMenu::connectionMenu(QWidget *parent)
: QMenu(parent)
{
    this->connect = new QAction(tr("&Connect"),parent);
    this->disconnect = new QAction(tr("&Disconnect"),parent);
}
