#ifndef MAINWINDOWSMENUBAR_H
#define MAINWINDOWSMENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class mainwindowsmenubar : public QMenuBar
{
public:
    mainwindowsmenubar(QWidget *parent = 0);
    QMenu* pluginMenu0;
    QMenu* connectionMenu0;

};


class pluginMenu : public QMenu
{
public:
    pluginMenu(QWidget *parent = 0);
    QAction* managePlugins;
};

class connectionMenu : public QMenu
{
public:
    connectionMenu(QWidget *parent = 0);
    QAction* connect;
    QAction* disconnect;
};

#endif // MAINWINDOWSMENUBAR_H
