#!/bin/bash

#export QTDIR=/usr/include
#export QTDIR=/usr/include/qt5

pythonqt_generator  --include-paths=./plugins:/usr/include/qt5:/usr/include/qt5/QtCore:/usr/include/qt5/QtWidgets  --output-directory=pythonQtOut PySocExplorerEngine.h pythonQtgeneratorCfg.txt
