//
// Created by Wuji Zhu on 18/8/2022.
//

#include <iostream>

class MOVE_TEST{
public:
    MOVE_TEST(): MOVE_TEST(0) {}
    MOVE_TEST(int num): value(num) {}

    MOVE_TEST& operator = (MOVE_TEST& other) {
        this->value = other.value;
        std::cout << "copy" << std::endl;
        return *this;
    }

    MOVE_TEST& operator = (MOVE_TEST&& other) {
        if (this != &other){
            this->value = other.value;
        }
        std::cout << "move" << std::endl;
        return *this;
    }

    int value;
};

void test_access_object_after_move() {
    MOVE_TEST a(0);
    MOVE_TEST b;
    b = std::move(a);
    std::cout << &a.value << " " << &b.value << std::endl;
    a.value = 1;
    std::cout << a.value;
}

void test_access_primitives_after_move() {
    std::cout << "STRING ------------------------------------------------------------\n";
    string s, d;
    s = "abc";

    std::cout << "S before: " << s << std::endl;
    std::cout << "D before: " << d << std::endl;
    d = std::move(s);

    std::cout << "S after: " << s << std::endl;
    std::cout << "D after: " << d << std::endl;

    std::cout << "INT ------------------------------------------------------------\n";
    int si, di;
    si = 1;

    std::cout << "S before: " << si << std::endl;
    std::cout << "D before: " << di << std::endl;
    di = std::move(si);

    std::cout << "S after: " << si << std::endl;
    std::cout << "D after: " << di << std::endl;



}
