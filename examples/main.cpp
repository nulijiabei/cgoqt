#include <QApplication>
#include <QTextCodec>
#include "examples.h"
#include "cgo.h"


using namespace std;

Examples * win;

Cgo * cgo;

extern "C" void init()
{
    cgo = new Cgo();
}

extern "C" int start()
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

extern "C" void drv_cgo_callback(void* _a, void* _b)
{
    cgo->setCgo(_a, _b);
}


extern "C" void recvMessageByCgo(void * _content)
{
   win->recvMessageByCgo((const char *)_content);
}

extern "C" void recvDisplayByCgo(void * _content)
{
   win->recvDisplayByCgo((const char *)_content);
}

extern "C" void recvContentByCgo(void * _content)
{
    win->recvContentByCgo((const char *)_content);
}
