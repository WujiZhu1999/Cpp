//
// Created by Wuji Zhu on 30/8/2022.
//

#include <any>
#include <iostream>

void test_any() {
    //construct, has value
    std::any a1;
    std::cout << a1.has_value() << std::endl;

    //emplace
    a1.emplace<int>(1);
    std::cout << a1.has_value() << std::endl;
    std::cout << a1.type().name() << std::endl;

    //any_cast
    int i = std::any_cast<int>(a1);
    std::cout << i << std::endl;

    a1.reset();
    std::cout << a1.has_value() << std::endl;
}