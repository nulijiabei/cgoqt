#ifndef CGO_H
#define CGO_H

extern "C" inline int cgo_connect(void *, int) { /* CGO */ }

extern "C" inline void cgo_command(void *, int) { /* CGO */ }

extern "C" inline void * cgo_message() { /* CGO */ }

extern "C" inline int cgo_checkconn() { /* CGO */ }

extern "C" inline void cgo_disconn() { /* CGO */ }

#endif // CGO_H


