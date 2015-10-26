#!bash

export QTDIR=/c/Qt/5.2.0/mingw48_32
export PATH=$PATH:$QTDIR/bin

pythonqt_generator.exe --output-directory=pythonQtOut Pylppmon.h pythonQtgeneratorCfg.txt