#include "mainwindow.h"

MainWindow::MainWindow(int port, QWidget *parent)
    : QMainWindow(parent)
{
    this->soc = NULL;
    this->readTimer = new QTimer();
    this->terminal = new QTextBrowser();
    this->terminal->setAcceptRichText(true);
    this->setCentralWidget(this->terminal);
    this->terminal->setEnabled(false);
    this->terminal->setReadOnly(true);
    this->pr_statusBar = this->statusBar();
    this->server = new QTcpServer();
    this->server->listen(QHostAddress::Any,port);
    connect(this->server, SIGNAL(newConnection()),this, SLOT(newConnection()));
    this->pr_statusBar->showMessage(tr("Not connected, waiting for client. On port ")+QString::number(this->server->serverPort()));
    this->readTimer->setInterval(500);
    this->readTimer->start();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::receive()
{
    while(soc->bytesAvailable()!=0)
    {
        this->terminal->append(soc->readAll());
    }
}

void MainWindow::stateChanged(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        this->terminal->setEnabled(false);
        this->pr_statusBar->showMessage(tr("Not connected, waiting for client. On port ")+QString::number(this->server->serverPort()));
        disconnect(this,SLOT(receive()));
        break;
    case QAbstractSocket::ConnectedState:
        this->terminal->setEnabled(true);
        this->pr_statusBar->showMessage(tr("Connected, listening on port ")+QString::number(this->server->serverPort()));
        break;
    default:
        break;
    }
}

void MainWindow::newConnection()
{
    if(this->soc!=NULL)
    {
        if(this->soc->state()!=QAbstractSocket::ConnectedState)
        {
            this->soc->disconnect();
        }
        disconnect(this,SLOT(receive()));
        disconnect(this,SLOT(stateChanged(QAbstractSocket::SocketState)));
        this->stateChanged(QAbstractSocket::UnconnectedState);
        delete this->soc;
    }
    this->soc = this->server->nextPendingConnection();
    connect(this->soc,SIGNAL(readyRead()),this,SLOT(receive()));
    connect(this->soc,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(stateChanged(QAbstractSocket::SocketState)));
    connect(this->readTimer,SIGNAL(timeout()),this,SLOT(receive()));
    this->stateChanged(QAbstractSocket::ConnectedState);
}









