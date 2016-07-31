#ifndef PLUGIN0TEST_HPP
#define PLUGIN0TEST_HPP

#include "testplugindll_global.hpp"
#include<QtCore/qstring.h>
class TESTPLUGINDLLSHARED_EXPORT Plugin0Test
{
    QString data_;
public:
    Plugin0Test();
    virtual~Plugin0Test();
public:
    void foo();
    void testData();
    const QString & data() const { return data_; }
    void setData(QString arg) { data_=std::move(arg); }
public:
    static QString defaultPluginName();
    static void reload(QString);
};

#endif // PLUGIN0TEST_HPP
