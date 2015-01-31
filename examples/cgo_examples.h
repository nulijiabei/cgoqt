#ifndef CGO_CONNECT
#define CGO_CONNECT

typedef void (*COMMAND_CGO_DISCONN_FUNCTION)();

typedef void (*COMMAND_CGO_COMMAND_FUNCTION)(void *, int);

typedef void (*COMMAND_CGO_SHORTCUTS_FUNCTION)(void *, int);

typedef void * (*COMMAND_CGO_MESSAGE_FUNCTION)();

typedef int (*COMMAND_CGO_CHECKCONN_2_FUNCTION)();

static COMMAND_CGO_DISCONN_FUNCTION cgo_disconn = 0;

static COMMAND_CGO_COMMAND_FUNCTION cgo_command = 0;

static COMMAND_CGO_SHORTCUTS_FUNCTION cgo_shortcuts = 0;

static COMMAND_CGO_MESSAGE_FUNCTION cgo_message = 0;

static COMMAND_CGO_CHECKCONN_2_FUNCTION cgo_checkconn_2 = 0;

extern "C" void drv_cgo_callback(int _a, void * _b)
{
    /*
    int _cgo_connect = 1;
    int _cgo_checkconn = 2;
    int _cgo_disconn = 3;
    int _cgo_command = 4;
    int _cgo_shortcuts = 5;
    int _cgo_message = 6;
    */
    switch (_a) {
    case 3:
        cgo_disconn = (COMMAND_CGO_DISCONN_FUNCTION)_b;
        break;
    case 4:
        cgo_command = (COMMAND_CGO_COMMAND_FUNCTION)_b;
        break;
    case 5:
        cgo_shortcuts = (COMMAND_CGO_SHORTCUTS_FUNCTION)_b;
        break;
    case 6:
        cgo_message = (COMMAND_CGO_MESSAGE_FUNCTION)_b;
        break;
    case 2:
        cgo_checkconn_2 = (COMMAND_CGO_CHECKCONN_2_FUNCTION)_b;
        break;
    }
}


#endif // CGO_CONNECT

