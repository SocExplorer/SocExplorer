#ifndef REGSEXPLORERCFG_H
#define REGSEXPLORERCFG_H

#include <socexplorerengine.h>
#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QList>

class regsExplorerCfg : public QWidget
{
    Q_OBJECT
public:
    explicit regsExplorerCfg(QWidget *parent = 0);
    
signals:
    
public slots:
    void updateRegList();
    QCheckBox* addDev(socExplorerEnumDevice *device);
    void clear();
private:
    QGridLayout* mainLayout;
    QList<QCheckBox*>* regsList;

};

#endif // REGSEXPLORERCFG_H
