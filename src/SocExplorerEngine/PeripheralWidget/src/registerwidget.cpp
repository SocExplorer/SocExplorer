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
#include "registerwidget.h"
#include <QPaintEvent>
#include <QPainter>

registerWidget::registerWidget(const QString &name, qint32 address, QObject *parent) :
    QObject(parent)
{
    p_address = address;
    p_value = 0;
    p_addressEl = new regWidgetElement(QString("0x%1").arg((uint)p_address,8,16).replace(" ","0"),QFont("Utopia", 12),10,4);
    p_fieldsEl = new bitfieldsElement(QString("%1").arg((uint)p_value,32,2).replace(" ","0"),QFont("Utopia", 12),4,4);
    p_nameEl = new regWidgetElement(name,QFont("Utopia", 12,QFont::Bold),4,4);
    p_xMargins = 4;
    p_yMargins = 6;
    updateBoundingRect();
}

registerWidget::~registerWidget()
{
    delete p_addressEl;
    delete p_fieldsEl;
    delete p_nameEl;
}

int registerWidget::contains(const QPointF &point)
{
    return p_boundingRect.contains(point.x(),point.y());
}

QPoint registerWidget::paint(QPainter* painter, QPoint offset)
{
    painter->save();
    painter->translate(offset);
    p_boundingRect.moveTopLeft(offset);
    painter->translate(p_addressEl->paint(painter));
    painter->translate(p_fieldsEl->paint(painter));
    p_nameEl->paint(painter);
    painter->restore();
    return QPoint(0,p_boundingRect.height()+p_boundingRect.y()+p_yMargins);
}

QRect registerWidget::boundingRect()
{
    return p_boundingRect;
}

uint registerWidget::cursorIndex()
{
    return p_fieldsEl->cursorIndex();
}

uint registerWidget::cursorIndex(int xPos)
{
    if(xPos>p_addressEl->boundingRect().width() && xPos<(p_addressEl->boundingRect().width()+p_fieldsEl->boundingRect().width()))
    {
        return p_fieldsEl->cursorIndex(xPos-p_addressEl->boundingRect().width());
    }
    return 0;
}

void registerWidget::updateSelection(int index)
{
    p_fieldsEl->updateSelection(index);
    emit this->repaint();
}

qint32 registerWidget::address()
{
    return p_address;
}

qint32 registerWidget::value()
{
    return p_value;
}

void registerWidget::setBitFieldAttribute(uint startIndex, uint stopIndex, const QString &name, const QString &description, bool rw)
{
    if(startIndex<=stopIndex && stopIndex<32)
    {
        int index= p_fieldsEl->addAttribute(name,description,rw );
        for(uint i=startIndex;i<=stopIndex;i++)
        {
            p_fieldsEl->setAttribute(i,index);
        }
    }
}

QString registerWidget::bitFieldDesc(int bitIndex)
{
    if(bitIndex>=0 && bitIndex<32)
    {
        return p_fieldsEl->description(bitIndex);
    }
    return QString("Out of range");
}

QString registerWidget::bitFieldName(int bitIndex)
{
    if(bitIndex>=0 && bitIndex<32)
    {
        return p_fieldsEl->name(bitIndex);
    }
    return QString("Out of range");
}

QString registerWidget::bitFieldToHex(int bitIndex)
{
    if(bitIndex>=0 && bitIndex<32)
    {
        return p_fieldsEl->valueHex(bitIndex);
    }
    return QString("Out of range");
}

QString registerWidget::bitFieldToDec(int bitIndex)
{
    if(bitIndex>=0 && bitIndex<32)
    {
        return p_fieldsEl->valueDec(bitIndex);
    }
    return QString("Out of range");
}

QString registerWidget::bitFieldToBin(int bitIndex)
{
    if(bitIndex>=0 && bitIndex<32)
    {
        // TODO do the convertion
        return p_fieldsEl->valueDec(bitIndex);
    }
    return QString("Out of range");
}

void registerWidget::setValue(qint32 value, bool updated)
{
    this->p_value = value;
    this->p_fieldsEl->setValue(QString("%1").arg((uint)p_value,32,2).replace(" ","0"));
    this->p_fieldsEl->setUpdated(updated);
    emit this->repaint();
}

void registerWidget::blinkCursor()
{
    p_fieldsEl->blinkCursor();
    //repaint();
}

void registerWidget::moveCursorLeft(int count)
{
    p_fieldsEl->moveCursorLeft(count);
    p_fieldsEl->blinkCursor();
}

void registerWidget::moveCursorRight(int count)
{
    p_fieldsEl->moveCursorRight(count);
    p_fieldsEl->blinkCursor();
}

void registerWidget::enter(int index)
{
    p_fieldsEl->enter(index);
}

void registerWidget::leave()
{
    p_fieldsEl->leave();
}

void registerWidget::clear(int index)
{
    if(!this->p_fieldsEl->readonly(index))
    {
        qint32 old = p_value;
        p_value &= ~(1<<index);
        if(old!=p_value)
            p_fieldsEl->setUpdated(false);
        this->p_fieldsEl->setValue(QString("%1").arg((uint)p_value,32,2).replace(" ","0"));
        emit this->repaint();
    }
}

void registerWidget::set(int index)
{
    if(!this->p_fieldsEl->readonly(index))
    {
        qint32 old = p_value;
        p_value |= 1<<index;
        if(old!=p_value)
            p_fieldsEl->setUpdated(false);
        this->p_fieldsEl->setValue(QString("%1").arg((uint)p_value,32,2).replace(" ","0"));
        emit this->repaint();
    }
}

void registerWidget::updateBoundingRect()
{
    p_boundingRect.setHeight(p_fieldsEl->boundingRect().height()+(p_yMargins*2));
    p_boundingRect.setWidth(p_fieldsEl->boundingRect().width()+p_addressEl->boundingRect().width()+p_nameEl->boundingRect().width()+(p_xMargins*2));
}



bitfieldsElement::bitfieldsElement(const QString &value, QFont font, int xMargin, int yMargin)
    :regWidgetElement(value,font,xMargin,yMargin)
{
    this->attributesLUT.append(new bitFieldAttribute(false,"UNSUSED","UNSUSED"));
    for(int i=0;i<32;i++)
    {
        attributesIndex[i] = 0;
    }
    p_startSelectionIndex = -1;
    p_stopSelectionIndex = -1;
    p_cursorIndex = -1;
    p_dx=QFontMetrics(p_font).width("0")+4;
    p_blinkTextBgColor = QColor(Qt::black);
    p_blinkTextColor = QColor(Qt::white);
    p_outdated = QColor(Qt::red);
    p_cursorBlinkEnable = false;
    p_changed = false;
    updateBoundingRect();
}

QPoint bitfieldsElement::paint(QPainter *painter)
{
    painter->fillRect(4,4,p_boundingRec.width(),p_boundingRec.height(),Qt::darkGray);
    painter->fillRect(0,0,p_boundingRec.width(),p_boundingRec.height(),Qt::white);
    painter->setFont(p_font);
    int lastAttributeIndex = attributesIndex[31];
    int xpos=p_xMargins;
    for(int i=0;i<(32/4);i++)
    {
        for(int l = 0;l<4;l++)
        {
            if(p_cursorBlinkEnable == false || (31-(int)p_cursorIndex) != ((i*4)+l))
            {
                if((int)p_startSelectionIndex!=-1 && (int)p_stopSelectionIndex!=-1 && p_startSelectionIndex <=(uint)31-(uint)((i*4)+l) && p_stopSelectionIndex >=(uint)31-(uint)((i*4)+l))
                {
                    QPen svg = painter->pen();
                    painter->setPen(p_blinkTextColor);
                    painter->fillRect(xpos-1,0,p_dx,p_boundingRec.height(),Qt::blue);
                    painter->drawText(xpos,QFontMetrics(p_font).ascent()+p_yMargins,p_valueStr.at((i*4)+l));
                    painter->setPen(svg);
                }
                else
                {
                    if(attributesLUT[attributesIndex[31-((i*4)+l)]]->rw==false)
                    {
                        painter->fillRect(xpos-1,0,p_dx,p_boundingRec.height(),Qt::lightGray);
                    }
                    else
                    {
                        painter->fillRect(xpos-1,0,p_dx,p_boundingRec.height(),Qt::white);
                    }
                    painter->drawText(xpos,QFontMetrics(p_font).ascent()+p_yMargins,p_valueStr.at((i*4)+l));
                }
            }
            else
            {
                QPen svg = painter->pen();
                painter->setPen(p_blinkTextColor);
                painter->fillRect(xpos-1,0,p_dx,p_boundingRec.height(),p_blinkTextBgColor);
                painter->drawText(xpos,QFontMetrics(p_font).ascent()+p_yMargins,p_valueStr.at((i*4)+l));
                painter->setPen(svg);
            }
            if(lastAttributeIndex!=attributesIndex[31-((i*4)+l)])
                painter->drawLine(xpos-(p_xMargins/2),0,xpos-(p_xMargins/2),p_boundingRec.height());
            lastAttributeIndex=attributesIndex[31-((i*4)+l)];
            xpos+=p_dx;
        }
        if(i==3)
            painter->drawLine(xpos+(p_xMargins/2),p_boundingRec.height()-6,xpos+(p_xMargins/2),p_boundingRec.height()+12);
        else if(i<7)
            painter->drawLine(xpos+(p_xMargins/2),p_boundingRec.height()-6,xpos+(p_xMargins/2),p_boundingRec.height()+6);
        xpos+=p_xMargins;
    }
    QPen svg = painter->pen();
    if(p_changed)
    {
        painter->setPen(p_outdated);
    }
    painter->drawRect(0,0,p_boundingRec.width(),p_boundingRec.height());
    painter->setPen(svg);
    return QPoint(p_boundingRec.width()+4+p_xMargins,0);
}

void bitfieldsElement::updateBoundingRect()
{
    p_boundingRec.setHeight(QFontMetrics(p_font).boundingRect(p_valueStr).height()+(p_yMargins*2));
    int width = (((4*(p_dx)) + p_xMargins) * 8) + (p_xMargins);
    p_boundingRec.setWidth(width);
}

void bitfieldsElement::setValue(const QString &value)
{
    p_valueStr = value;
    updateBoundingRect();
}

void bitfieldsElement::blinkCursor()
{
    p_cursorBlinkEnable = !p_cursorBlinkEnable;
}

void bitfieldsElement::moveCursorLeft(int count)
{
    p_cursorIndex+=count;
    if(31<p_cursorIndex)
    {
        p_cursorIndex = 31;
    }
    p_startSelectionIndex = p_cursorIndex;
    p_stopSelectionIndex = p_cursorIndex;

}

void bitfieldsElement::moveCursorRight(int count)
{
    p_cursorIndex -= count;
    if(31<p_cursorIndex)
    {
        p_cursorIndex = 0;
    }
    p_startSelectionIndex = p_cursorIndex;
    p_stopSelectionIndex = p_cursorIndex;
}

void bitfieldsElement::enter(int index)
{
    p_cursorIndex = index;
    p_cursorBlinkEnable = true;
    p_startSelectionIndex = -1;
    p_stopSelectionIndex = -1;
}

void bitfieldsElement::leave()
{
    p_cursorBlinkEnable = false;
    p_cursorIndex = -1;
    p_startSelectionIndex = -1;
    p_stopSelectionIndex = -1;
}

uint bitfieldsElement::cursorIndex()
{
    return p_cursorIndex;
}

uint bitfieldsElement::cursorIndex(int xPos)
{
    uint index=0;
    xPos-=p_xMargins;
    if(xPos<p_boundingRec.width())
    {
        index = 31 - ((4*xPos)/((4*p_dx)+p_xMargins));
    }
    return index;
}

void bitfieldsElement::setFont(QFont font)
{
    p_font = font;
    p_dx=QFontMetrics(p_font).width("0")+2;
    updateBoundingRect();
}

void bitfieldsElement::updateSelection(int index)
{
    if((int)p_cursorIndex!=-1)
    {
        if((int)p_startSelectionIndex!=-1 && (int)p_stopSelectionIndex!= -1)
        {
            if((uint)index>=p_stopSelectionIndex)
            {
                p_stopSelectionIndex = index;
                p_cursorIndex = index;
            }
            else
            {
                p_startSelectionIndex = index;
                p_cursorIndex = index;
            }
        }
        else
        {
            if((uint)index>p_cursorIndex)
            {
                p_startSelectionIndex = p_cursorIndex;
                p_stopSelectionIndex = index;
            }
            else
            {
                p_startSelectionIndex = index;
                p_stopSelectionIndex = p_cursorIndex;
            }
        }
    }
}












