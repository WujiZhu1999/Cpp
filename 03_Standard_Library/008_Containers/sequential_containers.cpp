//
// Created by Wuji Zhu on 2/9/2022.
//

#include <iostream>
#include <array>
#include <list>


class sequential_container_test_class {
public:
    sequential_container_test_class() {
        std::cout << "ORI" << std::endl;
    };

    sequential_container_test_class(const sequential_container_test_class& other) {
        std::cout << "CPY" << std::endl;
    }

    sequential_container_test_class(sequential_container_test_class&& other) noexcept {
        std::cout << "MOV" << std::endl;
    }

    sequential_container_test_class& operator= (const sequential_container_test_class& other) {
        std::cout << "CPY_ASSIGN" << std::endl;
        return *this;
    }

    ~sequential_container_test_class() {
        std::cout << "DEL" << std::endl;
    }
};

void test_array() {
    std::array<int, 10> arr;
    std::cout << arr[0] << " " << arr[5] << std::endl;
    std::cout << arr.size() << " " << arr.max_size();
}

void test_vector() {
    // default create will create n objects
    std::vector<sequential_container_test_class> vec(10);
    std::cout << vec.size() << " " << vec.capacity() << std::endl;

    //push_back will cause expansion and objects will move by MOVE constructor
    vec.push_back(sequential_container_test_class());
    std::cout << vec.size() << " " << vec.capacity() << std::endl;

    // resize (if there is insufficient objects, push that many objects to the back)
    std::vector<sequential_container_test_class> vec1;
    std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
    vec1.resize(10);
    std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
    vec1.resize(10);
    std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
    vec1.resize(11);
    std::cout << vec1.size() << " " << vec1.capacity() << std::endl;

    // resize to smaller
    vec1.resize(10);
    std::cout << vec1.size() << " " << vec1.capacity() << std::endl;

    // insert
    std::cout << "------------------INSERT------------------------\n";
    std::vector<sequential_container_test_class> vec2(3);
    vec2.push_back(sequential_container_test_class());
    auto t = sequential_container_test_class();
    vec2.insert(vec2.begin(), t);
    std::cout << std::endl;

    // reserve
    std::cout << "------------------REVERSE------------------------\n";
    vec2.reserve(100);
    vec2.reserve(50);
    std::cout << vec2.capacity() << std::endl;

    //shrink to fit
    std::cout << "------------------shrink_to_fit------------------------\n";
    vec2.shrink_to_fit();
    std::cout << vec2.capacity() << std::endl;

    //insert in the middle
    std::cout << "------------------insert_at_middle------------------------\n";
    std::vector<sequential_container_test_class> vec3(5);
    vec3.reserve(6);
    vec3.insert(vec3.end(), sequential_container_test_class());
    std::cout << "------------------end-------------------------------------\n";

}

void test_list() {

    //advance
    std::list<int> bin1;
    bin1.push_back(1);
    bin1.push_back(2);
    bin1.push_back(3);
    bin1.push_back(4);
    std::list<int>::iterator itr = bin1.begin();
    std::advance(itr, 3);
    std::advance(itr, -2);
    std::cout << *itr << std::endl;


    std::list<sequential_container_test_class> lis1, lis2;
    lis1.push_back(sequential_container_test_class());
    lis2.push_back(sequential_container_test_class());

    //lis1.merge(lis2); fail cause there is no < operator defined
    lis1.merge(lis2, [](sequential_container_test_class& a, sequential_container_test_class&b) {return 1;});


}