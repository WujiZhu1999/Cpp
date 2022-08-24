//
// Created by Wuji Zhu on 25/8/2022.
//

#include <iostream>
#include <memory>

class shared_from_this_class: public std::enable_shared_from_this<shared_from_this_class> {
public:
    ~shared_from_this_class() {
        std::cout << "deleted" << std::endl;
    }
};

void test_shared_ptr() {
    //use_count, unique
    std::shared_ptr<shared_from_this_class> ptr = std::shared_ptr<shared_from_this_class>(new shared_from_this_class);
    std::cout << ptr.use_count() << std::endl;
    std::cout << ptr.unique() << std::endl;
    std::cout << std::endl;

    //another reference --> one more count, not unique
    auto ptr2 = ptr;
    std::cout << ptr.use_count() << std::endl;
    std::cout << ptr.unique() << std::endl;
    std::cout << std::endl;

    //shared_from_this()
    auto ptr3 = (*ptr).shared_from_this();
    std::cout << ptr.use_count() << std::endl;
    std::cout << std::endl;

    //ptr when goes out of scope will get destroyed
    {
        auto ptr4 = ptr;
        std::cout << ptr.use_count() << std::endl;
        std::cout << std::endl;
    }
    std::cout << ptr.use_count() << std::endl;
    std::cout << std::endl;

    //reset will not change the object of other holder
    ptr3.reset();
    std::cout << ptr.use_count() << std::endl;
    std::cout << std::endl;

}