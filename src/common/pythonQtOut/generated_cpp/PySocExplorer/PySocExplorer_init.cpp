#include <PythonQt.h>
#include "PySocExplorer0.h"


void PythonQt_init_PySocExplorer(PyObject* module) {
PythonQt::priv()->registerClass(&ElfFile::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_ElfFile>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_ElfFile>, module, 0);
PythonQt::self()->addParentClass("ElfFile", "abstractExecFile",PythonQtUpcastingOffset<ElfFile,abstractExecFile>());
PythonQt::priv()->registerCPPClass("MemSizeWdgt", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_MemSizeWdgt>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("QHexEdit", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_QHexEdit>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_QHexEdit>, module, 0);
PythonQt::priv()->registerCPPClass("QHexSpinBox", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_QHexSpinBox>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("SocExplorerPlot", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_SocExplorerPlot>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_SocExplorerPlot>, module, 0);
PythonQt::priv()->registerClass(&TCP_Terminal_Client::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_TCP_Terminal_Client>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("XByteArray", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_XByteArray>, NULL, module, 0);
PythonQt::priv()->registerClass(&abstractExecFile::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_abstractExecFile>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_abstractExecFile>, module, 0);
PythonQt::priv()->registerCPPClass("codeFragment", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_codeFragment>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_codeFragment>, module, 0);
PythonQt::priv()->registerCPPClass("elfFileWidget", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfFileWidget>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("elfInfoWdgt", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfInfoWdgt>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("elfparser", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfparser>, NULL, module, 0);

}
