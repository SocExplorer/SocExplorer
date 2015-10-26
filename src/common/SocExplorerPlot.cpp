#include "SocExplorerPlot.h"



SocExplorerPlot::SocExplorerPlot(QWidget *parent) :
  QWidget(parent), mRubberBand(new QRubberBand(QRubberBand::Rectangle, this))
{
  this->m_plot = new QCustomPlot(this);
  this->m_plot->setInteractions(QCP::iRangeDrag  | QCP::iSelectAxes |
                                QCP::iSelectLegend | QCP::iSelectPlottables);
  this->m_plot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
  this->m_plot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
  this->m_mainlayout = new QGridLayout(this);
  this->setLayout(this->m_mainlayout);
  this->m_mainlayout->addWidget(this->m_plot);
  this->setMinimumSize(400,300);
  this->setFocusPolicy(Qt::WheelFocus);
  this->m_plot->setAttribute(Qt::WA_TransparentForMouseEvents);
  this->ctrl_hold = false;
  this->shift_hold = false;
  this->mouse_hold = false;
  this->m_plot->setNoAntialiasingOnDrag(true);
  this->show();
}

SocExplorerPlot::~SocExplorerPlot()
{
  delete mRubberBand;
}

void SocExplorerPlot::show()
{
  QWidget::show();
}

void SocExplorerPlot::replot()
{
  this->m_plot->replot();
}

void SocExplorerPlot::setTitle(QString title)
{
  Q_UNUSED(title)
  //this->m_plot->setTitle(title);
  /*!
  @todo Function borcken fixe this!
*/
  this->repaint();
}

void SocExplorerPlot::setXaxisLabel(QString label)
{
  this->m_plot->xAxis->setLabel(label);
  this->repaint();
}

void SocExplorerPlot::setYaxisLabel(QString label)
{
  this->m_plot->yAxis->setLabel(label);
  this->repaint();
}

void SocExplorerPlot::setXaxisRange(double lower, double upper)
{
  this->m_plot->xAxis->setRange(lower,upper);
}

void SocExplorerPlot::setYaxisRange(double lower, double upper)
{
  this->m_plot->yAxis->setRange(lower,upper);
}


void SocExplorerPlot::rescaleAxis()
{
  this->m_plot->rescaleAxes();
  this->m_plot->replot();
}

void SocExplorerPlot::setLegendFont(QFont font)
{
  this->m_plot->legend->setFont(font);
  this->repaint();
}

void SocExplorerPlot::setLegendSelectedFont(QFont font)
{
  this->m_plot->legend->setSelectedFont(font);
  this->repaint();
}

void SocExplorerPlot::setAdaptativeSampling(int graphIndex, bool enable)
{
  this->m_plot->graph(graphIndex)->setAdaptiveSampling(enable);
}

int SocExplorerPlot::addGraph()
{
  this->m_plot->addGraph();
  return this->m_plot->graphCount() -1;
}

bool SocExplorerPlot::removeGraph(int graphIndex)
{
  return this->m_plot->removeGraph(graphIndex);
}

void SocExplorerPlot::removeAllGraphs()
{
  int graphCount=this->m_plot->graphCount();
  for(int i=0;i<graphCount;i++)
    {
      this->m_plot->removeGraph(0);
    }
}


void SocExplorerPlot::setGraphName(int graphIndex,QString name)
{
  if(graphIndex<this->m_plot->graphCount())
    {
      this->m_plot->graph(graphIndex)->setName(name);
    }
}


void SocExplorerPlot::setGraphData(int graphIndex, QList<QVariant> x, QList<QVariant> y)
{
  if((graphIndex<this->m_plot->graphCount()) && (x.count()==y.count()))// && (x.at(0).type()==QVariant::Double))
    {
      QVector<double> _x(x.count()), _y(y.count());
      for(int i=0;i<x.count();i++)
        {
          /*_x[i] = x.at(i).value<double>();
            _y[i] = y.at(i).value<double>();*/
          _x[i] = x.at(i).toDouble();
          _y[i] = y.at(i).toDouble();
        }
      this->m_plot->graph(graphIndex)->setData(_x,_y);
    }
  this->m_plot->replot();
}

void SocExplorerPlot::addGraphData(int graphIndex, QList<QVariant> x, QList<QVariant> y)
{
  if((graphIndex<this->m_plot->graphCount()) && (x.count()==y.count()))// && (x.at(0).type()==QVariant::Double))
    {
      QVector<double> _x(x.count()), _y(y.count());
      for(int i=0;i<x.count();i++)
        {
          /*_x[i] = x.at(i).value<double>();
            _y[i] = y.at(i).value<double>();*/
          _x[i] = x.at(i).toDouble();
          _y[i] = y.at(i).toDouble();
        }
      this->m_plot->graph(graphIndex)->addData(_x,_y);
    }
  this->m_plot->replot();
}

void SocExplorerPlot::addGraphData(int graphIndex, QVariant x, QVariant y)
{
  if(graphIndex<this->m_plot->graphCount())// && (x.at(0).type()==QVariant::Double))
    {
      this->m_plot->graph(graphIndex)->addData(x.toDouble(),y.toDouble());
    }
  this->m_plot->replot();
}

void SocExplorerPlot::setGraphPen(int graphIndex,QPen pen)
{
  if(graphIndex<this->m_plot->graphCount())
    {
      this->m_plot->graph(graphIndex)->setPen(pen);
    }
}

QPen SocExplorerPlot::getGraphPen(int graphIndex)
{
  if(graphIndex<this->m_plot->graphCount())
    {
      return this->m_plot->graph(graphIndex)->pen();
    }
  return this->m_plot->graph()->pen();
}



void SocExplorerPlot::setGraphLineStyle(int graphIndex,QString lineStyle)
{
  if(graphIndex<this->m_plot->graphCount())
    {
      if(!lineStyle.compare("none"))
        {
          this->m_plot->graph(graphIndex)->setLineStyle(QCPGraph::lsNone);
          return;
        }
      if(!lineStyle.compare("line"))
        {
          this->m_plot->graph(graphIndex)->setLineStyle(QCPGraph::lsLine);
          return;
        }
      if(!lineStyle.compare("stepleft"))
        {
          this->m_plot->graph(graphIndex)->setLineStyle(QCPGraph::lsStepLeft);
          return;
        }
      if(!lineStyle.compare("stepright"))
        {
          this->m_plot->graph(graphIndex)->setLineStyle(QCPGraph::lsStepRight);
          return;
        }
      if(!lineStyle.compare("stepcenter"))
        {
          this->m_plot->graph(graphIndex)->setLineStyle(QCPGraph::lsStepCenter);
          return;
        }
      if(!lineStyle.compare("impulse"))
        {
          this->m_plot->graph(graphIndex)->setLineStyle(QCPGraph::lsImpulse);
          return;
        }


    }
}

void SocExplorerPlot::setGraphScatterStyle(int graphIndex,QString scatterStyle)
{
  if(graphIndex<this->m_plot->graphCount())
    {
      if(!scatterStyle.compare("none"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssNone);
          return;
        }
      if(!scatterStyle.compare("dot"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssDot);
          return;
        }
      if(!scatterStyle.compare("cross"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssCross);
          return;
        }
      if(!scatterStyle.compare("plus"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssPlus);
          return;
        }
      if(!scatterStyle.compare("circle"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssCircle);
          return;
        }
      if(!scatterStyle.compare("disc"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssDisc);
          return;
        }
      if(!scatterStyle.compare("square"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssSquare);
          return;
        }
      if(!scatterStyle.compare("diamond"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssDiamond);
          return;
        }
      if(!scatterStyle.compare("star"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssStar);
          return;
        }
      if(!scatterStyle.compare("triangle"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssTriangle);
          return;
        }
      if(!scatterStyle.compare("invertedtriangle"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssTriangleInverted);
          return;
        }
      if(!scatterStyle.compare("crosssquare"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssCrossSquare);
          return;
        }
      if(!scatterStyle.compare("plussquare"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssPlusSquare);
          return;
        }
      if(!scatterStyle.compare("crosscircle"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssCrossCircle);
          return;
        }
      if(!scatterStyle.compare("pluscircle"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssPlusCircle);
          return;
        }
      if(!scatterStyle.compare("peace"))
        {
          this->m_plot->graph(graphIndex)->setScatterStyle(QCPScatterStyle::ssPeace);
          return;
        }

    }
}

void SocExplorerPlot::setXaxisTickLabelType(QCPAxis::LabelType type)
{
  this->m_plot->xAxis->setTickLabelType(type);
}

void SocExplorerPlot::setXaxisDateTimeFormat(const QString &format)
{
  this->m_plot->xAxis->setDateTimeFormat(format);
}





void SocExplorerPlot::keyPressEvent(QKeyEvent * event)
{
  switch(event->key())
    {
    case Qt::Key_Control:
      this->ctrl_hold = true;
      setCursor(Qt::CrossCursor);
      break;
    case Qt::Key_Shift:
      this->shift_hold = true;
      break;
    case Qt::Key_M:
      this->rescaleAxis();
      break;
    case Qt::Key_Left:
      if(!ctrl_hold)
        {
          move(-0.1,Qt::Horizontal);
        }
      else
        {
          zoom(2,this->width()/2,Qt::Horizontal);
        }
      break;
    case Qt::Key_Right:
      if(!ctrl_hold)
        {
          move(0.1,Qt::Horizontal);
        }
      else
        {
          zoom(0.5,this->width()/2,Qt::Horizontal);
        }
      break;
    case Qt::Key_Up:
      if(!ctrl_hold)
        {
          move(0.1,Qt::Vertical);
        }
      else
        {
          zoom(0.5,this->height()/2,Qt::Vertical);
        }
      break;
    case Qt::Key_Down:
      if(!ctrl_hold)
        {
          move(-0.1,Qt::Vertical);
        }
      else
        {
          zoom(2,this->height()/2,Qt::Vertical);
        }
      break;
    default:
      QWidget::keyPressEvent(event);
      break;
    }
}

void SocExplorerPlot::keyReleaseEvent(QKeyEvent * event)
{
  switch(event->key())
    {
    case Qt::Key_Control:
      event->accept();
      this->ctrl_hold = false;
      break;
    case Qt::Key_Shift:
      event->accept();
      this->shift_hold = false;
      break;
    default:
      QWidget::keyReleaseEvent(event);
      break;
    }
  setCursor(Qt::ArrowCursor);
}

void SocExplorerPlot::wheelEvent(QWheelEvent * event)
{
  double factor;
  double wheelSteps = event->delta()/120.0; // a single step delta is +/-120 usually
  if(ctrl_hold)
    {
      if (event->orientation()==Qt::Vertical)//mRangeZoom.testFlag(Qt::Vertical))
        {
          setCursor(Qt::SizeVerCursor);
          factor = pow(this->m_plot->axisRect()->rangeZoomFactor(Qt::Vertical), wheelSteps);
          zoom(factor,event->pos().y(),Qt::Vertical);
        }
      QWidget::wheelEvent(event);
      return;
    }
  if(shift_hold)
    {
      if (event->orientation()==Qt::Vertical)//mRangeZoom.testFlag(Qt::Vertical))
        {
          setCursor(Qt::SizeHorCursor);
          factor = pow(this->m_plot->axisRect()->rangeZoomFactor(Qt::Horizontal), wheelSteps);
          zoom(factor,event->pos().x(),Qt::Horizontal);
        }
      QWidget::wheelEvent(event);
      return;
    }
  move(wheelSteps/10,Qt::Horizontal);
  QWidget::wheelEvent(event);
}




void SocExplorerPlot::mousePressEvent(QMouseEvent *event)
{
  if(event->button()==Qt::LeftButton)
    {
      if(ctrl_hold)
        {
          setCursor(Qt::CrossCursor);
          mOrigin = event->pos();
          mRubberBand->setGeometry(QRect(mOrigin, QSize()));
          mRubberBand->show();
        }
      else
        {
          setCursor(Qt::ClosedHandCursor);
          mDragStart = event->pos();
          this->mouse_hold = true;
          DragStartHorzRange = this->m_plot->axisRect()->rangeDragAxis(Qt::Horizontal)->range();
          DragStartVertRange = this->m_plot->axisRect()->rangeDragAxis(Qt::Vertical)->range();
        }
    }
  QWidget::mousePressEvent(event);
}

void SocExplorerPlot::mouseReleaseEvent(QMouseEvent *event)
{
  if(event->button()==Qt::LeftButton)
    {
      this->mouse_hold = false;
    }
  if (mRubberBand->isVisible())
    {
      const QRect & zoomRect = mRubberBand->geometry();
      int xp1, yp1, xp2, yp2;
      zoomRect.getCoords(&xp1, &yp1, &xp2, &yp2);
      double x1 = this->m_plot->xAxis->pixelToCoord(xp1);
      double x2 = this->m_plot->xAxis->pixelToCoord(xp2);
      double y1 = this->m_plot->yAxis->pixelToCoord(yp1);
      double y2 = this->m_plot->yAxis->pixelToCoord(yp2);

      this->m_plot->xAxis->setRange(x1, x2);
      this->m_plot->yAxis->setRange(y1, y2);

      mRubberBand->hide();
      this->m_plot->replot();
    }
  setCursor(Qt::ArrowCursor);
  QWidget::mouseReleaseEvent(event);
}

void SocExplorerPlot::zoom(double factor, int center, Qt::Orientation orientation)
{
  QCPAxis* axis = this->m_plot->axisRect()->rangeZoomAxis(orientation);
  axis->scaleRange(factor, axis->pixelToCoord(center));
  this->m_plot->replot();
}

void SocExplorerPlot::move(double factor, Qt::Orientation orientation)
{
  QCPAxis* axis = this->m_plot->axisRect()->rangeDragAxis(orientation);
  double rg = (axis->range().upper - axis->range().lower)*(factor);
  axis->setRange(axis->range().lower+(rg), axis->range().upper+(rg));
  this->m_plot->replot();
}


void SocExplorerPlot::mouseMoveEvent(QMouseEvent *event)
{
  if(mouse_hold)
    {
      QCPAxis* Haxis = this->m_plot->axisRect()->rangeDragAxis(Qt::Horizontal);
      QCPAxis* Vaxis = this->m_plot->axisRect()->rangeDragAxis(Qt::Vertical);
      double diff = Haxis->pixelToCoord(mDragStart.x()) - Haxis->pixelToCoord(event->pos().x());
      Haxis->setRange(DragStartHorzRange.lower+diff, DragStartHorzRange.upper+diff);
      diff = Vaxis->pixelToCoord(mDragStart.y()) - Vaxis->pixelToCoord(event->pos().y());
      Vaxis->setRange(DragStartVertRange.lower+diff, DragStartVertRange.upper+diff);
      this->m_plot->replot();
    }
  if (mRubberBand->isVisible())
    {
      mRubberBand->setGeometry(QRect(mOrigin, event->pos()).normalized());
    }
  QWidget::mouseMoveEvent(event);
}











