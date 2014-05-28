#include <PythonQt.h>
#include "PySocExplorer0.h"


void PythonQt_init_PySocExplorer(PyObject* module) {
PythonQt::priv()->registerClass(&ElfFile::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_ElfFile>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("MemSizeWdgt", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_MemSizeWdgt>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("QHexEdit", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_QHexEdit>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_QHexEdit>, module, 0);
PythonQt::priv()->registerCPPClass("QHexSpinBox", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_QHexSpinBox>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("SocExplorerPlot", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_SocExplorerPlot>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_SocExplorerPlot>, module, 0);
PythonQt::priv()->registerClass(&TCP_Terminal_Client::staticMetaObject, "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_TCP_Terminal_Client>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("XByteArray", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_XByteArray>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("elfFileWidget", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfFileWidget>, NULL, module, 0);
PythonQt::priv()->registerCPPClass("elfparser", "", "PySocExplorer", PythonQtCreateObject<PythonQtWrapper_elfparser>, NULL, module, 0);

}
