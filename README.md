----------------

http://www.nljb.net 具体介绍

一套行之有效的CGO+QT混写GUI结构

使用QT与GO开发图形程序，无非就是在QT中调用GO函数，在GO中使用QT方法。

目的呢，也就是贪图GO的简介以及在网络单元开发的优势，同时发挥QT的界面强项

在MVC中，数据层交给GO，视图交给QT，控制主要交给QT，部分触发事件由GO来做.

A，在GO中，通过注释导入#include 头文件来使用其中的函数(C.xxx())

B，在GO中，通过注释引导-lexamples库文件来使用其中的函数(C.xxx())

C，在GO中，通过函数行注释//export cgo_checkconn方式把GO函数转成C函数，并且在C中调用

D，在GO中，通过//export方式将Go转C，一定要，extern(表示变量或者函数的定义在别的文件中)

...

(http://raw.githubusercontent.com/nulijiabei/cgoqt/master/screenshot.png)

