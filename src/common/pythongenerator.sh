#!/bin/bash

#export QTDIR=/usr/include
export QTDIR=/usr/include/qt5

pythonqt_generator --output-directory=pythonQtOut PySocExplorer.h pythonQtgeneratorCfg.txt
