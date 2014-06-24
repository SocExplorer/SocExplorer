#include <PythonQt.h>
#include "PySocExplorerEngine0.h"


void PythonQt_init_PySocExplorerEngine(PyObject* module) {
PythonQt::priv()->registerClass(&socexplorerplugin::staticMetaObject, "PySocExplorerEngine", PythonQtCreateObject<PythonQtWrapper_socexplorerplugin>, PythonQtSetInstanceWrapperOnShell<PythonQtShell_socexplorerplugin>, module, 0);

}
