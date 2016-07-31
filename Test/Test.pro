CONFIG += c++14
CONFIG += console

INCLUDEPATH+=$$PWD/../TestPluginDll

QT += core gui
QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.hpp

include($$PWD/../PluginTest.pri)
DESTDIR=$$DESTDIR_THE_PROJECT
CONFIG(debug,debug|release){
LIBS+=-L$$DESTDIR_THE_PROJECT -lTestPluginDlld
}else{
LIBS+=-L$$DESTDIR_THE_PROJECT -lTestPluginDll
}
