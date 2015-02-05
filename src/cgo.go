package main

/*
	extern void cgo_init();
	extern int cgo_start();
	extern void cgo_callback(void*);
	extern void drv_cgo_callback(void*, void*);
	static void callback()
	{   char * _cgo_connect = "cgo_connect";
		char * _cgo_checkconn = "cgo_checkconn";
		char * _cgo_disconn = "cgo_disconn";
		char * _cgo_command = "cgo_command";
		char * _cgo_shortcuts = "cgo_shortcuts";
		char * _cgo_message = "cgo_message";
		char * _cgo_goline = "cgo_goline";
		extern int cgo_connect(void*, int, void*, int);
		extern int cgo_checkconn();
		extern void cgo_disconn();
		extern void cgo_command(void*, int);
		extern void cgo_shortcuts(void*, int);
		extern void* cgo_message();
		extern void cgo_goline(void*, int);
		drv_cgo_callback(_cgo_connect, &cgo_connect);
		drv_cgo_callback(_cgo_checkconn, &cgo_checkconn);
		drv_cgo_callback(_cgo_disconn, &cgo_disconn);
		drv_cgo_callback(_cgo_command, &cgo_command);
		drv_cgo_callback(_cgo_shortcuts, &cgo_shortcuts);
		drv_cgo_callback(_cgo_message, &cgo_message);
		drv_cgo_callback(_cgo_goline, &cgo_goline);

	}
*/
// #include <stdio.h>
// #include <stdlib.h>
// #cgo LDFLAGS: -L./ -lexamples
import "C"
import "unsafe"
import (
	z "github.com/nutzam/zgo"
	"log"
	"runtime"
	"strings"
)

var StaticConn *Conn

var StaticData *Data

func start() {
	C.cgo_init()
	C.callback()
	C.cgo_start()
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	log.SetFlags(log.Lshortfile | log.Ldate | log.Ltime | log.Lmicroseconds)
	StaticConn = NewConn()
	StaticData = NewData()
	start()
}

//export cgo_connect
func cgo_connect(_content unsafe.Pointer, _size C.int, _content_2 unsafe.Pointer, _size_2 C.int) C.int {
	device := string(C.GoBytes(_content, _size))
	authorize := string(C.GoBytes(_content_2, _size_2))
	if err := StaticConn.Connect(device, "1.02", authorize); err != nil {
		return C.int(0)
	}
	return C.int(1)
}

//export cgo_checkconn
func cgo_checkconn() C.int {
	if StaticConn.CheckConn() {
		return C.int(1)
	}
	return C.int(0)
}

//export cgo_disconn
func cgo_disconn() {
	StaticConn.DisConn()
}

//export cgo_command
func cgo_command(_content unsafe.Pointer, _size C.int) {
	command := string(C.GoBytes(_content, _size))
	StaticConn.SendCommandByConn(z.Trim(command))
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
		StaticConn.SendCommandByConn(z.Trim(command))
	}
}

//export cgo_message
func cgo_message() unsafe.Pointer {
	data := StaticData.getData()
	StaticData.delData()
	// 在哪里创建，就在哪里释放
	content := C.CString(data)
	// For Windows QT Free
	defer C.free(unsafe.Pointer(content))
	return unsafe.Pointer(content)
}

//export cgo_goline
func cgo_goline(_content unsafe.Pointer, _size C.int) {
	content := string(C.GoBytes(_content, _size))
	data := strings.Split(z.Trim(content), " ")
	if len(data) == 4 {
		StaticConn.SendGolineByConn(z.Trim(data[0]), z.Trim(data[1]), z.Trim(data[2]), z.Trim(data[3]))
	}
}

func cgo_display(_content string) {
	// 在哪里创建，就在哪里释放
	content := C.CString(_content)
	// For Windows QT Free
	defer C.free(unsafe.Pointer(content))
	C.cgo_callback(unsafe.Pointer(content))
}
