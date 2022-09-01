//
// Created by Wuji Zhu on 31/8/2022.
//

#include <vector>
#include <iostream>

class test_general_container_cls {
public:
    test_general_container_cls() = default;
    test_general_container_cls(const test_general_container_cls& other) {
        std::cout << "CPY" << std::endl;
    }

    test_general_container_cls(test_general_container_cls&& other) {
        std::cout << "MOV" << std::endl;
    }

};

void test_general_container() {
    std::vector<test_general_container_cls> v1(3);
    std::vector<test_general_container_cls> v2(v1.begin(), v1.end());

    std::cout << &v1[0] << " " << &v2[0] << std::endl;


    std::vector<test_general_container_cls> v3 = std::move(v1);
    std::cout << &v3[0];

    std::cout << &v1[1];
}

void test_general_begin_end() {
    std::vector<int> bin= {1,2,3};
    std::cout << *(bin.begin());
    cout << std::endl;

    std::vector<int> intVec;
    intVec.assign({1, 2, 3});
    for (auto v: intVec) std::cout << v << " ";        // 1 2 3
    cout << std::endl;

    intVec.insert(intVec.begin(), 0);
    for (auto v: intVec) std::cout << v << " ";        // 0 1 2 3
    cout << std::endl;

    intVec.insert(intVec.begin()+4, 4);
    for (auto v: intVec) std::cout << v << " ";        // 0 1 2 3 4
    cout << std::endl;

    intVec.insert(intVec.end(), {5, 6, 7, 8, 9, 10, 11});

    for (auto v: intVec) std::cout << v << " ";        // 0 1 2 3 4 5 6 7 8 9 10 11
    cout << std::endl;

    for (auto revIt= intVec.rbegin(); revIt != intVec.rend(); ++revIt)
        std::cout << *revIt << " ";                   // 11 10 9 8 7 6 5 4 3 2 1 0
    cout << std::endl;

    intVec.pop_back();
    for (auto v: intVec ) std::cout << v << " ";       // 0 1 2 3 4 5 6 7 8 9 10
    cout << std::endl;
}

void test_general_swap() {
    vector<int> b1, b2;
    b1.emplace_back(1);
    b2.emplace_back(2);

    std::cout << &b1[0] << " " << &b2[0] << std::endl;
    std::swap(b1, b2);
    std::cout << &b1[0] << " " << &b2[0] << std::endl;
}