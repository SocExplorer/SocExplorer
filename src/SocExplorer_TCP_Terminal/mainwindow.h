#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QStatusBar>
#include <QGridLayout>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(int port=4000,QWidget *parent = 0);
    ~MainWindow();

public slots:
    void receive();
    void stateChanged ( QAbstractSocket::SocketState socketState );
    void newConnection();
private:
    QTextBrowser* terminal;
    QStatusBar* pr_statusBar;
    QTcpSocket* soc;
    QTcpServer* server;
    QTimer* readTimer;
};

#endif // MAINWINDOW_H
