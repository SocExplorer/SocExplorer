#ifndef QTABLEWIDGETINTITEM_H
#define QTABLEWIDGETINTITEM_H

#include <QTableWidgetItem>

#define DecimalItem 0
#define HexaDecimalItem 1

class QTableWidgetIntItem : public QTableWidgetItem
{

public:
    explicit QTableWidgetIntItem(const QString& text, int Type);
    bool operator <(const QTableWidgetItem &other)const;
    bool operator >(const QTableWidgetItem &other)const;
    bool operator ==(const QTableWidgetItem &other)const;
    int toInt() const;
    int toInt(const QTableWidgetItem &item) const;

};

#endif // QTABLEWIDGETINTITEM_H
