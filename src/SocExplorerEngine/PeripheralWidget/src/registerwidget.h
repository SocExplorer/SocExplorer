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
#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H
#include <QtWidgets>
#include <QWidget>
#include <QTimer>
#if defined(SOCEXPLORER_SDK_BUILD)
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_EXPORT
#else
#  define SOCEXPLORER_SDK_EXPORT Q_DECL_IMPORT
#endif

class SOCEXPLORER_SDK_EXPORT regWidgetElement
{
public:
    regWidgetElement(const QString& value,QFont font,int xMargin,int yMargin)
    {
        p_valueStr = value;
        p_font = font;
        p_xMargins = xMargin;
        p_yMargins = yMargin;
        updateBoundingRect();
    }
    void setValue(const QString& value)
    {
        p_valueStr = value;
        updateBoundingRect();
    }
    void setFont(QFont font)
    {
        p_font = font;
        updateBoundingRect();
    }
    QSize boundingRect(){return p_boundingRec;}
    QString value(){return p_valueStr;}
    const QChar	at ( int position ) const{return p_valueStr.at(position);}
    QFont font(){return p_font;}
    int xMargin(){return p_xMargins;}
    int yMargin(){return p_yMargins;}
    QFontMetrics fontMetrics(){return QFontMetrics(p_font);}
    QPoint paint(QPainter* painter)
    {
        painter->setFont(p_font);
        painter->drawText(0,QFontMetrics(p_font).ascent()+p_yMargins,p_valueStr);
        return QPoint(p_boundingRec.width(),0);
    }
    void updateBoundingRect()
    {
        p_boundingRec.setHeight(QFontMetrics(p_font).boundingRect(p_valueStr).height()+(p_yMargins*2));
        p_boundingRec.setWidth(QFontMetrics(p_font).boundingRect(p_valueStr).width()+(p_xMargins*2));
    }

protected:
    QString p_valueStr;
    QFont p_font;
    QSize p_boundingRec;
    int p_xMargins;
    int p_yMargins;
};

class SOCEXPLORER_SDK_EXPORT bitfieldsElement: public regWidgetElement
{
    class bitFieldAttribute
    {
    public:
        bitFieldAttribute(bool rw,QString name,QString description)
        {
            this->rw = rw;
            this->Name = name;
            this->description = description;
        }
        bool rw;
        QString description;
        QString Name;
    };
public:
    bitfieldsElement(const QString& value,QFont font,int xMargin,int yMargin);
    QPoint paint(QPainter* painter);

    void updateBoundingRect();
    void setValue(const QString& value);
    void blinkCursor();
    void moveCursorLeft(int count);
    void moveCursorRight(int count);
    void enter(int index);
    void leave();
    uint cursorIndex();
    uint cursorIndex(int xPos);
    void setFont(QFont font);
    void updateSelection(int index);
    int addAttribute(const QString& name,const QString& description,bool rw)
    {
        attributesLUT.append(new bitFieldAttribute(rw,name,description));
        return attributesLUT.count()-1;
    }

    int setAttribute(int bitIndex,int attributeIndex)
    {
        if(bitIndex>=0 && bitIndex<32 && attributeIndex>=0 && attributeIndex<(attributesLUT.count()))
        {
            attributesIndex[bitIndex]=attributeIndex;
            return 0;
        }
        return -1;
    }

    QString description(int bitIndex)
    {
        if(bitIndex>=0 && bitIndex<32)
            return attributesLUT.at(attributesIndex[bitIndex])->description;
        return QString("");
    }
    QString name(int bitIndex)
    {
        if(bitIndex>=0 && bitIndex<32)
            return attributesLUT.at(attributesIndex[bitIndex])->Name;
        return QString("");
    }
    bool readonly(int bitIndex)
    {
        if(bitIndex>=0 && bitIndex<32)
            return  !attributesLUT.at(attributesIndex[bitIndex])->rw;
        return false;
    }
    QString valueHex(int index)
    {
        if(index>=0 && index<32)
        {
            return "0x" + QString::number(p_valueUint(index),16);
        }
        return QString("");
    }
    QString valueDec(int index)
    {
        if(index>=0 && index<32)
        {
            return  QString::number(p_valueUint(index),10);
        }
        return QString("");
    }
    void setUpdated(bool updated=true)
    {
        this->p_changed =  !updated;
    }
private:
    uint p_valueUint(int index)
    {
        uint value;
        int attributeIndex = attributesIndex[index];
        int startIndex = index;
        int stopIndex=0;
        while (startIndex>0)
        {
            if(attributesIndex[startIndex-1]==attributeIndex)
                startIndex--;
            else
                break;
        }
        stopIndex = startIndex;
        while (stopIndex<32)
        {
            if(attributesIndex[stopIndex+1]==attributeIndex)
                stopIndex++;
            else
                break;
        }
        bool ok;
        value =  p_valueStr.toUInt(&ok,2);
        value = (uint)0xFFFFFFFF & (value<<(31-stopIndex));
        value = (uint)0xFFFFFFFF & (value>>(31-stopIndex+startIndex));
        return value;
    }
    int attributesIndex[32];
    uint p_cursorIndex;
    uint p_startSelectionIndex;
    uint p_stopSelectionIndex;
    bool p_cursorBlinkEnable;
    bool p_changed;
    int p_dx;
    QList<bitFieldAttribute*> attributesLUT;
    QColor p_blinkTextColor,p_blinkTextBgColor,p_outdated;

};


class SOCEXPLORER_SDK_EXPORT registerWidget : public QObject
{
    Q_OBJECT
public:
    explicit registerWidget(const QString& name,qint32 address,QObject *parent = 0);
    ~registerWidget();
    int contains(const QPointF &point);
    QPoint paint(QPainter* painter,QPoint offset);
    QRect boundingRect();
    uint cursorIndex();
    uint cursorIndex(int xPos);
    void updateSelection(int index);
    qint32 address();
    qint32 value();
    void setBitFieldAttribute(uint startIndex,uint stopIndex,const QString& name,const QString& description,bool rw);
    QString bitFieldDesc(int bitIndex);
    QString bitFieldName(int bitIndex);
    QString bitFieldToHex(int bitIndex);
    QString bitFieldToDec(int bitIndex);
    QString bitFieldToBin(int bitIndex);
    void setUpdated(bool updated=true)
    {
        this->p_fieldsEl->setUpdated(updated);
    }
signals:
    void cursorUp(int pos);
    void cursorDown(int pos);
    void valueChanged(qint32 value);
    void repaint();

public slots:
    void setValue(qint32 value,bool updated=true);
    void blinkCursor();
    void moveCursorLeft(int count);
    void moveCursorRight(int count);
    void enter(int index=0);
    void leave();
    void clear(int index);
    void set(int index);
private:
    void updateBoundingRect();
    qint32 p_address;
    qint32 p_value;
    QRect p_boundingRect;
    int p_xMargins;
    int p_yMargins;
    regWidgetElement* p_addressEl,*p_nameEl;
    bitfieldsElement* p_fieldsEl;
};

#endif // REGISTERWIDGET_H
