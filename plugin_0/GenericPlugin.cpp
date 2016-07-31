#include "GenericPlugin.hpp"
#include "Plugin0Test.hpp"
#include <QtCore/qdebug.h>

GenericPlugin::GenericPlugin(QObject *parent) :
    QGenericPlugin(parent){
}

QObject * GenericPlugin::create(const QString &,const QString &) {
    return nullptr;
}

void GenericPlugin::foo(){
    qDebug()<<"xxxx";
}

void GenericPlugin::testData(Plugin0Test* arg) {
    if (arg==nullptr) { return; }
    qDebug()<<arg->data();
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(plugin_0, GenericPlugin)
#endif // QT_VERSION < 0x050000


