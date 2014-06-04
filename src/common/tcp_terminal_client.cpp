#include "tcp_terminal_client.h"
#include <QApplication>
#include <unistd.h>

TCP_Terminal_Client::TCP_Terminal_Client(QObject *parent) :
    QObject(parent)
{
    this->soc = new QTcpSocket();
    this->ServerProc = new QProcess();
}

void TCP_Terminal_Client::connectToServer(const QString &IP, int port)
{
    int timeout=60;
    if(this->soc->state()==QTcpSocket::UnconnectedState)
    {
        this->soc->connectToHost(IP,port);
        this->soc->waitForConnected(30000);
        while(this->soc->state()!=QTcpSocket::ConnectedState)
        {
            usleep(100000);
            if(timeout--==0)break;
        }
    }
}

void TCP_Terminal_Client::connectToServer()
{
    this->connectToServer("127.0.0.1",2000);
}

bool TCP_Terminal_Client::isConnected()
{
    return(this->soc->state()==QTcpSocket::ConnectedState);
}

void TCP_Terminal_Client::sendText(const QString &text)
{
    soc->write(text.toLatin1());
    soc->flush();
}

void TCP_Terminal_Client::startServer()
{
    if(this->ServerProc->state()==QProcess::NotRunning)
    {
        this->ServerProc->start(qApp->applicationDirPath()+"/SocExplorer_TCP_Terminal");
        this->ServerProc->waitForStarted(30000);
        usleep(500000);
    }
}

void TCP_Terminal_Client::startServer(int port)
{
    if(this->ServerProc->state()==QProcess::NotRunning)
    {
        this->ServerProc->start(qApp->applicationDirPath()+"/SocExplorer_TCP_Terminal --port "+QString::number(port));
        this->ServerProc->waitForStarted(30000);
        usleep(500000);
    }
}
















