#ifndef CGO_CONNECT_H
#define CGO_CONNECT_H

#include <QtGui>


typedef int (*COMMAND_CGO_CONNECT_FUNCTION)(void *, int);

typedef int (*COMMAND_CGO_CHECKCONN_FUNCTION)();

static COMMAND_CGO_CONNECT_FUNCTION cgo_connect = 0;

static COMMAND_CGO_CHECKCONN_FUNCTION cgo_checkconn = 0;

extern "C" void drv_cgo_callback_2(int _a, void * _b)
{
    /*
    int _cgo_connect = 1;
    int _cgo_checkconn = 2;
    */
    switch (_a) {
    case 1:
        cgo_connect = (COMMAND_CGO_CONNECT_FUNCTION)_b;
        break;
    case 2:
        cgo_checkconn = (COMMAND_CGO_CHECKCONN_FUNCTION)_b;
        break;
    }
}

#endif // CGO_CONNECT_H

