//
// Created by Wuji Zhu on 31/8/2022.
//

#include <optional>
#include <iostream>

class optional_test_class {
public:
    int num1, num2;
    optional_test_class() =  default;
    optional_test_class(int n1, int n2): num1(n1), num2(n2) {}
    optional_test_class(const optional_test_class& other): num1(other.num1), num2(other.num2) {
        std::cout << "CPY" << std::endl;
    }
    optional_test_class(optional_test_class&& other): num1(other.num1), num2(other.num2) {
        std::cout << "MOV" << std::endl;
    }
};

void test_optional() {
    //has_value
    std::optional<int> opt_i;
    std::cout << opt_i.has_value() << std::endl;

    std::optional<int> opt_i2(1);
    std::cout << opt_i2.has_value() << std::endl;

    //reset, emplace
    opt_i.emplace(1);
    opt_i2.reset();
    std::cout << opt_i.has_value() << std::endl;
    std::cout << opt_i2.has_value() << std::endl;

    //if it is created within container, move constructor is called
    optional_test_class optc(1,2);
    std::optional<optional_test_class> opt_cls(optional_test_class(1,2));
    std::optional<optional_test_class> opt_cls2(optc);

    //value
    std::cout << opt_i.value() << " " << opt_i2.value_or(123);

}