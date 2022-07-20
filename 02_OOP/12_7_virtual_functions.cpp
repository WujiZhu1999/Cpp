//
// Created by Wuji Zhu on 20/7/2022.
//
#include <iostream>

class Base {
public:
    void virtual greeting() {
        std::cout << "hi" << std::endl;
    }

    void greeting_no_virtual() {
        std::cout << "hi" << std::endl;
    }
};

class Derived: public Base {
public:
    void greeting() {
        std::cout << "hello" << std::endl;
    }

    void greeting_no_virtual() {
        std::cout << "hello" << std::endl;
    }
};

void test_with_virtual_function_copy_constructor() {
    Base b = Derived();
    b.greeting();
}

void test_without_virtual_function_copy_constructor() {
    Base b = Derived();
    b.greeting_no_virtual();
}

void test_with_virtual_pointer() {
    Derived d;
    Base *b = &d;
    b->greeting();
}

void test_without_virtual_pointer() {
    Derived d;
    Base *b = &d;
    b->greeting_no_virtual();
}

