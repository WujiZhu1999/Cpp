//
// Created by Wuji Zhu on 20/7/2022.
//
#include <iostream>
class diamond_base {
public:
    int id;
    diamond_base() = default;
    diamond_base(int id): id(id) {
        std::cout << "diamond base called" << std::endl;
    }
};

class diamond_lvl1_a: public diamond_base {
public:
    diamond_lvl1_a() = default;
    diamond_lvl1_a(int id): diamond_base(id) {
        std::cout << "lvl1_a called" << std::endl;
    }
};

class diamond_lvl1_b: public diamond_base {
public:
    diamond_lvl1_b() = default;
    diamond_lvl1_b(int id): diamond_base(id) {
        std::cout << "lvl1_a called" << std::endl;
    }
};

class diamond_lvl2_a: public diamond_lvl1_a, public diamond_lvl1_b {
public:
    diamond_lvl2_a(int idx) {
        this->diamond_lvl1_b::id = 0;
        this->diamond_lvl1_a::id = 0;
    }
};

void test_diamond(){
    diamond_lvl2_a a(1);
}