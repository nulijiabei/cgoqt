package main

/*
	extern void cgo_init();
	extern int cgo_start();
	extern void cgo_callback(void *);
*/
// #include <stdio.h>
// #include <stdlib.h>
// #cgo LDFLAGS: -L./ -lexamples -framework QtGui
import "C"
import "unsafe"

func start() {
	C.cgo_init()
	C.cgo_start()
}

//export cgo_connect
func cgo_connect(_content unsafe.Pointer, _size C.int) C.int {
	device := string(C.GoBytes(_content, _size))
	if err := conn.Connect(device); err != nil {
		return 0
	}
	return 1
}

//export cgo_command
func cgo_command(_content unsafe.Pointer, _size C.int) C.int {
	command := string(C.GoBytes(_content, _size))
	if err := conn.Write(command); err != nil {
		return 0
	}
	return 1
}

func cgo_callback(_content string) {
	C.cgo_callback(unsafe.Pointer(C.CString(_content)))
}
