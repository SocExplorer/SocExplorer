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
#include "peripheralwidget.h"

peripheralWidget::peripheralWidget(const QString &name, qint32 baseAddress, readWriteProxy *proxy, QWidget *parent) :
    QWidget(parent)
{
    p_name = name;
    p_timer = new QTimer(this);
    p_timer->setInterval(500);
    p_baseAddress = baseAddress;
    p_header = p_name + QString(" @0x%1").arg((uint)p_baseAddress,8,16);
    p_proxy = proxy;
    setAttribute(Qt::WA_AlwaysShowToolTips);
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
    selectedReg = -1;
    registersWdgts.clear();
    connect(p_timer,SIGNAL(timeout()),this,SLOT(blinkCursor()));
    setFont(QFont("Utopia", 14,QFont::Bold));
    setMinimumSize(400,100);
    updateGeometry();
}

int peripheralWidget::count()
{
    return registersWdgts.count();
}

const QString &peripheralWidget::name()
{
    return this->p_name;
}

void peripheralWidget::blinkCursor()
{
    if(selectedReg!=-1)
        registersWdgts.at(selectedReg)->blinkCursor();
    repaint();
}

void peripheralWidget::addRegister(const QString &name, qint32 address)
{
    /*TODO  Should regs by address*/
    registersWdgts.append(new registerWidget(name,address));
    connect(registersWdgts.last(),SIGNAL(repaint()),this,SLOT(repaint()));
}

void peripheralWidget::leave()
{
    if(selectedReg!=-1)
    {
        p_timer->stop();
        registersWdgts.at(selectedReg)->leave();
        selectedReg = -1;
        repaint();
    }
}

void peripheralWidget::enter(int cursorIndex, bool fromTop)
{
    if(cursorIndex>=0 && cursorIndex<32)
    {
        if(fromTop)
        {
            registersWdgts.at(0)->enter(cursorIndex);
            selectedReg = 0;
        }
        else
        {
            registersWdgts.at(registersWdgts.count()-1)->enter(cursorIndex);
            selectedReg = registersWdgts.count()-1;
        }
        p_timer->start();
        this->setFocus();
    }
}

void peripheralWidget::setReadWriteProxy(peripheralWidget::readWriteProxy *proxy)
{
    this->p_proxy = proxy;
}

void peripheralWidget::mousePressEvent(QMouseEvent *event)
{
    p_timer->stop();
    if(selectedReg!=-1)
    {
        registersWdgts.at(selectedReg)->leave();
        selectedReg = -1;
    }
    for(int i=0; i<registersWdgts.count();i++)
    {
        if(registersWdgts.at(i)->contains(event->pos()))
        {
            registersWdgts.at(i)->enter(registersWdgts.at(i)->cursorIndex(event->pos().x()));
            selectedReg = i;
            p_timer->start();
            emit clicked(this);
        }
    }
    repaint();
}

void peripheralWidget::mouseMoveEvent(QMouseEvent *event)
{
    bool match=false;
    if(event->buttons()==Qt::LeftButton)
    {
        for(int i=0; i<registersWdgts.count();i++)
        {
            if(registersWdgts.at(i)->contains(event->pos()))
            {
                registersWdgts.at(i)->updateSelection(registersWdgts.at(i)->cursorIndex(event->pos().x()));
            }
        }
    }
    else
    {
        for(int i=0; i<registersWdgts.count();i++)
        {
            if(registersWdgts.at(i)->contains(event->pos()))
            {
                match = true;
                int bitfieldIndex=registersWdgts.at(i)->cursorIndex(event->pos().x());
                QString toolTipText ="<b>< font color='Black'>"+registersWdgts.at(i)->bitFieldName(bitfieldIndex) +"</b><br />";
                toolTipText+= "Hexadecimal=<b>< font color='Blue'>"+registersWdgts.at(i)->bitFieldToHex(bitfieldIndex)+"</b>";
                toolTipText+= "    Decimal=<b>< font color='BlueViolet'>"+registersWdgts.at(i)->bitFieldToDec(bitfieldIndex)+"</b><br />";
                toolTipText+= registersWdgts.at(i)->bitFieldDesc(bitfieldIndex);
                QToolTip::showText(event->globalPos(),toolTipText,(QWidget*)this);
            }
        }
        if(!match)QToolTip::hideText();
    }
}

void peripheralWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}

void peripheralWidget::keyPressEvent(QKeyEvent *event)
{
    if(this->selectedReg!=-1){
        if(event->modifiers()==Qt::ControlModifier)
        {
            switch(event->key())
            {
            case Qt::Key_Up:
                registersWdgts.at(selectedReg)->set(registersWdgts.at(selectedReg)->cursorIndex());
                break;
            case Qt::Key_Down:
                registersWdgts.at(selectedReg)->clear(registersWdgts.at(selectedReg)->cursorIndex());
                break;
            case Qt::Key_W:
                p_proxy->writeReg(registersWdgts.at(selectedReg)->address(),registersWdgts.at(selectedReg)->value());
                registersWdgts.at(selectedReg)->setUpdated(true);
                registersWdgts.at(selectedReg)->repaint();
                break;
            case Qt::Key_R:
                qint32 value;
                value = p_proxy->readReg(registersWdgts.at(selectedReg)->address());
                registersWdgts.at(selectedReg)->setValue(value);
                break;
            default:
                break;
            }
        }
        else
        {
            switch(event->key())
            {
            case Qt::Key_0:
                registersWdgts.at(selectedReg)->clear(registersWdgts.at(selectedReg)->cursorIndex());
                registersWdgts.at(selectedReg)->moveCursorRight(1);
                break;
            case Qt::Key_1:
                registersWdgts.at(selectedReg)->set(registersWdgts.at(selectedReg)->cursorIndex());
                registersWdgts.at(selectedReg)->moveCursorRight(1);
                break;
            case Qt::Key_Right:
                registersWdgts.at(selectedReg)->moveCursorRight(1);
                this->repaint();
                break;
            case Qt::Key_Left:
                registersWdgts.at(selectedReg)->moveCursorLeft(1);
                this->repaint();
                break;
            case Qt::Key_Up:
                up();
                break;
            case Qt::Key_Down:
                down();
                break;
            case Qt::Key_W:
                p_proxy->writeReg(registersWdgts.at(selectedReg)->address(),registersWdgts.at(selectedReg)->value());
                registersWdgts.at(selectedReg)->setUpdated(true);
                registersWdgts.at(selectedReg)->repaint();
                break;
            case Qt::Key_R:
                qint32 value;
                value = p_proxy->readReg(registersWdgts.at(selectedReg)->address());
                registersWdgts.at(selectedReg)->setValue(value);
                break;
            default:
                break;
            }
        }

    }
}

void peripheralWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    QPoint offset=QPoint(0,0);
    int nameWidth = fontMetrics().width(p_header);
    if(registersWdgts.count()==0)
    {
        setMinimumSize(2*nameWidth+10,fontMetrics().height()+10);
    }
    painter.drawText((this->minimumWidth()/2)-nameWidth,4,fontMetrics().width(p_header),fontMetrics().height()+4,Qt::AlignCenter,p_header);
    offset+=QPoint(0,fontMetrics().height()+8);
    for(int i=0;i<registersWdgts.count();i++)
    {
        offset = registersWdgts.at(i)->paint(&painter,offset);
    }
    if(registersWdgts.count()>0)
    {
        int w=registersWdgts.first()->boundingRect().width();
        int h=offset.y();
        setMinimumSize(w,h);
    }
    updateGeometry();

}

void peripheralWidget::up()
{
    if(selectedReg!=-1)
    {
        if(selectedReg >0)
        {
            registersWdgts.at(selectedReg-1)->enter(registersWdgts.at(selectedReg)->cursorIndex());
            registersWdgts.at(selectedReg)->leave();
            selectedReg-=1;
            repaint();
        }
        else
        {
            emit upSig(this,registersWdgts.at(selectedReg)->cursorIndex());
        }
    }
}

void peripheralWidget::down()
{
    if(selectedReg!=-1)
    {
        if(selectedReg <(registersWdgts.count()-1))
        {
            registersWdgts.at(selectedReg+1)->enter(registersWdgts.at(selectedReg)->cursorIndex());
            registersWdgts.at(selectedReg)->leave();
            selectedReg+=1;
            repaint();
        }
        else
        {
            emit downSig(this,registersWdgts.at(selectedReg)->cursorIndex());
        }
    }
}
