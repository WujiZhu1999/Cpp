//
// Created by Wuji Zhu on 20/7/2022.
//

#include <iostream>
class BaseClass {
public:
    void say(){
        std::cout << "Base" << std::endl;
    }
};

class DerivedClass: public BaseClass {
public:
    void say(){
        BaseClass::say();
        std::cout << "Derived" << std::endl;
    }
};

void test_override(){
    DerivedClass().say();
}