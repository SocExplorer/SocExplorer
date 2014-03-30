SocExplorer
-----------

SocExplorer is an open source generic System On Chip testing software/framework. 
We write this software for the development and the validation of our instrument, 
the Low Frequency Receiver(LFR) for the Solar Orbiter mission. This instrument is 
based on an actel FPGA hosting a LEON3FT processor and some peripherals. To 
make it more collaborative, we use a plugin based system, the main executable is 
SocExplorer then all the functionality are provided by plugins. Like this 
everybody can provide his set of plugins to handle a new SOC or just a new 
peripheral. SocExplorer uses PythonQt to allow user to automate some tasks such 
as loading some plugins, configuring them and talking with his device. 

Licensing
---------

SocExplorer is provided under the terms of the GNU General Public License as published by the 
Free Software Foundation; either version 2 of the License, or (at your option) any 
later version.

Wiki
----

More details  [here](https://hephaistos.lpp.polytechnique.fr/redmine/projects/socexplorer/wiki)

How to build
------------

To build it on linux you can look here https://hephaistos.lpp.polytechnique.fr/redmine/projects/socexplorer/wiki/Linux_setup

If you can't access to it, first you will need a working qt5 kit with all the development packages.
 Step 1:
  You need to get a modified version of PythonQt, you can clone it from our repository
```Bash
  hg clone https://hephaistos.lpp.polytechnique.fr/rhodecode/HG_REPOSITORIES/LPP/INSTRUMENTATION/USERS/JEANDET/PythonQt PythonQt
  cd PythonQt
  qmake-qt5 
  make 
  sudo make install
```
 Step 2:
  Get and install SocExplorer
```Bash
  hg clone https://hephaistos.lpp.polytechnique.fr/rhodecode/HG_REPOSITORIES/LPP/INSTRUMENTATION/SocExplorer SocExplorer
  cd SocExplorer
  qmake-qt5
  make 
  sudo make install
  mkdir -p ~/.SocExplorer/config
  cp ressources/Grlib.xml ~/.SocExplorer/config/Grlib.xml
```
 Step 3:
  Get and install SocExplorer main plugins
```Bash
  hg clone https://hephaistos.lpp.polytechnique.fr/rhodecode/HG_REPOSITORIES/LPP/INSTRUMENTATION/SocExplorerPlugins SocExplorerPlugins
  qmake-qt5
  make 
  make install # /!\ As regular user!
```

Bug repports
------------

To repport any bug you can either send a [mail](mailto:alexis.jeandet@member.fsf.org) or repport an issue [here](https://hephaistos.lpp.polytechnique.fr/redmine/projects/socexplorer/issues)











