#!/usr/bin/lppmon -e 
def loadAHBUART():
  proxy.loadSysDriver("AHBUARTplugin");


proxy.loadSysDriver("AHBUARTplugin");
proxy.loadSysDriver("RMAPplugin","test");
proxy.loadSysDriverToParent("AHBplugin","AHBUARTplugin0");
proxy.loadSysDriverToParent("APBplugin","test");


widget=QtGui.QPushButton("load AHBUARTplugin")
widget.show();
widget.connect("clicked()",loadAHBUART);

