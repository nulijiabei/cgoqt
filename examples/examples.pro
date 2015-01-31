#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T16:38:52
#
#-------------------------------------------------

QMAKE_LFLAGS += -v

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = examples
TEMPLATE = lib

SOURCES +=\
    examples.cpp \
    connect.cpp \
    cgo_main.cpp

HEADERS  += \
    examples.h \
    connect.h \
    cgo_connect.h \
    cgo_examples.h

FORMS    += \
    examples.ui \
    connect.ui

RESOURCES += \
    examples.qrc
