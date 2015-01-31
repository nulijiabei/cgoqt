package main

/*
	extern void cgo_init();
	extern int cgo_start();
	extern void cgo_callback(void *);
	extern void drv_cgo_callback(int, void*);
	extern void drv_cgo_callback_2(int, void*);
	static void init_callback()
	{
		int _cgo_connect = 1;
		int _cgo_checkconn = 2;
		int _cgo_disconn = 3;
		int _cgo_command = 4;
		int _cgo_shortcuts = 5;
		int _cgo_message = 6;
		extern int cgo_connect(void *, int);
		extern int cgo_checkconn();
		extern void cgo_disconn();
		extern void cgo_command(void *, int);
		extern void cgo_shortcuts(void *, int);
		extern void * cgo_message();
		drv_cgo_callback_2(_cgo_connect, &cgo_connect);
		drv_cgo_callback_2(_cgo_checkconn, &cgo_checkconn);
		drv_cgo_callback(_cgo_checkconn, &cgo_checkconn);
		drv_cgo_callback(_cgo_disconn, &cgo_disconn);
		drv_cgo_callback(_cgo_command, &cgo_command);
		drv_cgo_callback(_cgo_shortcuts, &cgo_shortcuts);
		drv_cgo_callback(_cgo_message, &cgo_message);
	}
*/
// #include <stdio.h>
// #include <stdlib.h>
// #cgo LDFLAGS: -L./ -lexamples
import "C"
import "unsafe"
import z "github.com/nutzam/zgo"
import "log"

var StaticConn *Conn

var StaticData *Data

func start() {
	C.init_callback()
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
	log.Println("Go->", device)
	if err := StaticConn.Connect(device); err != nil {
		return C.int(0)
	}
	return C.int(1)
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
	StaticConn.WriteConn(z.Trim(command))
}

//export cgo_shortcuts
func cgo_shortcuts(_content unsafe.Pointer, _size C.int) {
	var command string
	content := string(C.GoBytes(_content, _size))
	switch z.Trim(content) {
	case "network":
		command = "ifconfig -a"
	}
	if !z.IsBlank(command) {
		StaticConn.WriteConn(z.Trim(command))
	}
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
