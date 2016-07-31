#include <memory>
#include <QtCore/QPluginLoader>
#include <QtCore/qdebug.h>
#include "Plugin0Test.hpp"
#include "PluginTestInterface.hpp"
#include "../plugin_0/GenericPlugin.hpp"

namespace {
std::shared_ptr<Plugin0TestInterface> __plugin;
QString __old__plugin__name;

void reload_plugin0(QString argPluginName) {
    const auto varOldPlugin=__plugin;

    if (argPluginName.isEmpty()) {
        argPluginName=Plugin0Test::defaultPluginName();
    }

    if (varOldPlugin) {
        if (__old__plugin__name==argPluginName) {
            qDebug()<<"plugin:"<<__old__plugin__name<<"has loaded!";
            return;
        }
    }

    auto varLoader=std::make_shared<QPluginLoader>(argPluginName);
    QObject * varPluginQobjectPointer=varLoader->instance();
    if (varPluginQobjectPointer) {
        auto varDeleteFunction=[varLoader=std::move(varLoader),
            varPluginQobjectPointer](){
            delete varPluginQobjectPointer;
            varLoader->unload();
        };
        auto varPluginPointer=dynamic_cast<Plugin0TestInterface *>(varPluginQobjectPointer);
        std::shared_ptr<Plugin0TestInterface> varNewPlugin{
            varPluginPointer,
            [varDeleteFunction=std::move(varDeleteFunction)](auto *) {
            /*may move delete in main thread??*/
            varDeleteFunction();
        }
        };
        std::swap(varNewPlugin,__plugin);
        std::swap(__old__plugin__name,argPluginName);
    }
    else {
        qDebug()<<"can not find plugin"<<argPluginName;
    }

}

std::shared_ptr<Plugin0TestInterface> import_plugin0() {
    if (bool(__plugin)==false) {
        reload_plugin0({});
    }
    return __plugin/*make a copy*/;
}

}

Plugin0Test::Plugin0Test() {
    data_="test";
}

Plugin0Test::~Plugin0Test() {
}

void Plugin0Test::foo() {
    auto varPack=import_plugin0();
    varPack->foo();
}

void Plugin0Test::testData() {
    auto varPack=import_plugin0();
    varPack->testData(this);
}

QString Plugin0Test::defaultPluginName() {
#if defined(_DEBUG)&&!defined(NDEBUG)
    const static QString varPluginName=QLatin1String("generic/default_plugin_0d");
#else
    const static QString varPluginName=QLatin1String("generic/default_plugin_0");
#endif
    return varPluginName;
}

void Plugin0Test::reload(QString arg) {
    reload_plugin0(std::move(arg));
}
