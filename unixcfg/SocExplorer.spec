%global upstream_name socexplorer-0.6-3

Name:           socexplorer
Version:        0.6
Release:        3%{?dist}
Summary:        SocExplorer is an open source generic System On Chip testing software/framework.
Group:          Development/Tools
License:        GPLv2+
URL:            https://hephaistos.lpp.polytechnique.fr/redmine/projects/socexplorer
Source0:        https://hephaistos.lpp.polytechnique.fr/redmine/attachments/download/376/%{upstream_name}.zip

BuildRequires:  python2-devel
BuildRequires:  qt5-qtbase-devel
BuildRequires:  qt5-qtwebkit-devel
BuildRequires:  qt5-qttools-static
BuildRequires:  qt5-qttools-devel
BuildRequires:  qt5-qtsvg-devel
BuildRequires:  qt5-qtxmlpatterns-devel
BuildRequires:  qt5-qtmultimedia-devel
BuildRequires:  elfutils-libelf-devel
BuildRequires:  qt5-pythonqt-devel
BuildRequires:  mercurial
BuildRequires:  appdata-tools
BuildRequires:  desktop-file-utils

Requires(post): python2
Requires(post): qt5-qtbase
Requires(post): qt5-qtwebkit
Requires(post): qt5-qtsvg
Requires(post): qt5-qtxmlpatterns
Requires(post): elfutils-libelf
Requires(post): qt5-pythonqt

Provides:  socexplorer = 0.6-3
Obsoletes: socexplorer < 0.6-2

%description
SocExplorer is an open source generic System On Chip testing software/framework. We write this software for the development and the validation of our instrument, the Low Frequency Receiver(LFR) for the Solar Orbiter mission. This instrument is based on an actel FPGA hosting a LEON3FT processor and some peripherals. To make it more collaborative, we use a plugin based system, the main executable is SocExplorer then all the functionality are provided by plugins. Like this everybody can provide his set of plugins to handle a new SOC or just a new peripheral. SocExplorer uses PythonQt to allow user to automate some tasks such as loading some plugins, configuring them and talking with his device.

%package devel
Summary:    SocExplorer is an open source generic System On Chip testing software/framework.
Group:      Development/Tools
Requires:   %{name}%{?_isa} = %{version}-%{release}
Requires:  python2-devel
Requires:  qt5-qtbase-devel
Requires:  qt5-qtwebkit-devel
Requires:  qt5-qttools-static
Requires:  qt5-qttools-devel
Requires:  qt5-qtsvg-devel
Requires:  qt5-qtxmlpatterns-devel
Requires:  qt5-qtmultimedia-devel
Requires:  elfutils-libelf-devel
Requires:  qt5-pythonqt-devel
Requires:  mercurial
Requires:  appdata-tools
Requires:  desktop-file-utils

%description devel
Header files and development libraries for SocExplorer package. SocExplorer is an open source generic System On Chip testing software/framework.

%prep
%setup -q -n %{upstream_name}



%build
%{_qt5_qmake}

make %{?_smp_mflags}

%install
make install INSTALL_ROOT=%{buildroot}
appdata-validate --nonet %{buildroot}/%{_datadir}/appdata/socexplorer.appdata.xml
desktop-file-validate $RPM_BUILD_ROOT%{_datadir}/applications/socexplorer.desktop

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
   /etc/SocExplorer/python/PygmentsHighlighter.py
   /etc/SocExplorer/python/PygmentsHighlighter.pyc
   /etc/SocExplorer/python/PygmentsHighlighter.pyo
   /etc/SocExplorer/python/PythonCompleter.py
   /etc/SocExplorer/python/PythonCompleter.pyc
   /etc/SocExplorer/python/PythonCompleter.pyo
   /etc/SocExplorer/python/module_completion.py
   /etc/SocExplorer/python/module_completion.pyc
   /etc/SocExplorer/python/module_completion.pyo
   /etc/SocExplorer/python/pygments/__init__.py
   /etc/SocExplorer/python/pygments/__init__.pyc
   /etc/SocExplorer/python/pygments/__init__.pyo
   /etc/SocExplorer/python/pygments/cmdline.py
   /etc/SocExplorer/python/pygments/cmdline.pyc
   /etc/SocExplorer/python/pygments/cmdline.pyo
   /etc/SocExplorer/python/pygments/console.py
   /etc/SocExplorer/python/pygments/console.pyc
   /etc/SocExplorer/python/pygments/console.pyo
   /etc/SocExplorer/python/pygments/filter.py
   /etc/SocExplorer/python/pygments/filter.pyc
   /etc/SocExplorer/python/pygments/filter.pyo
   /etc/SocExplorer/python/pygments/filters/__init__.py
   /etc/SocExplorer/python/pygments/filters/__init__.pyc
   /etc/SocExplorer/python/pygments/filters/__init__.pyo
   /etc/SocExplorer/python/pygments/formatter.py
   /etc/SocExplorer/python/pygments/formatter.pyc
   /etc/SocExplorer/python/pygments/formatter.pyo
   /etc/SocExplorer/python/pygments/formatters/__init__.py
   /etc/SocExplorer/python/pygments/formatters/__init__.pyc
   /etc/SocExplorer/python/pygments/formatters/__init__.pyo
   /etc/SocExplorer/python/pygments/formatters/_mapping.py
   /etc/SocExplorer/python/pygments/formatters/_mapping.pyc
   /etc/SocExplorer/python/pygments/formatters/_mapping.pyo
   /etc/SocExplorer/python/pygments/formatters/bbcode.py
   /etc/SocExplorer/python/pygments/formatters/bbcode.pyc
   /etc/SocExplorer/python/pygments/formatters/bbcode.pyo
   /etc/SocExplorer/python/pygments/formatters/html.py
   /etc/SocExplorer/python/pygments/formatters/html.pyc
   /etc/SocExplorer/python/pygments/formatters/html.pyo
   /etc/SocExplorer/python/pygments/formatters/img.py
   /etc/SocExplorer/python/pygments/formatters/img.pyc
   /etc/SocExplorer/python/pygments/formatters/img.pyo
   /etc/SocExplorer/python/pygments/formatters/latex.py
   /etc/SocExplorer/python/pygments/formatters/latex.pyc
   /etc/SocExplorer/python/pygments/formatters/latex.pyo
   /etc/SocExplorer/python/pygments/formatters/other.py
   /etc/SocExplorer/python/pygments/formatters/other.pyc
   /etc/SocExplorer/python/pygments/formatters/other.pyo
   /etc/SocExplorer/python/pygments/formatters/rtf.py
   /etc/SocExplorer/python/pygments/formatters/rtf.pyc
   /etc/SocExplorer/python/pygments/formatters/rtf.pyo
   /etc/SocExplorer/python/pygments/formatters/svg.py
   /etc/SocExplorer/python/pygments/formatters/svg.pyc
   /etc/SocExplorer/python/pygments/formatters/svg.pyo
   /etc/SocExplorer/python/pygments/formatters/terminal.py
   /etc/SocExplorer/python/pygments/formatters/terminal.pyc
   /etc/SocExplorer/python/pygments/formatters/terminal.pyo
   /etc/SocExplorer/python/pygments/formatters/terminal256.py
   /etc/SocExplorer/python/pygments/formatters/terminal256.pyc
   /etc/SocExplorer/python/pygments/formatters/terminal256.pyo
   /etc/SocExplorer/python/pygments/lexer.py
   /etc/SocExplorer/python/pygments/lexer.pyc
   /etc/SocExplorer/python/pygments/lexer.pyo
   /etc/SocExplorer/python/pygments/lexers/__init__.py
   /etc/SocExplorer/python/pygments/lexers/__init__.pyc
   /etc/SocExplorer/python/pygments/lexers/__init__.pyo
   /etc/SocExplorer/python/pygments/lexers/_asybuiltins.py
   /etc/SocExplorer/python/pygments/lexers/_asybuiltins.pyc
   /etc/SocExplorer/python/pygments/lexers/_asybuiltins.pyo
   /etc/SocExplorer/python/pygments/lexers/_clbuiltins.py
   /etc/SocExplorer/python/pygments/lexers/_clbuiltins.pyc
   /etc/SocExplorer/python/pygments/lexers/_clbuiltins.pyo
   /etc/SocExplorer/python/pygments/lexers/_luabuiltins.py
   /etc/SocExplorer/python/pygments/lexers/_luabuiltins.pyc
   /etc/SocExplorer/python/pygments/lexers/_luabuiltins.pyo
   /etc/SocExplorer/python/pygments/lexers/_mapping.py
   /etc/SocExplorer/python/pygments/lexers/_mapping.pyc
   /etc/SocExplorer/python/pygments/lexers/_mapping.pyo
   /etc/SocExplorer/python/pygments/lexers/_phpbuiltins.py
   /etc/SocExplorer/python/pygments/lexers/_phpbuiltins.pyc
   /etc/SocExplorer/python/pygments/lexers/_phpbuiltins.pyo
   /etc/SocExplorer/python/pygments/lexers/_postgres_builtins.py
   /etc/SocExplorer/python/pygments/lexers/_postgres_builtins.pyc
   /etc/SocExplorer/python/pygments/lexers/_postgres_builtins.pyo
   /etc/SocExplorer/python/pygments/lexers/_scilab_builtins.py
   /etc/SocExplorer/python/pygments/lexers/_scilab_builtins.pyc
   /etc/SocExplorer/python/pygments/lexers/_scilab_builtins.pyo
   /etc/SocExplorer/python/pygments/lexers/_vimbuiltins.py
   /etc/SocExplorer/python/pygments/lexers/_vimbuiltins.pyc
   /etc/SocExplorer/python/pygments/lexers/_vimbuiltins.pyo
   /etc/SocExplorer/python/pygments/lexers/agile.py
   /etc/SocExplorer/python/pygments/lexers/agile.pyc
   /etc/SocExplorer/python/pygments/lexers/agile.pyo
   /etc/SocExplorer/python/pygments/lexers/asm.py
   /etc/SocExplorer/python/pygments/lexers/asm.pyc
   /etc/SocExplorer/python/pygments/lexers/asm.pyo
   /etc/SocExplorer/python/pygments/lexers/compiled.py
   /etc/SocExplorer/python/pygments/lexers/compiled.pyc
   /etc/SocExplorer/python/pygments/lexers/compiled.pyo
   /etc/SocExplorer/python/pygments/lexers/dotnet.py
   /etc/SocExplorer/python/pygments/lexers/dotnet.pyc
   /etc/SocExplorer/python/pygments/lexers/dotnet.pyo
   /etc/SocExplorer/python/pygments/lexers/functional.py
   /etc/SocExplorer/python/pygments/lexers/functional.pyc
   /etc/SocExplorer/python/pygments/lexers/functional.pyo
   /etc/SocExplorer/python/pygments/lexers/hdl.py
   /etc/SocExplorer/python/pygments/lexers/hdl.pyc
   /etc/SocExplorer/python/pygments/lexers/hdl.pyo
   /etc/SocExplorer/python/pygments/lexers/jvm.py
   /etc/SocExplorer/python/pygments/lexers/jvm.pyc
   /etc/SocExplorer/python/pygments/lexers/jvm.pyo
   /etc/SocExplorer/python/pygments/lexers/math.py
   /etc/SocExplorer/python/pygments/lexers/math.pyc
   /etc/SocExplorer/python/pygments/lexers/math.pyo
   /etc/SocExplorer/python/pygments/lexers/other.py
   /etc/SocExplorer/python/pygments/lexers/other.pyc
   /etc/SocExplorer/python/pygments/lexers/other.pyo
   /etc/SocExplorer/python/pygments/lexers/parsers.py
   /etc/SocExplorer/python/pygments/lexers/parsers.pyc
   /etc/SocExplorer/python/pygments/lexers/parsers.pyo
   /etc/SocExplorer/python/pygments/lexers/shell.py
   /etc/SocExplorer/python/pygments/lexers/shell.pyc
   /etc/SocExplorer/python/pygments/lexers/shell.pyo
   /etc/SocExplorer/python/pygments/lexers/special.py
   /etc/SocExplorer/python/pygments/lexers/special.pyc
   /etc/SocExplorer/python/pygments/lexers/special.pyo
   /etc/SocExplorer/python/pygments/lexers/sql.py
   /etc/SocExplorer/python/pygments/lexers/sql.pyc
   /etc/SocExplorer/python/pygments/lexers/sql.pyo
   /etc/SocExplorer/python/pygments/lexers/templates.py
   /etc/SocExplorer/python/pygments/lexers/templates.pyc
   /etc/SocExplorer/python/pygments/lexers/templates.pyo
   /etc/SocExplorer/python/pygments/lexers/text.py
   /etc/SocExplorer/python/pygments/lexers/text.pyc
   /etc/SocExplorer/python/pygments/lexers/text.pyo
   /etc/SocExplorer/python/pygments/lexers/web.py
   /etc/SocExplorer/python/pygments/lexers/web.pyc
   /etc/SocExplorer/python/pygments/lexers/web.pyo
   /etc/SocExplorer/python/pygments/plugin.py
   /etc/SocExplorer/python/pygments/plugin.pyc
   /etc/SocExplorer/python/pygments/plugin.pyo
   /etc/SocExplorer/python/pygments/scanner.py
   /etc/SocExplorer/python/pygments/scanner.pyc
   /etc/SocExplorer/python/pygments/scanner.pyo
   /etc/SocExplorer/python/pygments/style.py
   /etc/SocExplorer/python/pygments/style.pyc
   /etc/SocExplorer/python/pygments/style.pyo
   /etc/SocExplorer/python/pygments/styles/__init__.py
   /etc/SocExplorer/python/pygments/styles/__init__.pyc
   /etc/SocExplorer/python/pygments/styles/__init__.pyo
   /etc/SocExplorer/python/pygments/styles/autumn.py
   /etc/SocExplorer/python/pygments/styles/autumn.pyc
   /etc/SocExplorer/python/pygments/styles/autumn.pyo
   /etc/SocExplorer/python/pygments/styles/borland.py
   /etc/SocExplorer/python/pygments/styles/borland.pyc
   /etc/SocExplorer/python/pygments/styles/borland.pyo
   /etc/SocExplorer/python/pygments/styles/bw.py
   /etc/SocExplorer/python/pygments/styles/bw.pyc
   /etc/SocExplorer/python/pygments/styles/bw.pyo
   /etc/SocExplorer/python/pygments/styles/colorful.py
   /etc/SocExplorer/python/pygments/styles/colorful.pyc
   /etc/SocExplorer/python/pygments/styles/colorful.pyo
   /etc/SocExplorer/python/pygments/styles/default.py
   /etc/SocExplorer/python/pygments/styles/default.pyc
   /etc/SocExplorer/python/pygments/styles/default.pyo
   /etc/SocExplorer/python/pygments/styles/emacs.py
   /etc/SocExplorer/python/pygments/styles/emacs.pyc
   /etc/SocExplorer/python/pygments/styles/emacs.pyo
   /etc/SocExplorer/python/pygments/styles/friendly.py
   /etc/SocExplorer/python/pygments/styles/friendly.pyc
   /etc/SocExplorer/python/pygments/styles/friendly.pyo
   /etc/SocExplorer/python/pygments/styles/fruity.py
   /etc/SocExplorer/python/pygments/styles/fruity.pyc
   /etc/SocExplorer/python/pygments/styles/fruity.pyo
   /etc/SocExplorer/python/pygments/styles/manni.py
   /etc/SocExplorer/python/pygments/styles/manni.pyc
   /etc/SocExplorer/python/pygments/styles/manni.pyo
   /etc/SocExplorer/python/pygments/styles/monokai.py
   /etc/SocExplorer/python/pygments/styles/monokai.pyc
   /etc/SocExplorer/python/pygments/styles/monokai.pyo
   /etc/SocExplorer/python/pygments/styles/murphy.py
   /etc/SocExplorer/python/pygments/styles/murphy.pyc
   /etc/SocExplorer/python/pygments/styles/murphy.pyo
   /etc/SocExplorer/python/pygments/styles/native.py
   /etc/SocExplorer/python/pygments/styles/native.pyc
   /etc/SocExplorer/python/pygments/styles/native.pyo
   /etc/SocExplorer/python/pygments/styles/pastie.py
   /etc/SocExplorer/python/pygments/styles/pastie.pyc
   /etc/SocExplorer/python/pygments/styles/pastie.pyo
   /etc/SocExplorer/python/pygments/styles/perldoc.py
   /etc/SocExplorer/python/pygments/styles/perldoc.pyc
   /etc/SocExplorer/python/pygments/styles/perldoc.pyo
   /etc/SocExplorer/python/pygments/styles/rrt.py
   /etc/SocExplorer/python/pygments/styles/rrt.pyc
   /etc/SocExplorer/python/pygments/styles/rrt.pyo
   /etc/SocExplorer/python/pygments/styles/tango.py
   /etc/SocExplorer/python/pygments/styles/tango.pyc
   /etc/SocExplorer/python/pygments/styles/tango.pyo
   /etc/SocExplorer/python/pygments/styles/trac.py
   /etc/SocExplorer/python/pygments/styles/trac.pyc
   /etc/SocExplorer/python/pygments/styles/trac.pyo
   /etc/SocExplorer/python/pygments/styles/vim.py
   /etc/SocExplorer/python/pygments/styles/vim.pyc
   /etc/SocExplorer/python/pygments/styles/vim.pyo
   /etc/SocExplorer/python/pygments/styles/vs.py
   /etc/SocExplorer/python/pygments/styles/vs.pyc
   /etc/SocExplorer/python/pygments/styles/vs.pyo
   /etc/SocExplorer/python/pygments/token.py
   /etc/SocExplorer/python/pygments/token.pyc
   /etc/SocExplorer/python/pygments/token.pyo
   /etc/SocExplorer/python/pygments/unistring.py
   /etc/SocExplorer/python/pygments/unistring.pyc
   /etc/SocExplorer/python/pygments/unistring.pyo
   /etc/SocExplorer/python/pygments/util.py
   /etc/SocExplorer/python/pygments/util.pyc
   /etc/SocExplorer/python/pygments/util.pyo
   /etc/SocExplorer/plugin.conf.d/plugins.conf
   %{_bindir}/SocExplorer_TCP_Terminal
   %{_bindir}/socexplorer
   %{_datadir}/SocExplorer/icon.png
   %{_datadir}/SocExplorer/Grlib.xml
   %{_datadir}/SocExplorer/LPP.xml
   %{_datadir}/SocExplorer/IAP.xml
   %{_datadir}/applications/socexplorer.desktop
   %{_datadir}/appdata/socexplorer.appdata.xml
   %{_qt5_libdir}/libsocexplorercommon.so*
   %{_qt5_libdir}/libsocexplorerengine.so*


%files devel
   %{_qt5_headerdir}/SocExplorer/
   %{_qt5_archdatadir}/mkspecs/features/socexplorerplugin.prf
   /usr/share/qtcreator/templates/wizards/SocExplorerPlugin/plugin.cpp
   /usr/share/qtcreator/templates/wizards/SocExplorerPlugin/plugin.h
   /usr/share/qtcreator/templates/wizards/SocExplorerPlugin/project.pro
   /usr/share/qtcreator/templates/wizards/SocExplorerPlugin/wizard.xml


%changelog
* Mon Oct 26  2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.6
- Updated LPP IPs registers definition list(LPP.xml).

* Fri Apr 17  2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.6
- Updated abstractbinary file lib to expose new feature.

* Fri Apr 3  2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.6
- Fix some remaining mistakes.

* Thu Apr 2  2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.6
-Uses r80 as source.
-Removed GenericPySysdriver interface, now socexplorer plugins can be subclassed in python.

* Thu Mar 26  2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.5
-Uses r77 as source.

* Mon Mar  9 2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.4
- Uses r75 as source.

* Tue Feb 10 2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.4
- Uses r74 as source.

* Fri Feb 6 2015 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.4
- Reseted patches uses r73 as source.

* Tue Dec 30 2014 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.4
- Reseted patches uses r72 as source.

* Sun Jun 29 2014 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.4
- Reseted patches uses r69 as source.

* Sat Jun 28 2014 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.4
- Applied patch r65 to install also plugin as RPM
- Applied patch r66 to install xml soc descriptions in /usr/share/SocExplorer
- Applied patch r67 to add appdata for gnome-software visibility

* Tue Jun 24 2014 Alexis Jeandet <alexis.jeandet@member.fsf.org> - 0.4
- Initial Fedora packaging
