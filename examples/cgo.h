#ifndef CGO_H
#define CGO_H

using namespace std;

extern "C" inline void input(void *, int) { /* CGO */ }

extern "C" inline void * output() { /* CGO */ }

extern "C" void init()
{
}

extern "C" int start()
{
}

#endif // CGO_H
