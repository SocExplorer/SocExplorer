#!/usr/bin/lppmon -e 
import time
terminal=Pylppmon.TCP_Terminal_Client()
terminal.startServer()
terminal2=Pylppmon.TCP_Terminal_Client()
terminal2.startServer(2200)
terminal2.connectToServer("127.0.0.1",2200)

terminal.connectToServer()
terminal.sendText("<p><b> "+str(time.ctime())+": </b></p>"+"Hello World")
terminal2.sendText("<p><b> "+str(time.ctime())+": </b></p>"+"Hello World on terminal 2")
terminal.sendText("<p><b> "+str(time.ctime())+": </b></p>")
terminal.sendText("<p><b> "+str(time.ctime())+": </b></p>"+"<ul>HTML Items List Example:<LI>Item1</LI><LI>Item2</LI></ul>")
terminal.sendText("<p><b> "+str(time.ctime())+": </b></p>"+"<p style=\"color:#0000ff\" style=\"background-color:#00ff00\">hello</p>") 
for i in range(0,100):
    terminal.sendText("<p><b>"+str(time.ctime())+": </b></p>"+"<p style=\"color:#0000ff\" style=\"background-color:#00ff00\">hello "+str(i)+"</p>") 
    time.sleep(0.05)
