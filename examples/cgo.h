#ifndef CGO_H
#define CGO_H

#include <map>
#include <string>

using namespace std;

typedef int (*COMMAND_CGO_CONNECT_FUNCTION)(void*, int, void*, int);
typedef int (*COMMAND_CGO_CHECKCONN_FUNCTION)();
typedef void (*COMMAND_CGO_DISCONN_FUNCTION)();
typedef void (*COMMAND_CGO_COMMAND_FUNCTION)(void*, int);
typedef void (*COMMAND_CGO_SHORTCUTS_FUNCTION)(void*, int);
typedef int (*COMMAND_CGO_GOLINE_FUNCTION)(void*, int);
typedef void (*COMMAND_CGO_READER_FUNCTION)(void*, int);
typedef int (*COMMAND_CGO_WRITER_FUNCTION)(void*, int, void*, int);

class Cgo
{
public:
    Cgo();
    int setCgo(void*, void*);
public:
    COMMAND_CGO_CONNECT_FUNCTION cgo_connect;
    COMMAND_CGO_CHECKCONN_FUNCTION cgo_checkconn;
    COMMAND_CGO_DISCONN_FUNCTION cgo_disconn;
    COMMAND_CGO_COMMAND_FUNCTION cgo_command;
    COMMAND_CGO_SHORTCUTS_FUNCTION cgo_shortcuts;
    COMMAND_CGO_GOLINE_FUNCTION cgo_goline;
    COMMAND_CGO_READER_FUNCTION cgo_reader;
    COMMAND_CGO_WRITER_FUNCTION cgo_writer;
};

#endif // CGO_H
