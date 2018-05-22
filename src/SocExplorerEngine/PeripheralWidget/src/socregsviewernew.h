#ifndef SOCREGSVIEWERNEW_H
#define SOCREGSVIEWERNEW_H

#include <QWidget>
#include <peripheralwidget.h>
#include <collapsableperipheralwidget.h>

namespace Ui {
class SocRegsViewerNew;
}

class SocRegsViewerNew : public QWidget
{
    Q_OBJECT

public:
    explicit SocRegsViewerNew(const QString &name, QWidget *parent = 0);
    explicit SocRegsViewerNew(QWidget *parent = 0);
    ~SocRegsViewerNew();

    peripheralWidget *peripheral(int index);

signals:

public slots:
    void addPeripheral(peripheralWidget* peripheral);
    void periphClicked(peripheralWidget* sender);
    void periphUp(peripheralWidget* sender,int cursorIndex);
    void periphDown(peripheralWidget* sender,int cursorIndex);
    void setSocName(const QString& name);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::SocRegsViewerNew *ui;
    QList<peripheralWidget*> p_peripherals;
    QList<CollapsablePeripheralWidget*> p_CPeripherals;
};

#endif // SOCREGSVIEWERNEW_H
