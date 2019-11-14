#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "Base.hpp"

class Connector : public Base {
public:
    Connector();
    ~Connector();

    void setLeft(Base*);
    void setRight(Base*);

    Base* getLeft();
    Base* getRight();

    virtual bool execute() = 0;
protected:
    Base* left;
    Base* right;
};

#endif