#include "toolbar.h"

toolBar::toolBar(QWidget *parent) :
    QDockWidget(parent)
{
    this->toolsContainer = new toolBarContainer;
    this->setWidget(this->toolsContainer);
    this->setFeatures(DockWidgetMovable | DockWidgetFloatable);
    this->setWindowTitle("SocExplorer Toolbar");
}



void toolBar::addTool(QDockWidget* widget)
{
    widget->setAllowedAreas(Qt::AllDockWidgetAreas);
    this->toolsContainer->addDockWidget(Qt::TopDockWidgetArea,widget);
}



