package main

/*
	extern void init();
	extern int start();
	extern void message(void *);
*/
// #include <stdio.h>
// #include <stdlib.h>
// #cgo LDFLAGS: -L./ -lexamples -framework QtGui
import "C"

// import "unsafe"
// import ()

func main() {

	C.start()

}
