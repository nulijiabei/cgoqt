----------------

最新消息是Google已经在开始实验性的开发gxui库

相信不远的明天，可以通过gxui库开发纯Go的桌面软件

项目地址：https://github.com/google/gxui

对于本项目，只是提供了一个使用CGO与QT混血桌面软件的一种方式

所以没有什么停止与不停止，关闭与不关闭之说.

只要你需要，这个方式一直就存在，本项目就是该方式的一个例子

而且我也通过该方式开发出实实在在的软件并且应用到windows和macos上

----------------

说明：这个项目不是一个CGOQT的库，而是一个我使用CGO+QT写成的一个软件

主要是将CGO的函数，通过函数指针传到QT中，在QT中使用，所以就需要混合编译

先在QT中把所有需要GO的方法都留空，只实现一个从GO接收函数的接口，然后定义空函数使用

然后将写好的QT程序编译成LIB库，放到GO中，通过GO调用LIB库中函数传递函数指针来实现工作的

----------------

http://www.nljb.net 具体介绍

----------------

一套行之有效的CGO+QT混写GUI结构

----------------

使用QT与GO开发图形程序，无非就是在QT中调用GO函数，在GO中使用QT方法。

目的呢，也就是贪图GO的简介以及在网络单元开发的优势，同时发挥QT的界面强项

在MVC中，数据层交给GO，视图交给QT，控制主要交给QT，部分触发事件由GO来做.

	A，在GO中，通过注释导入#include 头文件来使用其中的函数(C.xxx())
	B，在GO中，通过注释引导-lexamples库文件来使用其中的函数(C.xxx())
	C，在GO中，通过函数行注释//export cgo_checkconn方式把GO函数转成C函数，并且在C中调用
	D，在GO中，通过//export方式将Go转C，一定要，extern(表示变量或者函数的定义在别的文件中)

----------------

![image](https://raw.githubusercontent.com/nulijiabei/cgoqt/master/screenshot.png)

