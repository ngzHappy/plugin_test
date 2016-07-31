#ifndef PLUGINTESTINTERFACE_HPP
#define PLUGINTESTINTERFACE_HPP

#include "testplugindll_global.hpp"
class Plugin0Test;
class TESTPLUGINDLLSHARED_EXPORT Plugin0TestInterface{
public:
    virtual ~Plugin0TestInterface()=default;
    virtual void foo()=0;
    virtual void testData(Plugin0Test*)=0;
};


#endif // PLUGINTESTINTERFACE_HPP
