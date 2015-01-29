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

var StaticConn *Conn

var StaticData *Data

func start() {
	C.cgo_init()
	C.cgo_start()
}

func main() {
	StaticConn = NewConn()
	StaticData = NewData()
	start()
}

//export cgo_connect
func cgo_connect(_content unsafe.Pointer, _size C.int) C.int {
	device := string(C.GoBytes(_content, _size))
	if err := StaticConn.Connect(device); err != nil {
		return 0
	}
	return 1
}

//export cgo_checkconn
func cgo_checkconn() C.int {
	if StaticConn.CheckConn() {
		return 1
	}
	return 0
}

//export cgo_disconn
func cgo_disconn() {
	StaticConn.DisConn()
}

//export cgo_command
func cgo_command(_content unsafe.Pointer, _size C.int) {
	command := string(C.GoBytes(_content, _size))
	StaticConn.WriteConn(command)
}

//export cgo_message
func cgo_message() unsafe.Pointer {
	data := StaticData.getData()
	StaticData.delData()
	return unsafe.Pointer(C.CString(data))
}

func cgo_callback(_content string) {
	C.cgo_callback(unsafe.Pointer(C.CString(_content)))
}
