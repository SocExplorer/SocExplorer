#!/usr/bin/socexplorer -e 

proxy.loadSysDriver("AHBUARTplugin","AHBUART");
proxy.loadSysDriverToParent("dsu3plugin","AHBUART");
proxy.loadSysDriverToParent("APB_UART_PLUGIN","AHBUART");
AHBUART.open("/dev/ttyUSB0",30000000)
FILE=QtGui.QFileDialog.getOpenFileName()
if FILE!="":
   dsu3plugin0.openFile(FILE)
   dsu3plugin0.loadFile()
   dsu3plugin0.run()
   print "File loaded and running"
