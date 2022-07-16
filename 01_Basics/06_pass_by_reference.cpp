//
// Created by Wuji Zhu on 16/7/2022.
//

#include <iostream>
#include <vector>

using namespace std;

void pass_by_reference(int &x) {
    ++x;
}

void pass_by_value(int x) {
    ++x;
}

void vector_default_value(vector<int> bin) {
    bin[0] = 1;
}

void array_default_reference(int bin[]) {
    bin[0] = 1;
}

void test_pass_by_reference_value_difference(){
    int x = 1;
    cout << x << " " << endl;
    pass_by_value(x);
    cout << x << " " << endl;
    pass_by_reference(x);
    cout << x << " " << endl;

    cout << "------vector------" << endl;
    vector<int> bin = {0};
    vector_default_value(bin);
    cout << bin[0] << endl;

    cout << "------array------" << endl;
    int b[1] = {0};
    array_default_reference(b);
    cout << b[0] << endl;


}