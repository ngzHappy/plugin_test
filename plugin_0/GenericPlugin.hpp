#ifndef GENERICPLUGIN_HPP
#define GENERICPLUGIN_HPP

#include <QGenericPlugin>
#include "../Test/PluginTestInterface.hpp"

class GenericPlugin :
        public QGenericPlugin,
        public Plugin0TestInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" FILE "plugin_0.json")
#endif // QT_VERSION >= 0x050000

public:
    GenericPlugin(QObject *parent = 0);
    QObject *create(const QString &,const QString &)override;
public:
    virtual void foo() override;
};

#endif // GENERICPLUGIN_HPP





