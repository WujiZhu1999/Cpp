//
// Created by Wuji Zhu on 20/7/2022.
//

#ifndef CPP_11_HEADER_H
#define CPP_11_HEADER_H

class Header {
    int x;
    int y;

public:
    Header();
    Header(int x);
    Header(int x, int y);

    int sum();
    int diff();
    void toString();
};

#endif //CPP_11_HEADER_H
