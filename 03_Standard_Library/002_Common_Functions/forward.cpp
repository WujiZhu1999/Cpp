//
// Created by Wuji Zhu on 19/8/2022.
//

#include <iostream>

class FORWARD_INNER {
private:
    int x;
public:
    FORWARD_INNER() = default;
    FORWARD_INNER(int x): x(x) {}

    FORWARD_INNER(const FORWARD_INNER& other) {
        this->x = other.x;
        std::cout << "COPY" << std::endl;
    }

    FORWARD_INNER(FORWARD_INNER&& other) {
        this->x = other.x;
        std::cout << "MOVE" << std::endl;
    }
};

class FORWARD_OUTER {
private:
    FORWARD_INNER i;
public:
    /**
     * Use the one without forward will actually call COPY constructor since other converted to lvalue type.
     * */
    FORWARD_OUTER() = default;
    //FORWARD_OUTER(FORWARD_INNER&& other): i(other) {}
    FORWARD_OUTER(FORWARD_INNER&& other): i(std::forward<FORWARD_INNER>(other)) {}

};

void test_forward() {
    FORWARD_INNER i(1);
    FORWARD_OUTER(std::move(i));
}