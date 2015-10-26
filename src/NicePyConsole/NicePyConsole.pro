TARGET   = NicePyConsole
TEMPLATE = app

CONFIG += pythonqt


HEADERS +=                  \
  SimpleConsole.h           \
  NicePyConsole.h           \
  PygmentsHighlighter.h     \
  PythonCompleter.h         \
  PythonCompleterPopup.h
  
SOURCES +=                  \
  SimpleConsole.cpp         \
  NicePyConsole.cpp         \  
  main.cpp                  \
  PygmentsHighlighter.cpp   \
  PythonCompleter.cpp       \
  PythonCompleterPopup.cpp

OTHER_FILES +=              \
  PygmentsHighlighter.py    \
  PythonCompleter.py        \
  module_completion.py
