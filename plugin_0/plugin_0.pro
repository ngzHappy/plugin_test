#generic/plugin_0
CONFIG += c++14

QT       += core gui

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


