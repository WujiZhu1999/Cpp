//
// Created by Wuji Zhu on 20/8/2022.
//

#include <functional>
#include <iostream>

void printAll(int i, double d, std::string s, float f) {
    std::cout << "INT: " << i << std::endl;
    std::cout << "DOUBLE: " << d << std::endl;
    std::cout << "STRING: " << s << std::endl;
    std::cout << "FLOAT: " << f << std::endl;
}



void test_bind() {
    printAll(1, 2.0, "abc", 1.2);
    std::cout << "SEPARATION LINE --------------------------------" << std::endl;
    std::function < void(int) > self_defined_print1 = std::bind(printAll, std::placeholders::_1, 3.0, "xyz", 1.23);
    self_defined_print1(1);

    std::cout << "SEPARATION LINE --------------------------------" << std::endl;
    auto self_defined_print2 = std::bind(printAll, std::placeholders::_1, 123.123, std::placeholders::_2, 1.23);
    self_defined_print2(2, "aaa");
}