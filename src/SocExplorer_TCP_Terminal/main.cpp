#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int port=2000;
    QStringList args= a.arguments();
    for(int i=0;i<args.count();i++)
    {
        if(args.at(i).compare("--port")==0)
        {
            port = args.at(i+1).toInt();
            break;
        }
    }
    printf("Listening on port %d\n",port);
    MainWindow w(port);
    w.show();
    
    return a.exec();
}
