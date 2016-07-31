#include "GenericPlugin.hpp"
#include <iostream>

GenericPlugin::GenericPlugin(QObject *parent) :
    QGenericPlugin(parent){
}

QObject * GenericPlugin::create(const QString &,const QString &) {
    return nullptr;
}

void GenericPlugin::foo(){
    std::cout<<"xxxx"<<std::endl;
    std::cout.flush();
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(plugin_0, GenericPlugin)
#endif // QT_VERSION < 0x050000


