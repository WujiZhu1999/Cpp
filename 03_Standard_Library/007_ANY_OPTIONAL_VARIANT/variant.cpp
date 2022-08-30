//
// Created by Wuji Zhu on 31/8/2022.
//

#include <variant>
#include <iostream>

void test_variant() {
    std::variant<bool ,int, float, int, double> v;

    //get
    std::cout << std::get<0>(v) << std::endl;
    //std::cout << std::get<float>(v) << std::endl;   contains int not float will throw

    //emplace
    v.emplace<float>(0.0);
    std::cout << std::get<float>(v) << std::endl;

    v.emplace<0>(123);
    std::cout << std::get<0>(v) << std::endl;

    //holds_alternative
    std::cout << std::holds_alternative<float>(v) << std::endl;
    //std::cout << std::holds_alternative<int>(v) << std::endl; compile error, int occur more than once.
    std::cout << std::holds_alternative<double>(v) << std::endl;
    std::cout << std::holds_alternative<bool>(v) << std::endl; // 1 since this is default

    //std::get_if
    v.emplace<0>(true);
    std::cout << std::get_if<double>(&v) << std::endl;
    v.emplace<4>(0.0);
    std::cout << std::get_if<double>(&v) << std::endl;

    //index
    std::cout << v.index();
}