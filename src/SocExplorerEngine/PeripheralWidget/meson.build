sources = files([
    'src/peripheralwidget.cpp',
    'src/registerwidget.cpp',
    'src/socregsviewer.cpp',
    'src/socregsviewernew.cpp',
    'src/collapsableperipheralwidget.cpp'
    ])

moc_headers=files([
    'src/peripheralwidget.h',
    'src/registerwidget.h',
    'src/socregsviewer.h',
    'src/socregsviewernew.h',
    'src/collapsableperipheralwidget.h'
    ])


ui_files = files([
  'src/socregsviewernew.ui',
  'src/collapsableperipheralwidget.ui'
  ])


processed = qt5_mod.preprocess(
  moc_headers : moc_headers,   # Only headers that need moc should be put here
  ui_files    : ui_files,
  qresources  : ['ressources/peripheralwidget.qrc']
)

inc = ['src']

lib_peripheralwidget = shared_library('peripheralwidget',
	sources, processed,
	include_directories: include_directories(inc),
	dependencies: [qt5widgets],
	install: true
	)

peripheralwidget = declare_dependency(link_with:lib_peripheralwidget, include_directories: include_directories(inc))

pkg.generate(libraries : lib_peripheralwidget,
             subdirs : inc,
             version : '1.0',
             name : 'libperipheralwidget',
             filebase : 'peripheralwidget',
             description : 'SocExplorer peripheral widget library.')
