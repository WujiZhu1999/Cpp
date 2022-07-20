//
// Created by Wuji Zhu on 20/7/2022.
//

#include <iostream>

class Demo {
public:

    int id;
    Demo() {
        this->id = 1;
        std::cout << "Default constructor get called" << std::endl;
    }

    Demo(int id): id(id) {
        std::cout << "This is not explicit constructor" << std::endl;
    }

    Demo(const Demo& demo) {
        this->id = demo.id;
        std::cout << "This is copy constructor" << std::endl;
    }

    Demo(Demo&& demo) {
        this->id = demo.id;
        std::cout << "This is move constructor" << std::endl;
    }

    Demo& operator= (Demo& demo) {
        this->id = demo.id;
        std::cout << "This is copy assign constructor" << std::endl;
        return *this;
    }

    Demo& operator= (Demo&& demo) {
        this->id = demo.id;
        std::cout << "This is move assign constructor" << std::endl;
        return *this;
    }
};

void use_copy(Demo demo){}
void use_ref(Demo& demo){}
void use_rv(Demo&& demo){}

void test_constructors() {
    std::cout << "-----1-----" << std::endl;
    Demo d1;
    std::cout << "-----2-----" << std::endl;
    Demo d2(1);
    std::cout << "-----3-----" << std::endl;
    Demo d3 = 1;
    std::cout << "-----4-----" << std::endl;
    Demo d4 = d1;
    std::cout << "-----5-----" << std::endl;
    Demo d5 = move(d2);
    std::cout << "-----6-----" << std::endl;
    d5 = d4;
    std::cout << "-----7-----" << std::endl;
    d5 = Demo();
    std::cout << "-----8-----" << std::endl;
    use_copy(d1);
    std::cout << "-----9-----" << std::endl;
    use_ref(d1);
    std::cout << "-----10----" << std::endl;
    use_rv(move(d2));
}

/**
 * About move constructor
 * */
#include <vector>
class TestDemo{
public:
    TestDemo(int num):num(num){}
    TestDemo(const TestDemo& other) :num(other.num) {
        std::cout << "copy " << this->num << std::endl;
    }

    TestDemo(TestDemo&& other) noexcept :num(other.num) {
        std::cout << "move " << this->num << std::endl;
    };
private:

    int num;
};

void test_move_constructor_vector(){
    std::vector<TestDemo> demo1{2,3};
    TestDemo test{1};
    demo1.push_back(test);
}

#include <vector>
class TestDemoNoCopy{
public:
    TestDemoNoCopy(int num):num(num){}
    TestDemoNoCopy(const TestDemoNoCopy& other) = delete;
    TestDemoNoCopy& operator= (TestDemoNoCopy& other) = delete;

    TestDemoNoCopy(TestDemoNoCopy&& other) noexcept :num(other.num) {
        std::cout << "move " << this->num << std::endl;
    };
private:

    int num;
};
/*
void test_no_copy_move_constructor_vector(){
    std::vector<TestDemoNoCopy> demo1;

    TestDemoNoCopy test{1};
    demo1.push_back(test);
}*/

