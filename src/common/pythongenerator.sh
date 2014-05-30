#!/bin/bash

#export QTDIR=/usr/include
#export QTDIR=/usr/include/qt5

pythonqt_generator  -include-paths="./elf /usr/include/qt5 /usr/include/qt5/QtWidgets"  --output-directory=pythonQtOut PySocExplorer.h pythonQtgeneratorCfg.txt
