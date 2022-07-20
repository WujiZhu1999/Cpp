//
// Created by Wuji Zhu on 20/7/2022.
//
#include <iostream>
class OnHeap {
public:
    ~OnHeap() = delete;
};

class OnStack {
public:
    void* operator new(std::size_t size) = delete;
};

class NormalDelete {
public:
    ~NormalDelete() {
        std::cout << "NormalDelete destructor get called" << std::endl;
    }
};

void test_heap_stack_delete(){
    OnHeap *onHeap = new OnHeap;
    //delete onHeap;

    //OnStack onStack = new OnStack;
    NormalDelete *normalDelete = new NormalDelete;
    delete normalDelete;
}