----------------

http://www.nljb.net 具体介绍

一套行之有效的CGO+QT混血GUI结构

使用QT与GO开发图形程序，无非就是在QT中调用GO函数，在GO中使用QT方法。

目的呢，也就是贪图GO的简介以及在网络单元开发的优势，同时发挥QT的界面强项

在MVC中，数据层交给GO，视图交给QT，控制主要交给QT，部分触发事件由GO来做.

A，在GO中，通过注释导入#include 头文件来使用其中的函数(C.xxx())

B，在GO中，通过注释引导-lexamples库文件来使用其中的函数(C.xxx())

C，在GO中，通过函数行注释//export cgo_checkconn方式把GO函数转成C函数，并且在C中调用

D，在GO中，通过//export方式将Go转C，一定要，extern(表示变量或者函数的定义在别的文件中)

    // Cgo.h
    #ifndef CGO_H
    #define CGO_H
    #include <map>
    #include <string>
    using namespace std;
    typedef int (*COMMAND_CGO_CONNECT_FUNCTION)(void*, int, void*, int);
    typedef int (*COMMAND_CGO_CHECKCONN_FUNCTION)();
    typedef void (*COMMAND_CGO_DISCONN_FUNCTION)();
    typedef void (*COMMAND_CGO_COMMAND_FUNCTION)(void*, int);
    typedef void (*COMMAND_CGO_SHORTCUTS_FUNCTION)(void*, int);
    typedef int (*COMMAND_CGO_GOLINE_FUNCTION)(void*, int);
    typedef void (*COMMAND_CGO_READER_FUNCTION)(void*, int);
    typedef int (*COMMAND_CGO_WRITER_FUNCTION)(void*, int, void*, int);
    class Cgo
    {
    public:
        Cgo();
        int setCgo(void*, void*);
    public:
        COMMAND_CGO_CONNECT_FUNCTION cgo_connect;
        COMMAND_CGO_CHECKCONN_FUNCTION cgo_checkconn;
        COMMAND_CGO_DISCONN_FUNCTION cgo_disconn;
        COMMAND_CGO_COMMAND_FUNCTION cgo_command;
        COMMAND_CGO_SHORTCUTS_FUNCTION cgo_shortcuts;
        COMMAND_CGO_GOLINE_FUNCTION cgo_goline;
        COMMAND_CGO_READER_FUNCTION cgo_reader;
        COMMAND_CGO_WRITER_FUNCTION cgo_writer;
    };
    #endif // CGO_H
    // Cgo.cpp
    #include <QString>
    #include "cgo.h"
    Cgo::Cgo()
    {
        cgo_connect = 0;
        cgo_checkconn = 0;
        cgo_disconn = 0;
        cgo_command = 0;
        cgo_shortcuts = 0;
        cgo_goline = 0;
        cgo_reader = 0;
        cgo_writer = 0;
    }
    int Cgo::setCgo(void* _a, void* _b)
    {
        if (QString("cgo_connect").compare((char*)_a) == 0)
        cgo_connect = (COMMAND_CGO_CONNECT_FUNCTION)_b;
        if (QString("cgo_checkconn").compare((char*)_a) == 0)
        cgo_checkconn = (COMMAND_CGO_CHECKCONN_FUNCTION)_b;
        if (QString("cgo_disconn").compare((char*)_a) == 0)
        cgo_disconn = (COMMAND_CGO_DISCONN_FUNCTION)_b;
        if (QString("cgo_command").compare((char*)_a) == 0)
        cgo_command = (COMMAND_CGO_COMMAND_FUNCTION)_b;
        if (QString("cgo_shortcuts").compare((char*)_a) == 0)
        cgo_shortcuts = (COMMAND_CGO_SHORTCUTS_FUNCTION)_b;
        if (QString("cgo_goline").compare((char*)_a) == 0)
        cgo_goline = (COMMAND_CGO_GOLINE_FUNCTION)_b;
        if (QString("cgo_reader").compare((char*)_a) == 0)
        cgo_reader = (COMMAND_CGO_READER_FUNCTION)_b;
        if (QString("cgo_writer").compare((char*)_a) == 0)
        cgo_writer = (COMMAND_CGO_WRITER_FUNCTION)_b;
        return 1;
    }
    
    // Go
    package main
    /*
        extern void init(); // 这里是声明在QT里面的函数，方便调用
        extern int start(); // 这里是声明在QT里面的函数，方便调用
        extern void drv_cgo_callback(void*, void*); // 这里是声明在QT里面的函数，方便调用
        static void callback() // GO中调用
        {   char * _cgo_connect = "cgo_connect"; // 函数名称，以便QT内区分
            char * _cgo_checkconn = "cgo_checkconn"; // 函数名称，以便QT内区分
            char * _cgo_disconn = "cgo_disconn"; // 函数名称，以便QT内区分
            char * _cgo_command = "cgo_command"; // 函数名称，以便QT内区分
            char * _cgo_shortcuts = "cgo_shortcuts"; // 函数名称，以便QT内区分
            char * _cgo_goline = "cgo_goline"; // 函数名称，以便QT内区分
            char * _cgo_reader = "cgo_reader"; // 函数名称，以便QT内区分
            char * _cgo_writer = "cgo_writer"; // 函数名称，以便QT内区分
            extern int cgo_connect(void*, int, void*, int); // 这里是声明在GO转C函数，方便传递
            extern int cgo_checkconn(); // 这里是声明在GO转C函数，方便传递
            extern void cgo_disconn(); // 这里是声明在GO转C函数，方便传递
            extern void cgo_command(void*, int); // 这里是声明在GO转C函数，方便传递
            extern void cgo_shortcuts(void*, int); // 这里是声明在GO转C函数，方便传递
            extern void cgo_goline(void*, int); // 这里是声明在GO转C函数，方便传递
            extern void cgo_reader(void*, int); // 这里是声明在GO转C函数，方便传递
            extern void cgo_writer(void*, int, void*, int); // 这里是声明在GO转C函数，方便传递
            drv_cgo_callback(_cgo_connect, &cgo_connect); // 调用 QT 内函数，传入 GO转C 函数指针
            drv_cgo_callback(_cgo_checkconn, &cgo_checkconn); // 调用 QT 内函数，传入 GO转C 函数指针
            drv_cgo_callback(_cgo_disconn, &cgo_disconn); // 调用 QT 内函数，传入 GO转C 函数指针
            drv_cgo_callback(_cgo_command, &cgo_command); // 调用 QT 内函数，传入 GO转C 函数指针
            drv_cgo_callback(_cgo_shortcuts, &cgo_shortcuts); // 调用 QT 内函数，传入 GO转C 函数指针
            drv_cgo_callback(_cgo_goline, &cgo_goline); // 调用 QT 内函数，传入 GO转C 函数指针
            drv_cgo_callback(_cgo_reader, &cgo_reader); // 调用 QT 内函数，传入 GO转C 函数指针
            drv_cgo_callback(_cgo_writer, &cgo_writer); // 调用 QT 内函数，传入 GO转C 函数指针
        }
    */
    // #include <stdio.h>
    // #include <stdlib.h>
    // #cgo LDFLAGS: -L./ -lexamples // 注意：这里将QT编译成库文件，在GO中引入使用.
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
        C.init() // 调用QT中的函数，初始化
        C.callback() // 调用GO中注释的C函数，建GO转C函数传入到QT中
        C.start() // 调用QT中的函数，启动程序
    }
    // 主
    func main() {
        log.Println(z.UnixMsSec(1))
        runtime.GOMAXPROCS(runtime.NumCPU())
        log.SetFlags(log.Lshortfile | log.Ldate | log.Ltime | log.Lmicroseconds)
        StaticConn = NewConn()
        start()
    }
    //export cgo_connect
    func cgo_connect(_content unsafe.Pointer, _size C.int, _content_2 unsafe.Pointer, _size_2 C.int) C.int {
        device := string(C.GoBytes(_content, _size))
        authorize := string(C.GoBytes(_content_2, _size_2))
        if err := StaticConn.Connect(device, "1.03", authorize); err != nil {
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

    // 说明
    // 也就是，在 Go 里面调用 QT 函数
    // 然后 把 Go转C 的函数传入 QT 函数内
    // 然后 在 QT 函数内调用 Go转C 的函数
    #include <QApplication>
    #include <QTextCodec>
    #include "examples.h"
    #include "cgo.h"
    using namespace std;
    // 这里是QT窗口
    Examples * win;
    // Cgo 就是保存有GO函数指针的类
    Cgo * cgo;
    // 初始化，生成保存函数指针的类 (在Go内调用）
    extern "C" void init()
    {
        cgo = new Cgo();
    }
    // 开始运行 (在Go内调用)
    extern "C" int start()
    {
        int argc = 0 ;
        char *argv[] = {};
        QApplication a(argc, argv);
        win = new Examples();
        // 这里把存有GO函数指针的类传入QT窗口类中.
        win->setCgo(cgo);
        win->show();
        return a.exec();
    }
    // 这里就是，接收GO传入函数指针的地方 (在GO内调用)
    extern "C" void drv_cgo_callback(void* _a, void* _b)
    {
        // 这里，将函数指针保存到Cgo类中
        // _a 是函数名，_b 是函数指针
        cgo->setCgo(_a, _b);
    }
    
...
