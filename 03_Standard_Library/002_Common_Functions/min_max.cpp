//
// Created by Wuji Zhu on 18/8/2022.
//

#include <iostream>

class MIN_MAX_NUMBER {
private:
    int num;
public:

    bool operator < (const MIN_MAX_NUMBER& other) const {
        return this->num < other.num;
    }

    friend std::ostream& operator << (std::ostream& os, const MIN_MAX_NUMBER& self);

    MIN_MAX_NUMBER(): MIN_MAX_NUMBER(0) {}
    MIN_MAX_NUMBER(int num): num(num){}
    MIN_MAX_NUMBER(const MIN_MAX_NUMBER& other): num(other.num) {
        //std::cout << "COPY" << std::endl;
    }

    MIN_MAX_NUMBER(MIN_MAX_NUMBER&& other) noexcept :num(other.num) {
        std::cout << "MOVE" << std::endl;
    }

    MIN_MAX_NUMBER& operator = (const MIN_MAX_NUMBER& other) {
        this->num = other.num;
        return *this;
    }

};

std::ostream& operator << (std::ostream& os, const MIN_MAX_NUMBER& self) {
    os << self.num;
    return os;
}

void test_min_max() {
    MIN_MAX_NUMBER a = 1, b = 2, c = 3;
    std::cout << "a: 1, b: 2, c: 3" << std::endl;
    std::cout << "std::min(a, b): " << std::min(a, b) << endl;
    std::cout << "std::max(a, b): " << std::max(a, b) << endl;
    std::cout << "std::max(bin: {a, b, c}): " << std::min({a, b, c}) << endl;
    std::cout << "std::minmax(bin: {a, b, c}): min: " << std::minmax({a, b, c}).first << " max: " << std::minmax({a, b, c}).second << endl;

    std::cout << "std::min(bin: {a, b, c}, comparator: a.num > b.num): "
    << std::min({a, b, c}, [](MIN_MAX_NUMBER x, MIN_MAX_NUMBER y) {return not(x < y);}) << endl;

}