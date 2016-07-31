CONFIG += c++14
INCLUDEPATH += $$PWD

QT += gui

CONFIG(debug,debug|release){
TARGET = TestPluginDlld
}else{
TARGET = TestPluginDll
}

TEMPLATE = lib

DEFINES += TESTPLUGINDLL_LIBRARY

SOURCES += TestPluginDll.cpp \
    Plugin0Test.cpp

HEADERS += TestPluginDll.hpp\
        testplugindll_global.hpp \
    Plugin0Test.hpp \
    PluginTestInterface.hpp

include($$PWD/../PluginTest.pri)
DESTDIR=$$DESTDIR_THE_PROJECT

