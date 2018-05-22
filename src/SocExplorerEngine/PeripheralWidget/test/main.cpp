#include "mainwindow.h"
#include <QApplication>
#include "socregsviewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    qint32 baseAddress = 0x8000100;
    qint32 baseAddress2 = 0x8000200;
//    testWidget  = new peripheralWidget("UART1",baseAddress,this);
//    for(int i=0;i<10;i++)
//        testWidget->addRegister(QString("REG%1").arg((uint)i),baseAddress+(i*4));
    socRegsViewer* socViewer;
    socViewer = new socRegsViewer("leon 3");
    socViewer->addPeripheral(new peripheralWidget("UART1",baseAddress));
    socViewer->addPeripheral(new peripheralWidget("UART2",baseAddress2));
    for(int i=0;i<10;i++)
    {
            socViewer->peripheral(0)->addRegister(QString("REG%1").arg((uint)i),baseAddress+(i*4));
            socViewer->peripheral(1)->addRegister(QString("REG%1").arg((uint)i),baseAddress2+(i*4));
    }
    socViewer->show();
    return a.exec();
}
