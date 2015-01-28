#include "examples.h"

using namespace std;

Examples * w;

extern "C" void cgo_init()
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
}

extern "C" int cgo_start()
{
    int argc = 0 ;
    char *argv[] = {};
    QApplication a(argc, argv);
    w = new Examples;
    w->show();
    return a.exec();
}

extern "C" void cgo_callback(void * p)
{
    w->sendDisplay((char*)p);
    free(p);
}
