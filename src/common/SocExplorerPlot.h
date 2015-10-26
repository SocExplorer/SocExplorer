#ifndef SOCEXPLORERPLOT_H
#define SOCEXPLORERPLOT_H

#include <QWidget>
#include <QGridLayout>
#include <qcustomplot.h>
#include <QRubberBand>
#include <QPoint>

class SocExplorerPlot : public QWidget
{
  Q_OBJECT
public:
  explicit SocExplorerPlot(QWidget *parent = 0);
  ~SocExplorerPlot();
  void setTitle(QString title);
  void setXaxisLabel(QString label);
  void setXaxisRange(double lower, double upper);
  void setYaxisLabel(QString label);
  void setYaxisRange(double lower, double upper);
  void rescaleAxis();
  void setLegendFont(QFont font);
  void setLegendSelectedFont(QFont font);
  void setAdaptativeSampling(int graphIndex,bool enable);
  int addGraph();
  bool removeGraph(int graphIndex);
  void removeAllGraphs();
  void setGraphName(int graphIndex,QString name);
  void setGraphData(int graphIndex, QList<QVariant> x, QList<QVariant> y);
  void setGraphData(int graphIndex, QCPDataMap* data,bool copy = true,bool replot=true);
  void addGraphData(int graphIndex, QList<QVariant> x, QList<QVariant> y);
  void addGraphData(int graphIndex, QVariant x, QVariant y);
  void setGraphPen(int graphIndex,QPen pen);
  QPen getGraphPen(int graphIndex);
  void setGraphLineStyle(int graphIndex,QString lineStyle);
  void setGraphScatterStyle(int graphIndex,QString scatterStyle);
  void setXaxisTickLabelType(QCPAxis::LabelType type);
  void setXaxisDateTimeFormat(const QString &format);
  void show();
  void replot();

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
  void zoom(double factor, int center, Qt::Orientation orientation);
  void move(double factor, Qt::Orientation orientation);
  QCustomPlot* m_plot;
  QGridLayout* m_mainlayout;
  bool ctrl_hold;
  bool shift_hold;
  bool mouse_hold;
  QCPRange DragStartHorzRange;
  QCPRange DragStartVertRange;
  QPoint mDragStart;
  bool mZoomMode;
  QRubberBand * mRubberBand;
  QPoint mOrigin;
};

#endif // SOCEXPLORERPLOT_H
