#ifndef PLUGIN0TEST_HPP
#define PLUGIN0TEST_HPP

#include<QtCore/qstring.h>
class Plugin0Test
{
public:
    Plugin0Test();
public:
    void foo();
public:
    static QString defaultPluginName();
    static void reload(QString);
};

#endif // PLUGIN0TEST_HPP
