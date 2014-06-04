
HEADERS +=                  \
  $${PWD}/SimpleConsole.h           \
  $${PWD}/NicePyConsole.h           \
  $${PWD}/PygmentsHighlighter.h     \
  $${PWD}/PythonCompleter.h         \
  $${PWD}/PythonCompleterPopup.h
  
SOURCES +=                  \
  $${PWD}/SimpleConsole.cpp         \
  $${PWD}/NicePyConsole.cpp         \
  $${PWD}/PygmentsHighlighter.cpp   \
  $${PWD}/PythonCompleter.cpp       \
  $${PWD}/PythonCompleterPopup.cpp



OTHER_FILES +=              \
  $${PWD}/PygmentsHighlighter.py    \
  $${PWD}/PythonCompleter.py        \
  $${PWD}/module_completion.py \
  $${PWD}/pygments/formatters/latex.py \
  $${PWD}/pygments/formatters/terminal256.py \
  $${PWD}/pygments/formatters/_mapping.py \
  $${PWD}/pygments/formatters/svg.py \
  $${PWD}/pygments/formatters/html.py \
  $${PWD}/pygments/formatters/terminal.py \
  $${PWD}/pygments/formatters/bbcode.py \
  $${PWD}/pygments/formatters/rtf.py \
  $${PWD}/pygments/formatters/__init__.py \
  $${PWD}/pygments/formatters/other.py \
  $${PWD}/pygments/formatters/img.py \
  $${PWD}/pygments/console.py \
  $${PWD}/pygments/lexer.py \
  $${PWD}/pygments/style.py \
  $${PWD}/pygments/styles/colorful.py \
  $${PWD}/pygments/styles/autumn.py \
  $${PWD}/pygments/styles/monokai.py \
  $${PWD}/pygments/styles/vim.py \
  $${PWD}/pygments/styles/manni.py \
  $${PWD}/pygments/styles/fruity.py \
  $${PWD}/pygments/styles/pastie.py \
  $${PWD}/pygments/styles/vs.py \
  $${PWD}/pygments/styles/murphy.py \
  $${PWD}/pygments/styles/rrt.py \
  $${PWD}/pygments/styles/tango.py \
  $${PWD}/pygments/styles/trac.py \
  $${PWD}/pygments/styles/default.py \
  $${PWD}/pygments/styles/__init__.py \
  $${PWD}/pygments/styles/emacs.py \
  $${PWD}/pygments/styles/bw.py \
  $${PWD}/pygments/styles/friendly.py \
  $${PWD}/pygments/styles/borland.py \
  $${PWD}/pygments/styles/perldoc.py \
  $${PWD}/pygments/styles/native.py \
  $${PWD}/pygments/filters/__init__.py \
  $${PWD}/pygments/filter.py \
  $${PWD}/pygments/token.py \
  $${PWD}/pygments/unistring.py \
  $${PWD}/pygments/scanner.py \
  $${PWD}/pygments/formatter.py \
  $${PWD}/pygments/util.py \
  $${PWD}/pygments/lexers/_mapping.py \
  $${PWD}/pygments/lexers/parsers.py \
  $${PWD}/pygments/lexers/web.py \
  $${PWD}/pygments/lexers/compiled.py \
  $${PWD}/pygments/lexers/special.py \
  $${PWD}/pygments/lexers/dotnet.py \
  $${PWD}/pygments/lexers/_luabuiltins.py \
  $${PWD}/pygments/lexers/sql.py \
  $${PWD}/pygments/lexers/templates.py \
  $${PWD}/pygments/lexers/text.py \
  $${PWD}/pygments/lexers/math.py \
  $${PWD}/pygments/lexers/jvm.py \
  $${PWD}/pygments/lexers/asm.py \
  $${PWD}/pygments/lexers/__init__.py \
  $${PWD}/pygments/lexers/_asybuiltins.py \
  $${PWD}/pygments/lexers/other.py \
  $${PWD}/pygments/lexers/shell.py \
  $${PWD}/pygments/lexers/agile.py \
  $${PWD}/pygments/lexers/_phpbuiltins.py \
  $${PWD}/pygments/lexers/_scilab_builtins.py \
  $${PWD}/pygments/lexers/_vimbuiltins.py \
  $${PWD}/pygments/lexers/_clbuiltins.py \
  $${PWD}/pygments/lexers/functional.py \
  $${PWD}/pygments/lexers/_postgres_builtins.py \
  $${PWD}/pygments/lexers/hdl.py \
  $${PWD}/pygments/__init__.py \
  $${PWD}/pygments/cmdline.py \
  $${PWD}/pygments/plugin.py

NicePyConsoleFiles.files = $${PWD}/PygmentsHighlighter.py    \
                           $${PWD}/PythonCompleter.py        \
                           $${PWD}/module_completion.py

NicePyConsolePygmentsFiles.files = $${PWD}/pygments



unix{

    NicePyConsoleFiles.path = /etc/SocExplorer/python
    NicePyConsolePygmentsFiles.path = /etc/SocExplorer/python
    INSTALLS += NicePyConsoleFiles NicePyConsolePygmentsFiles
    QMAKE_POST_LINK = $${QMAKE_MKDIR} $${DESTDIR}/python && $${QMAKE_COPY} $${NicePyConsoleFiles.files} $${DESTDIR}/python && $${QMAKE_COPY} -R $${NicePyConsolePygmentsFiles.files} $${DESTDIR}/python
}

win32{

    EXTRA_PYTHONFILES_WIN = $${NicePyConsoleFiles.files}
    EXTRA_PYTHONFILES_WIN ~= s,/,\\,g
    DESTDIR_WIN = $${DESTDIR}
    DESTDIR_WIN ~= s,/,\\,g
    for(FILE,EXTRA_BINFILES_WIN){
                QMAKE_POST_LINK +=$$quote(cmd /c copy /y $${FILE} $${DESTDIR_WIN}$$escape_expand(\n\t))
    }
}


