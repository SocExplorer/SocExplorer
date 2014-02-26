#!/usr/bin/lppmon -e 
import numpy as np
freq1 = 30
freq2 = 300
time_step = 0.001

t_ini = -50 * 1.0/(max(freq1,freq2))
t_fin = -1 * t_ini

time_vec = np.arange(t_ini, t_fin, time_step)

#input signal
input_sig1 = np.sin(2 * np.pi * freq1 * time_vec)
input_sig2 = np.sin(2 * np.pi * freq2 * time_vec)
input_sig = input_sig1 + input_sig2


plot=Pylppmon.LppMonPlot()
plot.setTitle("demo")
plot.setXaxisLabel("Time(s)")
plot.setYaxisLabel("Values")

Courbe1=plot.addGraph()
Courbe2=plot.addGraph()
Courbe3=plot.addGraph()

plot.setGraphData(Courbe1,time_vec.tolist(),input_sig1.tolist())
plot.setGraphData(Courbe2,time_vec.tolist(),input_sig2.tolist())
plot.setGraphData(Courbe3,time_vec.tolist(),input_sig.tolist())
# none line stepleft stepright stepcenter impulse 
plot.setGraphLineStyle(0,"stepleft")
plot.setGraphLineStyle(Courbe2,"impulse")
#  none dot cross plus circle disc square diamond star triangle invertedtriangle crosssquare plussquare crosscircle pluscircle peace 
plot.setGraphScatterStyle(Courbe3,"square")

pen=plot.getGraphPen(1)
pen.setWidth(4)
color=pen.color()
color.setRgb(0x00FF00)
pen.setColor(color)
plot.setGraphPen(1,pen)

pen=plot.getGraphPen(0)
pen.setWidth(2)
color=pen.color()
color.setRgb(0xFF0000)
pen.setColor(color)
plot.setGraphPen(2,pen)

plot.rescaleAxis()












