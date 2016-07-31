#ifndef PLUGINTESTINTERFACE_HPP
#define PLUGINTESTINTERFACE_HPP

class Plugin0Test;
class Plugin0TestInterface{
public:
    virtual ~Plugin0TestInterface()=default;
    virtual void foo()=0;
};


#endif // PLUGINTESTINTERFACE_HPP
