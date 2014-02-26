#ifndef SOCEXPLORERPLOT_H
#define SOCEXPLORERPLOT_H

#include <QWidget>
#include <QGridLayout>
#include <qcustomplot.h>

class SocExplorerPlot : public QWidget
{
    Q_OBJECT
public:
    explicit SocExplorerPlot(QWidget *parent = 0);
    void setTitle(QString title);
    void setXaxisLabel(QString label);
    void setXaxisRange(double lower, double upper);
    void setYaxisLabel(QString label);
    void setYaxisRange(double lower, double upper);
    void rescaleAxis();
    void setLegendFont(QFont font);
    void setLegendSelectedFont(QFont font);
    int addGraph();
    void setGraphName(int graphIndex,QString name);
    void setGraphData(int graphIndex, QList<QVariant> x, QList<QVariant> y);
    void addGraphData(int graphIndex, QList<QVariant> x, QList<QVariant> y);
    void addGraphData(int graphIndex, QVariant x, QVariant y);
    void setGraphPen(int graphIndex,QPen pen);
    QPen getGraphPen(int graphIndex);
    void setGraphLineStyle(int graphIndex,QString lineStyle);
    void setGraphScatterStyle(int graphIndex,QString scatterStyle);
    void show();

signals:
    
public slots:

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void wheelEvent(QWheelEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QCustomPlot* m_plot;
    QGridLayout* m_mainlayout;
    bool ctrl_hold;
    bool shift_hold;
    bool mouse_hold;
    QCPRange DragStartHorzRange;
    QCPRange DragStartVertRange;
    QPoint mDragStart;
};

#endif // SOCEXPLORERPLOT_H
