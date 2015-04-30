----------------

说明：这个项目不是一个CGOQT的库，而是一个我使用CGO+QT写成的一个软件

主要是将CGO的函数，通过函数指针传到QT中，在QT中使用，所以就需要混合编译

先在QT中把所有需要GO的方法都留空，只实现一个从GO接收函数的接口，然后定义空函数使用

然后将写好的QT程序编译成LIB库，放到GO中，通过GO调用LIB库中函数传递函数指针来实现工作的

----------------

有个想法, 想法，想法 ...... 想做一个Go转C++(QT)的接口工具

例如：cgo2qt main.go ...

会生成三个文件：

	1, cgo.go 
	2, cgo.hpp
	3, cgo.cpp

	cgo.go  - 包含着所有在GO中的C代码和接口
	cgo.hpp - 包含着所有供QT使用的CGO代码声明
	cgo.cpp - 包含着所有供QT使用的CGO代码实现

拿到这三个文件后，你需要做三件事情

	1, 将cgo.hpp和cgo.cpp拷贝到QT项目里面使用
	2, 将QT+cgo.hpp+cgo.cpp写好的程序编译Lib库
	3, 将Lib库放到Go项目下与CGO代码一起编译即可

要做的事情有很多 ...

	1, 比如要求要将所有需要转换的函数加标签(//cgoqt funcName)
	2, 将所有带标签的函数转换成供Go使用的CGO中间函数
	3, 将所有供CGO使用的中间函数转换成C函数供QT使用

这里面需要处理:

	1, 所有类型对应关系, 比如：int(GO) -> C.int(CGO) -> int(C)
	2, 为所有函数生成对应的函数指针及类型，供函数传递

....

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

