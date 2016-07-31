CONFIG += c++14
CONFIG += console

CONFIG(debug,debug|release){
DEFINES*=_DEBUG
}else{
DEFINES*=NDEBUG
}

QT += core gui
QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Plugin0Test.cpp

HEADERS  += MainWindow.hpp \
    Plugin0Test.hpp \
    PluginTestInterface.hpp
