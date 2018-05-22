#ifndef REGSEXPLORERNEW_H
#define REGSEXPLORERNEW_H

#include <QDockWidget>
#include <socexplorerengine.h>
#include <peripheralwidget.h>
#include <socregsviewernew.h>

namespace Ui {
class RegsExplorerNew;
}

class RegsExplorer : public QDockWidget
{
    Q_OBJECT
    class regExplorerReadWriteDelegate: public peripheralWidget::readWriteProxy
    {
    public:
        regExplorerReadWriteDelegate() {}
        void writeReg(qint32 address,qint32 value){if(device)device->writeReg(address,value);}
        qint32 readReg(qint32 address){if(device)return device->readReg(address);}
        socExplorerEnumDevice* device;
    };
public:
    explicit RegsExplorer(QWidget *parent = 0);
    ~RegsExplorer();
public slots:
    void addDev(socExplorerEnumDevice* device);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::RegsExplorerNew *ui;
    regExplorerReadWriteDelegate delegate;
};

#endif // REGSEXPLORERNEW_H
