#ifndef COLLAPSABLEPERIPHERALWIDGET_H
#define COLLAPSABLEPERIPHERALWIDGET_H

#include <QWidget>
#include <peripheralwidget.h>
#include <QTimer>

namespace Ui {
class CollapsablePeripheralWidget;
}

class QRegToolTipLabel : public QLabel
{
    Q_OBJECT
public:
    QRegToolTipLabel(QWidget * parent = 0, Qt::WindowFlags f = 0):QLabel(parent,f){}
    QRegToolTipLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0):QLabel(text,parent,f){}
signals:
    void enter();
    void leave();
    void clicked();
protected:
    void enterEvent(QEvent* event){emit enter();QLabel::enterEvent(event);}
    void leaveEvent(QEvent* event){emit leave();QLabel::leaveEvent(event);}
    void mousePressEvent(QMouseEvent * event){emit clicked();QLabel::mousePressEvent(event);}
};

class CollapsablePeripheralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CollapsablePeripheralWidget(peripheralWidget* periph,QWidget *parent = 0);
    ~CollapsablePeripheralWidget();
    void setPeripheralWidget(peripheralWidget* periph);
    peripheralWidget* getPeripheralWidget();
protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
public slots:
    void collapse();
    void setName(const QString& name);
    void showTooltip();
    void hideTooltip();
signals:
    void clicked(peripheralWidget* sender);
    void upSig(peripheralWidget* sender,int cursorIndex);
    void downSig(peripheralWidget* sender,int cursorIndex);
private:
    Ui::CollapsablePeripheralWidget *ui;
    peripheralWidget* m_periph;
    bool m_collapsed;
    QTimer tthidetmr;
};

#endif // COLLAPSABLEPERIPHERALWIDGET_H
