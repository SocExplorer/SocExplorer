#!/usr/bin/socexplorer -e 
import numpy as np
freq1 = 30
freq2 = 300
time_step = 0.000001

t_ini = -500 * 1.0/(max(freq1,freq2))
t_fin = -1 * t_ini

time_vec = np.arange(t_ini, t_fin, time_step)

#input signal
input_sig1 = np.sin(2 * np.pi * freq1 * time_vec)


plot=PySocExplorer.SocExplorerPlot()
plot.setTitle("demo")
plot.setXaxisLabel("Time(s)")
plot.setYaxisLabel("Values")

Courbe1=plot.addGraph()

plot.setGraphData(Courbe1,time_vec.tolist(),input_sig1.tolist())

plot.rescaleAxis()












