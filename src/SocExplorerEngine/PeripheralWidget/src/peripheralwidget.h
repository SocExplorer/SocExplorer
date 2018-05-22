/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Plasma Physics Laboratory - CNRS
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 3 of the License, or
--  (at your option) any later version.
--
--  This program is distributed in the hope that it will be useful,
--  but WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--  GNU General Public License for more details.
--
--  You should have received a copy of the GNU General Public License
--  along with this program; if not, write to the Free Software
--  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
-------------------------------------------------------------------------------*/
/*--                  Author : Alexis Jeandet
--                     Mail : alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/
#ifndef PERIPHERALWIDGET_H
#define PERIPHERALWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QList>
#include <QTimer>
#include "registerwidget.h"
#if defined(SOCEXPLORER_SDK_BUILD)
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_EXPORT
#else
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_IMPORT
#endif

/*
 * TODO ADD an outdated marker
 * Show outdated registers with a different color for example
*/

class SOCEXPLORER_SDK_EXPORT peripheralWidget : public QWidget
{
    Q_OBJECT
public:
    class readWriteProxy
    {
    public:
        readWriteProxy() {}
        virtual void writeReg(qint32 address,qint32 value)=0;
        virtual qint32 readReg(qint32 address)=0;
    };

    explicit peripheralWidget(const QString& name,qint32 baseAddress,readWriteProxy* proxy=0, QWidget *parent = 0);
    registerWidget* registerAt(int index)
    {
        if(index>=0 && index<registersWdgts.count())
            return registersWdgts.at(index);
        return NULL;
    }
    int count();
    const QString& name();
signals:
    void writeRegSig(qint32 address,qint32 value);
    qint32 readRegSig(qint32 address);
    void clicked(peripheralWidget* sender);
    void upSig(peripheralWidget* sender,int cursorIndex);
    void downSig(peripheralWidget* sender,int cursorIndex);
public slots:
    void blinkCursor();
    void addRegister(const QString& name,qint32 address);
    void leave();
    void enter(int cursorIndex,bool fromTop=true);
    void setReadWriteProxy(readWriteProxy* proxy);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent * event);
    void paintEvent(QPaintEvent* event);

private:
    void up();
    void down();
    QString p_name;
    QString p_header;
    qint32 p_baseAddress;
    QList<registerWidget*> registersWdgts;
    int selectedReg;
    QTimer* p_timer;
    readWriteProxy* p_proxy;

};

#endif // PERIPHERALWIDGET_H
