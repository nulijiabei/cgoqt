package main

/*
	extern void init();
	extern int start();
	extern void drv_cgo_callback(void*, void*);
	static void callback()
	{   char * _cgo_connect = "cgo_connect";
		char * _cgo_checkconn = "cgo_checkconn";
		char * _cgo_disconn = "cgo_disconn";
		char * _cgo_command = "cgo_command";
		char * _cgo_shortcuts = "cgo_shortcuts";
		char * _cgo_goline = "cgo_goline";
		char * _cgo_reader = "cgo_reader";
		char * _cgo_writer = "cgo_writer";
		extern int cgo_connect(void*, int, void*, int);
		extern int cgo_checkconn();
		extern void cgo_disconn();
		extern void cgo_command(void*, int);
		extern void cgo_shortcuts(void*, int);
		extern void cgo_goline(void*, int);
		extern void cgo_reader(void*, int);
		extern void cgo_writer(void*, int, void*, int);
		drv_cgo_callback(_cgo_connect, &cgo_connect);
		drv_cgo_callback(_cgo_checkconn, &cgo_checkconn);
		drv_cgo_callback(_cgo_disconn, &cgo_disconn);
		drv_cgo_callback(_cgo_command, &cgo_command);
		drv_cgo_callback(_cgo_shortcuts, &cgo_shortcuts);
		drv_cgo_callback(_cgo_goline, &cgo_goline);
		drv_cgo_callback(_cgo_reader, &cgo_reader);
		drv_cgo_callback(_cgo_writer, &cgo_writer);
	}
	extern void recvMessageByCgo(void*);
	extern void recvDisplayByCgo(void*);
	extern void recvContentByCgo(void*);
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

// 全局连接
var StaticConn *Conn

// 开始
func start() {
	C.init()
	C.callback()
	C.start()
}

// 主
func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	log.SetFlags(log.Lshortfile | log.Ldate | log.Ltime | log.Lmicroseconds)
	StaticConn = NewConn()
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
	err := StaticConn.SendCommandByConn(z.Trim(command))
	if err != nil {
		cgo_message(err.Error())
	}
}

//export cgo_reader
func cgo_reader(_content unsafe.Pointer, _size C.int) {
	command := string(C.GoBytes(_content, _size))
	err := StaticConn.SendReaderByConn(z.Trim(command))
	if err != nil {
		cgo_message(err.Error())
	}
}

//export cgo_writer
func cgo_writer(_content unsafe.Pointer, _size C.int, _content_2 unsafe.Pointer, _size_2 C.int) {
	command := string(C.GoBytes(_content, _size))
	content := string(C.GoBytes(_content_2, _size_2))
	err := StaticConn.SendWriterByConn(z.Trim(command), z.Trim(content))
	if err != nil {
		cgo_message(err.Error())
	}
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
		err := StaticConn.SendCommandByConn(z.Trim(command))
		if err != nil {
			cgo_message(err.Error())
		}
	}
}

//export cgo_goline
func cgo_goline(_content unsafe.Pointer, _size C.int) {
	content := string(C.GoBytes(_content, _size))
	data := strings.Split(z.Trim(content), " ")
	if len(data) == 4 {
		err := StaticConn.SendGolineByConn(z.Trim(data[0]), z.Trim(data[1]), z.Trim(data[2]), z.Trim(data[3]))
		if err != nil {
			cgo_message(err.Error())
		}
	}
}

// C
func cgo_message(_content string) {
	content := C.CString(_content)
	// For Windows QT Free
	defer C.free(unsafe.Pointer(content))
	C.recvMessageByCgo(unsafe.Pointer(content))
}

// C
func cgo_display(_content string) {
	content := C.CString(_content)
	// For Windows QT Free
	defer C.free(unsafe.Pointer(content))
	C.recvDisplayByCgo(unsafe.Pointer(content))
}

// C
func cgo_content(_content string) {
	content := C.CString(_content)
	// For Windows QT Free
	defer C.free(unsafe.Pointer(content))
	C.recvContentByCgo(unsafe.Pointer(content))
}
