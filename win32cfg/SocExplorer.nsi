; example2.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install example2.nsi into a directory that the user selects,

;--------------------------------

; The name of the installer
Name "SocExplorer_win32_setup"

Icon "socexplorer.ico"

; The file to write
OutFile "SocExplorer_win32_setup.exe"

; The default installation directory
InstallDir $PROGRAMFILES\LPP\SocExplorer

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\SocExplorer" "Install_Dir"

LicenseText "SocExplorer License Agreement"
LicenseData "COPYING"

; Request application privileges for Windows Vista
RequestExecutionLevel admin


;--------------------------------

; Pages

Page license
Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; These are the programs that are needed by LPPMON.
Section -Prerequisites
  MessageBox MB_YESNO "Install Python 2.7.3?" /SD IDYES IDNO python27
    setoutpath "$INSTDIR\Prerequisites"
    File "python-2.7.6.msi"
    ExecWait '"msiexec" /i "$INSTDIR\Prerequisites\python-2.7.3.msi"'
    Delete "$INSTDIR\Prerequisites\python-2.7.3.msi"
  python27:
  MessageBox MB_YESNO "Install SciPy 0.11.0?" /SD IDYES IDNO SciPy
    setoutpath "$INSTDIR\Prerequisites"
    File "scipy-0.11.0-win32-superpack-python2.7.exe"
    ExecWait "$INSTDIR\Prerequisites\scipy-0.11.0-win32-superpack-python2.7.exe"
    Delete "$INSTDIR\Prerequisites\scipy-0.11.0-win32-superpack-python2.7.exe"
  SciPy:
  MessageBox MB_YESNO "Install numpy 1.6.2?" /SD IDYES IDNO numpy
    setoutpath "$INSTDIR\Prerequisites"
    File "numpy-1.6.2-win32-superpack-python2.7.exe"
    ExecWait "$INSTDIR\Prerequisites\numpy-1.6.2-win32-superpack-python2.7.exe"
    Delete "$INSTDIR\Prerequisites\numpy-1.6.2-win32-superpack-python2.7.exe"
  numpy:
  MessageBox MB_YESNO "Install matplotlib 1.1.0?" /SD IDYES IDNO matplotlib
    setoutpath "$INSTDIR\Prerequisites"
    File "matplotlib-1.1.0.win32-py2.7.exe"
    ExecWait "$INSTDIR\Prerequisites\matplotlib-1.1.0.win32-py2.7.exe"
    Delete "$INSTDIR\Prerequisites\matplotlib-1.1.0.win32-py2.7.exe"
  matplotlib:
SectionEnd

; The stuff to install
Section "SocExplorer (required)"


  ; Set output path to the installation directory.
  SetOutPath $INSTDIR

  ; Put file there
  File "SocExplorer.exe"
  File "*.dll"
  File "socexplorer.rc"
  File /r "python"
  File /r "config"
  File /r "platforms"
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\LPPMON "Install_Dir" "$INSTDIR"

  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SocExplorer" "DisplayName" "NSIS SocExplorer"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SocExplorer" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SocExplorer" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SocExplorer" "NoRepair" 1
  WriteUninstaller "uninstall.exe"

SectionEnd
Section "plugins"
  SetOutPath $INSTDIR\plugins
  File "plugins\*"
SectionEnd


; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\SocExplorer"
  CreateShortCut "$SMPROGRAMS\SocExplorer\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\SocExplorer\SocExplorer.lnk" "$INSTDIR\SocExplorer.exe" "" "$INSTDIR\SocExplorer.exe" 0


SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"

  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SocExplorer"
  DeleteRegKey HKLM SOFTWARE\SocExplorer

  ; Remove files and uninstaller
  Delete $INSTDIR\*
  Delete $INSTDIR\plugins\*
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\SocExplorer\*.*"

  ; Remove directories used
  RMDir "$INSTDIR\SocExplorer\plugins"
  RMDir "$SMPROGRAMS\SocExplorer"
  RMDir "$INSTDIR"

SectionEnd
