#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "peripheralwidget.h"
#include "socregsviewer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    peripheralWidget* testWidget;
    socRegsViewer* socViewer;
};

#endif // MAINWINDOW_H
