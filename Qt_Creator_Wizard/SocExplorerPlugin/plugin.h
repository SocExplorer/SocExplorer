/*------------------------------------------------------------------------------
-------------------------------------------------------------------------------*/
/*--                  Author : %driver_Author%
--                     Mail : %driver_Mail%
----------------------------------------------------------------------------*/
#ifndef %ProjectName%_H
#define %ProjectName%_H
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLayout>

#include <socexplorerplugin.h>



class %ProjectName% : public socexplorerplugin
{
    Q_OBJECT
public:
    explicit %ProjectName%(QWidget *parent = 0);
    ~%ProjectName%();
    /* You can implement the folowing function if you want to overwrite
     *  their default behavior
    */
    /*
    int registermenu(QMainWindow *menuHolder);
    int isConnected();
    int connect();
    int VID(){return driver_VID;}
    int PID(){return driver_PID;}
    */

public slots:
    unsigned int Write(unsigned int *Value,unsigned int count, unsigned int address=0);
    unsigned int Read(unsigned int *Value,unsigned int count, unsigned int address=0);
signals:

private:


};

#endif // %ProjectName%_H
