#pragma once
#include "std_lib_facilities.h"
class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    Dummy(const Dummy &other);
    ~ Dummy() {
        delete num;
    }
    int get() const {return *num;}
    Dummy& operator=(Dummy rhs);
    

};
void dummyTest();