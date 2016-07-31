#generic/plugin_0
CONFIG += c++14

INCLUDEPATH+=$$PWD/../TestPluginDll

QT += core gui

CONFIG(debug,debug|release){
TARGET = plugin_0d
}else{
TARGET = plugin_0
}

TEMPLATE = lib
CONFIG += plugin

DESTDIR = $$[QT_INSTALL_PLUGINS]/generic

SOURCES += GenericPlugin.cpp

HEADERS += GenericPlugin.hpp
DISTFILES += plugin_0.json

include($$PWD/../PluginTest.pri)
CONFIG(debug,debug|release){
LIBS+=-L$$DESTDIR_THE_PROJECT -lTestPluginDlld
}else{
LIBS+=-L$$DESTDIR_THE_PROJECT -lTestPluginDll
}

