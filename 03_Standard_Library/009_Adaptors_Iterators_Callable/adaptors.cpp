//
// Created by Wuji Zhu on 9/9/2022.
//

#include <stack>
#include <iostream>
#include <queue>
#include <memory>

class adaptor_test_class {
public:
    adaptor_test_class() {
        std::cout << "ORI" << std::endl;
    };

    adaptor_test_class(const adaptor_test_class& other) {
        std::cout << "CPY" << std::endl;
    }

    adaptor_test_class(adaptor_test_class&& other) noexcept {
        std::cout << "MOV" << std::endl;
    }

    adaptor_test_class& operator= (const adaptor_test_class& other) {
        std::cout << "CPY_ASSIGN" << std::endl;
        return *this;
    }

    ~adaptor_test_class() {
        std::cout << "DEL" << std::endl;
    }
};

void test_stack() {
    std::stack<adaptor_test_class> bin1;
    adaptor_test_class cls1, cls2, cls3;
    bin1.push(cls1);
    bin1.push(std::move(cls2));

    std::cout << "-------------------------\n";
    std::vector<adaptor_test_class> vec1(2);
    std::vector<adaptor_test_class> vec2(2);
    std::cout << "-------------------------\n";
    std::stack<adaptor_test_class, std::vector<adaptor_test_class>> bin2(std::move(vec1));
    std::cout << "-------------------------\n";
    std::stack<adaptor_test_class, std::vector<adaptor_test_class>> bin3(vec2);
    std::cout << "-------------------------\n";
    bin2.push(cls3); //it still follows the underlying logic of vector
    std::cout << "-------------------------\n";
}

void test_queue() {

    adaptor_test_class cls1, cls2, cls3;
    std::vector<adaptor_test_class> vec1;
    vec1.reserve(2);
    std::cout << "-------------------------\n";
    std::queue<adaptor_test_class, std::vector<adaptor_test_class>> bin1(std::move(vec1));
    bin1.push(cls1);
    bin1.push(cls2);
    //just cpy since still have enough reserve space
    bin1.push(cls3);

    //bin1.pop(); error, cannot pop since vector do not support pop front
    std::cout << "-------------------------\n";

}

struct myInt {
    int idx, val;
    myInt(int idx, int val): idx(idx), val(val) {
        std::cout << "ORI " << idx << std::endl;
    }
    myInt(): myInt(0, 0) {}

    myInt(const myInt& other): idx(other.idx), val(other.val) {
        std::cout << "CPY " << idx << std::endl;
    }

    myInt(myInt&& other) noexcept : idx(other.idx), val(other.val) {
        std::cout << "MOV " << idx << std::endl;
    }

    myInt& operator= (const myInt& other) {
        this->idx = other.idx;
        this->val = other.val;
        return *this;
    }
};

void test_priority_queue() {
    std::vector<std::shared_ptr<myInt>> vec{
        shared_ptr<myInt>(new myInt(0,1)),
        shared_ptr<myInt>(new myInt(1,2)),
        shared_ptr<myInt>(new myInt(2,0))
    };
    auto comp = [] (const std::shared_ptr<myInt>& a, const std::shared_ptr<myInt>& b) {
        return a->val < b->val;
    };

    std::priority_queue<std::shared_ptr<myInt>, std::vector<std::shared_ptr<myInt>>, decltype(comp)> pri(comp, std::move(vec));
    std::shared_ptr<myInt> ptr = pri.top();
    std::cout << ptr->val << std::endl;
    ptr->val = -1;
    std::cout << ptr->val << std::endl;
}