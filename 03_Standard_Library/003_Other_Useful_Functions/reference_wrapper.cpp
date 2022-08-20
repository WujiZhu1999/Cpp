//
// Created by Wuji Zhu on 20/8/2022.
//
#include <iostream>
#include <functional>
#include <vector>

class reference_wrapper_test_class{
public:
    int x;
    reference_wrapper_test_class() = default;
    reference_wrapper_test_class(const reference_wrapper_test_class& other) {
        std::cout << "copy" << std::endl;
    }
    reference_wrapper_test_class(reference_wrapper_test_class&& other) noexcept {
        std::cout << "move" << std::endl;
    }
};

template<typename T>
void functest(T a) {
    ++a.get();
}

void test_reference_wrapper() {
    int a = 1;
    int &b = a;
    std::cout << "a address: " << &a << std::endl;
    std::cout << "b address: " << &b << std::endl;

    std::cout << "a before functest: " << a << std::endl;
    //functest(a);
    //functest(b);
    functest(std::ref(a));
    std::cout << "a after  functest: " << a << std::endl;
}

void myAdd(int a, int b, int &r) {
    r = a + b;
}

void test_reference_wrapper_2(){
    int result = 0;
    auto f = std::bind(myAdd, std::placeholders::_1, 20, result);
    f(10);
    std::cout << "result after  myAdd: " << result << std::endl;
}

void test_reference_wrapper_3() {
    reference_wrapper_test_class a{};
    reference_wrapper_test_class b{};
    reference_wrapper_test_class a_ref{};
    reference_wrapper_test_class b_ref{};

    vector<reference_wrapper_test_class> bin;
    bin.push_back(a);
    bin.push_back(b);
    std::cout << "a: " << &a << std::endl;
    std::cout << "b: " << &b << std::endl;
    std::cout << "a in vector: " << &(bin[0]) << std::endl;
    std::cout << "b in vector: " << &(bin[1]) << std::endl;

    vector<std::reference_wrapper<reference_wrapper_test_class>> bin_ref;
    bin_ref.push_back(std::ref(a_ref));
    bin_ref.push_back(std::ref(b_ref));
    std::cout << "a_ref: " << &(a_ref) << std::endl;
    std::cout << "b_ref: " << &(b_ref) << std::endl;
    std::cout << "a_ref in vector: " << &(bin_ref[0].get()) << std::endl;
    std::cout << "b_ref in vector: " << &(bin_ref[1].get()) << std::endl;

}