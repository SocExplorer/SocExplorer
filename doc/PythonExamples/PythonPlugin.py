#!/usr/bin/lppmon -e


class test(PySocExplorerEngine.socexplorerplugin):
    m_Layout = QtGui.QGridLayout()
    m_CenterWidget = QtGui.QWidget()
    m_hexviewer = PySocExplorer.QHexEdit()
    m_addressQSPB = PySocExplorer.QHexSpinBox()
    m_readQPB = QtGui.QPushButton("read")
    m_writeQPB = QtGui.QPushButton("write")

    def postInstantiationTrigger(self):
        print("building GUI")
        self.setWidget(self.m_CenterWidget)
        self.m_CenterWidget.setLayout(self.m_Layout)
        self.m_Layout.addWidget(self.m_addressQSPB, 0, 0, 1, 1)
        self.m_Layout.addWidget(self.m_readQPB, 0, 1, 1, 1)
        self.m_Layout.addWidget(self.m_writeQPB, 0, 2, 1, 1)
        self.m_Layout.addWidget(self.m_hexviewer, 1, 0, 1, -1)

    def hello(self):
        print("hello")

    def VID(self):
        return 10

    def PID(self):
        return 100

    def readData(self):
        bufferQBA = QtCore.QByteArray()
        buffer = self.parentPlugin().Read(self.m_addressQSPB.value, 16*1024)
        for i in range(0, 16*1024):
            bufferQBA.append(int(buffer[i]))
            bufferQBA.append(int(buffer[i]))
            bufferQBA.append(int(buffer[i]))
            bufferQBA.append(int(buffer[i]))
        self.m_hexviewer.setData(bufferQBA)



