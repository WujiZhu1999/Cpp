//
// Created by Wuji Zhu on 22/8/2022.
//

#include <memory>

class unique_ptr_test_object {

public:
    int num;

    unique_ptr_test_object() = default;

    unique_ptr_test_object(int num): num(num) {
        std::cout << num << "get constructed" << std::endl;
    }

    ~unique_ptr_test_object() {
        std::cout << num << "get deleted" << std::endl;
    }
};

void test_unique_pointer() {
    unique_ptr<unique_ptr_test_object> ptr_0 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(0));
    {
        unique_ptr<unique_ptr_test_object> ptr_1 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(1));
    }

    /**
    unique_ptr_test_object obj_2(2);
    auto ptr_2 = unique_ptr<unique_ptr_test_object>(&obj_2);

    Cpp(2068,0x103098580) malloc: *** error for object 0x16d0737cc: pointer being freed was not allocated
    Cpp(2068,0x103098580) malloc: *** set a breakpoint in malloc_error_break to debug
    */
};

void test_unique_pointer_1() {
    //reset
    unique_ptr<unique_ptr_test_object> ptr_0 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(0));
    ptr_0.reset(new unique_ptr_test_object(-1));

    //release
    unique_ptr<unique_ptr_test_object> ptr_1 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(1));
    unique_ptr_test_object* ptr_1_ptr = ptr_1.release();
    delete ptr_1_ptr;

    //move constructor
    unique_ptr<unique_ptr_test_object> ptr_2 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(2));
    unique_ptr<unique_ptr_test_object> ptr_2_mov;
    std::cout << "ptr_2 " << ptr_2.get() << std::endl;
    std::cout << "ptr_2_mov " << ptr_2_mov.get() << std::endl;

    //ptr_2_mov = ptr_2; error
    ptr_2_mov = std::move(ptr_2);
    std::cout << "ptr_2 " << ptr_2.get() << std::endl;
    std::cout << "ptr_2_mov " << ptr_2_mov.get() << std::endl;

    //swap
    unique_ptr<unique_ptr_test_object> ptr_3 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(3));
    unique_ptr<unique_ptr_test_object> ptr_4 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(4));

    std::cout << "ptr_3 " << ptr_3.get() << std::endl;
    std::cout << "ptr_4 " << ptr_4.get() << std::endl;

    std::swap(ptr_3, ptr_4);
    std::cout << "ptr_3 " << ptr_3.get() << std::endl;
    std::cout << "ptr_4 " << ptr_4.get() << std::endl;
}

void test_unique_pointer_2() {
    //self defined delete
    auto ptr_0 = unique_ptr<unique_ptr_test_object, void(*)(unique_ptr_test_object*)>(
            new unique_ptr_test_object(0),[](unique_ptr_test_object* ptr) {
                std::cout << "self defined delete" << std::endl;
                delete ptr;
            });

    // *, ->
    auto ptr_1 = unique_ptr<unique_ptr_test_object>(new unique_ptr_test_object(1));
    std::cout << (*ptr_1).num << ptr_1->num << std::endl;

    //[]
    auto ptr_list = unique_ptr<unique_ptr_test_object[]>(new unique_ptr_test_object[5]);
    std::cout << ptr_list[0].num << std::endl;
}