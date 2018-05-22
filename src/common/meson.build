moc_headers=files([
    'QCustomPlot/qcustomplot.h',
    'SocExplorerPlot.h',
    'tcp_terminal_client.h',
    'genericBinaryFiles/elf/elfinfowdgt.h',
    'genericBinaryFiles/elf/elffile.h',
    'genericBinaryFiles/elf/elffilewidget.h',
    'qipdialogbox.h',
    'genericBinaryFiles/srec/srecfile.h',
    'genericBinaryFiles/srec/srecfilewidget.h',
    'genericBinaryFiles/BinFile/binaryfile.h',
    'genericBinaryFiles/BinFile/binaryfilewidget.h',
    'genericBinaryFiles/genericbinaryfilewidget.h',
    'genericBinaryFiles/abstractbinfile.h',
    'genericBinaryFiles/qvpushbutton.h',
    'genericBinaryFiles/filelist.h',
    'qhexedit/qhexedit.h',
    'qhexedit/qhexedit_p.h',
    'memsizewdgt.h',
    'qhexspinbox.h',
    'pythonQtOut/generated_cpp/PySocExplorer/PySocExplorer0.h'
    ])

moc_sources=[]

ui_files = files([
    'genericBinaryFiles/elf/elffilewidget.ui',
    'genericBinaryFiles/srec/srecfilewidget.ui',
    'genericBinaryFiles/BinFile/binaryfilewidget.ui',
    'genericBinaryFiles/genericbinaryfilewidget.ui'])

processed = qt5_mod.preprocess(
  moc_headers : moc_headers,   # Only headers that need moc should be put here
  moc_sources : moc_sources,   # must have #include"moc_helperFile.cpp"
  ui_files    : ui_files,
  qresources  : ['genericBinaryFiles/ressources/genericBinaryFiles.qrc']
)

if  target_machine.system() == 'windows'
   lppserial_sources = 'lppserial/src/RS232_win.c'
else
   lppserial_sources = 'lppserial/src/RS232_unix.c'
endif

sources = files([
    lppserial_sources,
    'qsvgicon.cpp',
    'genericBinaryFiles/elf/elfparser.cpp',
    'genericBinaryFiles/qtablewidgetintitem.cpp',
    'genericBinaryFiles/genericbinaryfilewidget.cpp',
    'qhexedit/xbytearray.cpp',
    'qhexedit/commands.cpp',
    'memsizewdgt.cpp',
    'qhexspinbox.cpp',
    'qhexedit/qhexedit_p.cpp',
    'qhexedit/qhexedit.cpp',
    'QCustomPlot/qcustomplot.cpp',
    'tcp_terminal_client.cpp',
    'genericBinaryFiles/elf/elfinfowdgt.cpp',
    'genericBinaryFiles/elf/elffile.cpp',
    'qipdialogbox.cpp',
    'SocExplorerPlot.cpp',
    'genericBinaryFiles/elf/elffilewidget.cpp',
    'genericBinaryFiles/srec/srecfile.cpp',
    'genericBinaryFiles/srec/srecfilewidget.cpp',
    'genericBinaryFiles/abstractbinfile.cpp',
    'genericBinaryFiles/BinFile/binaryfile.cpp',
    'genericBinaryFiles/BinFile/binaryfilewidget.cpp',
    'genericBinaryFiles/qvpushbutton.cpp',
    'genericBinaryFiles/filelist.cpp',
    'pythonQtOut/generated_cpp/PySocExplorer/PySocExplorer0.cpp',
    'pythonQtOut/generated_cpp/PySocExplorer/PySocExplorer_init.cpp'
])

inc = ['QCustomPlot','genericBinaryFiles','genericBinaryFiles/srec','genericBinaryFiles/BinFile', 'genericBinaryFiles/elf','qhexedit']

libelf = dependency('libelf', fallback:['libelf','libelf_dep'])

lib_socexplorercommon = shared_library('socexplorercommon',
	sources, processed,
	include_directories: include_directories(inc),
	dependencies: [qt5widgets, qt5printsupport, qt5network, qt5svg,libelf, pythonqt],
	install: true
	)

socexplorercommon = declare_dependency(link_with:lib_socexplorercommon,
	include_directories: include_directories(inc),
	dependencies: [qt5widgets, qt5printsupport, qt5network, qt5svg,libelf, pythonqt])

pkg.generate(libraries : lib_socexplorercommon,
             subdirs : inc,
             version : '1.0',
             name : 'libsocexplorercommon',
             filebase : 'socexplorercommon',
             description : 'SocExplorer common.')
