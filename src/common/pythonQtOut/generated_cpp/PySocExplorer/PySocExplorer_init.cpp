#include <PythonQt.h>
#include "PySocExplorer0.h"


void PythonQt_init_PySocExplorer(PyObject* module) {
PythonQt::priv()->registerClass(&ElfFile::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_ElfFile>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_ElfFile>, module, 0);
PythonQt::self()->addParentClass("ElfFile", "abstractExecFile",PythonQtUpcastingOffset<ElfFile,abstractExecFile>());
PythonQt::priv()->registerClass(&MemSizeWdgt::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_MemSizeWdgt>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_MemSizeWdgt>, module, 0);
PythonQt::priv()->registerClass(&QHexEdit::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_QHexEdit>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_QHexEdit>, module, 0);
PythonQt::priv()->registerClass(&QHexSpinBox::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_QHexSpinBox>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_QHexSpinBox>, module, 0);
PythonQt::priv()->registerClass(&SocExplorerPlot::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_SocExplorerPlot>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_SocExplorerPlot>, module, 0);
PythonQt::priv()->registerClass(&TCP_Terminal_Client::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_TCP_Terminal_Client>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_TCP_Terminal_Client>, module, 0);
PythonQt::priv()->registerCPPClass("XByteArray", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_XByteArray>, NULL, module, 0);
PythonQt::priv()->registerClass(&abstractExecFile::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_abstractExecFile>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_abstractExecFile>, module, 0);
PythonQt::priv()->registerCPPClass("codeFragment", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_codeFragment>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_codeFragment>, module, 0);
PythonQt::priv()->registerClass(&elfFileWidget::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfFileWidget>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_elfFileWidget>, module, 0);
PythonQt::priv()->registerClass(&elfInfoWdgt::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfInfoWdgt>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_elfInfoWdgt>, module, 0);
PythonQt::priv()->registerCPPClass("elfparser", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfparser>, NULL, module, 0);

}
