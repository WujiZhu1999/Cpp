//
// Created by Wuji Zhu on 14/8/2022.
//

#include "common_namespace_2.h"
#include <iostream>

using namespace std;

void common_namespace::func2() {
    std::cout << "common_namespace_2-->common_namespace_func2()" << std::endl;
}

/*
void common_namespace::common_func() {
    std::cout << "common_function()--from common_namespace_2";
}*/