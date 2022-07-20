//
// Created by Wuji Zhu on 20/7/2022.
//

#include <iostream>
#include <string>

class AAA{
};

class Number{

public:
    int x;
    Number() = default;
    Number(int x): x(x) {}

    Number operator+(int y) {
        this->x += y;
        return *this;
    }

    void operator+=(int y) {
        this->x += y;
    }

    Number& operator+(std::string s) {
        this->x += s.size();
        return *this;
    }

    explicit operator AAA() {
        return AAA();
    }

    explicit operator bool() {
        return true;
    }

    explicit operator int() {
        return this->x;
    }

};

void test_operator_override() {
    Number a(1), b(1), c(1);

    (a + 1) = b;
    std::cout << a.x << std::endl;

    (a + "1") = b;
    std::cout << a.x << std::endl;

    /**
     * For the first one we do not return the reference, so change will not affect.
     * For the second one we return the reference.
     * */
}

void test_type_conversion() {
    Number n;
    AAA aaa(n);
    AAA bbb = (AAA) n;
    if (n) {
        std::cout << "convert to bool" << endl;
    }

    std::cout << int(n);
}