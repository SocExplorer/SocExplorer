#!/usr/bin/lppmon -e 

class test(PySocExplorerEngine.socexplorerplugin):
	def hello(self):
	    print "hello"
	def VID(self):
	    return 10
	def PID(self):
	    return 100

