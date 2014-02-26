#ifndef TCP_TERMINAL_CLIENT_H
#define TCP_TERMINAL_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QProcess>
#include <QThread>
#include <QMutex>


class TCP_Terminal_Client : public QObject
{
    Q_OBJECT
public:
    explicit TCP_Terminal_Client(QObject *parent = 0);
    void connectToServer(const QString& IP,int port);
    void connectToServer();
    bool isConnected();
    void sendText(const QString& text);
    void startServer();
    void startServer(int port);
signals:
    
public slots:

private:
    QTcpSocket* soc;
    QProcess* ServerProc;
};

#endif // TCP_TERMINAL_CLIENT_H
