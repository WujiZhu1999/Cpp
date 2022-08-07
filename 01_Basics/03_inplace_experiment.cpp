//
// Created by Wuji Zhu on 16/7/2022.
//

#include <iostream>

using namespace std;

void test_inplace() {
    int x = 1;
    int y = 1;
    cout << x << " " << &x << endl;
    x += 1;
    cout << x << " " << &x << endl;
    x = y + 1;
    cout << x << " " << &x << endl;
    x = x + 1;
    cout << x << " " << &x << endl;
}