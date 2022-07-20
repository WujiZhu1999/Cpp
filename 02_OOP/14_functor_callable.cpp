//
// Created by Wuji Zhu on 21/7/2022.
//

#include <iostream>
#include <string>

class doubler{
public:
    int operator() (int x) {
        return 2*x;
    }

    std::string operator() (std::string s) {
        return s+s;
    }

    int operator() (int x, int y) {
        return 2*x + 2*y;
    }
};

void test_callable(){
    doubler d;
    std::cout << d(1) << std::endl;
    std::cout << d("A") << std::endl;
    std::cout << d(1,2) << std::endl;
}