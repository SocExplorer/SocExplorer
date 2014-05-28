#!/bin/bash

#export QTDIR=/usr/include
export QTDIR=/usr/include/qt5

pythonqt_generator --dump-object-tree --output-directory=pythonQtOut PySocExplorer.h pythonQtgeneratorCfg.txt
