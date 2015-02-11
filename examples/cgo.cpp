#include <QString>
#include "cgo.h"

Cgo::Cgo()
{
    cgo_connect = 0;
    cgo_checkconn = 0;
    cgo_disconn = 0;
    cgo_command = 0;
    cgo_shortcuts = 0;
    cgo_goline = 0;
    cgo_reader = 0;
}

int Cgo::setCgo(void* _a, void* _b)
{
    if (QString("cgo_connect").compare((char*)_a) == 0)
        cgo_connect = (COMMAND_CGO_CONNECT_FUNCTION)_b;
    if (QString("cgo_checkconn").compare((char*)_a) == 0)
        cgo_checkconn = (COMMAND_CGO_CHECKCONN_FUNCTION)_b;
    if (QString("cgo_disconn").compare((char*)_a) == 0)
        cgo_disconn = (COMMAND_CGO_DISCONN_FUNCTION)_b;
    if (QString("cgo_command").compare((char*)_a) == 0)
        cgo_command = (COMMAND_CGO_COMMAND_FUNCTION)_b;
    if (QString("cgo_shortcuts").compare((char*)_a) == 0)
        cgo_shortcuts = (COMMAND_CGO_SHORTCUTS_FUNCTION)_b;
    if (QString("cgo_goline").compare((char*)_a) == 0)
        cgo_goline = (COMMAND_CGO_GOLINE_FUNCTION)_b;
    if (QString("cgo_reader").compare((char*)_a) == 0)
        cgo_reader = (COMMAND_CGO_READER_FUNCTION)_b;
    return 1;
}
