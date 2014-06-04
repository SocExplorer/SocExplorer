#include "qtablewidgetintitem.h"

QTableWidgetIntItem::QTableWidgetIntItem(const QString &text,int Type)
    :QTableWidgetItem(text,Type)
{
}

bool QTableWidgetIntItem::operator <(const QTableWidgetItem& other) const
{
    return toInt() < toInt(other);
}

bool QTableWidgetIntItem::operator >(const QTableWidgetItem &other) const
{
    return toInt() > toInt(other);
}

bool QTableWidgetIntItem::operator ==(const QTableWidgetItem &other) const
{
    return toInt() == toInt(other);
}

int QTableWidgetIntItem::toInt() const
{
    bool ok=true;
    if(type()==DecimalItem)
    {
        return text().toInt();
    }
    else if(type()==HexaDecimalItem)
    {
        return text().replace("0x","").toInt(&ok,16);
    }
    return 0;
}

int QTableWidgetIntItem::toInt(const QTableWidgetItem &item) const
{
    bool ok=true;
    if(item.type()==DecimalItem)
    {
        return item.text().toInt();
    }
    else if(item.type()==HexaDecimalItem)
    {
        return item.text().replace("0x","").toInt(&ok,16);
    }
    return 0;
}


