//
// Created by Wuji Zhu on 14/8/2022.
//
#include <iostream>

namespace namespace_1 {
    void print_name() {
        std::cout << "name_space_1_print_name()" << endl;
    }
}

namespace namespace_2 {
    void print_name() {
        std::cout << "name_space_2_print_name()" << endl;
    }
}

namespace namespace_3 {
    namespace namespace_3_1 {
        void print_name() {
            std::cout << "name_space_3_1_print_name()" << endl;
        }
    }
}