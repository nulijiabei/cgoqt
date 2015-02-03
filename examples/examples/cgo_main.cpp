#include "examples.h"
#include "cgo.h"
#include <QApplication>

using namespace std;

Examples * win;

Cgo * cgo;

extern "C" void cgo_init()
{
    cgo = new Cgo();
}

extern "C" int cgo_start()
{
    int argc = 0 ;
    char *argv[] = {};
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    win = new Examples();
    win->setCgo(cgo);
    win->show();
    return a.exec();
}

extern "C" void cgo_callback(void * p)
{
    win->sendDisplay((char*)p);
}

extern "C" void drv_cgo_callback(void* _a, void* _b)
{
    cgo->setCgo(_a, _b);
}

