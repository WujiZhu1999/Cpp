//
// Created by Wuji Zhu on 20/7/2022.
//
#include "11_header.h"
#include <iostream>
Header::Header(): Header(0,0) {}
Header::Header(int x): Header(x, 0) {}
Header::Header(int x, int y): x(x), y(y) {}

int Header::sum() {
    return x+y;
}

int Header::diff() {
    return x-y;
}

void Header::toString() {
    std::cout << sum() << " " << diff();
}