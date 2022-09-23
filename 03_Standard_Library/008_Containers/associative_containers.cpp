//
// Created by Wuji Zhu on 6/9/2022.
//

#include <iostream>
#include <map>
#include <unordered_map>

class associative_container_test_class {
public:
    associative_container_test_class() {
        std::cout << "ORI" << std::endl;
    };

    associative_container_test_class(const associative_container_test_class& other) {
        std::cout << "CPY" << std::endl;
    }

    associative_container_test_class(associative_container_test_class&& other) noexcept {
        std::cout << "MOV" << std::endl;
    }

    associative_container_test_class& operator= (const associative_container_test_class& other) {
        std::cout << "CPY_ASSIGN" << std::endl;
        return *this;
    }

    ~associative_container_test_class() {
        std::cout << "DEL" << std::endl;
    }
};


//bool operator< (const associative_container_test_class& a1, const associative_container_test_class& a2) {
//    return true;
//}

void test_map() {
    // 1. self defined class for key needs to support `operator<`

    //std::map<associative_container_test_class, int> bin;
    //associative_container_test_class key1;
    //bin[key1] = 1;


    // 2. moving objects into map
    std::map<int, associative_container_test_class> bin;

    //normal insert --> copy
    associative_container_test_class cls1, cls2, cls3, cls4, cls5, cls6;

    std::cout << "bin[1] = cls;\n";
    bin[1] = cls1;
    std::cout << "bin.insert({2, cls2});\n";
    bin.insert({2, cls2});
    std::cout << "bin[3] = std::move(cls3);\n";
    bin[3] = std::move(cls3);
    std::cout << "bin.insert(std::make_pair(4, std::move(cls4)));\n";
    bin.insert(std::make_pair(4, std::move(cls4)));
    std::cout << "bin.insert({5, std::move(cls5)});\n";
    std::pair<const int, associative_container_test_class> pir(5, std::move(cls5));
    //bin.insert({5, std::move(cls5)});
    /**
     * Most likely because the value type of your map is pair<int const, Node>, not pair<int, Node>: in a map, the key is constant.
       Since insert() accepts a pair<int const, Node> const& and you supply a pair<int, Node>, to perform the conversion
       a temporary must be constructed from which the value in the map can in turn be copy-constructed.
       To verify it, change this line:
        pair<int, Node> toInsert = pair<int, Node>(2, node2);
     * */
    std::cout << "---\n";
    bin.insert(pir);
    std::cout << "---\n";

    std::pair<const int, associative_container_test_class> pir2(5, std::move(cls6));
    //bin.insert({5, std::move(cls6)});
    bin.insert(pir2);

    //key not found
    //std::cout << "bin.at(6);\n";
    //bin.at(6);

    std::cout << "bin[6]\n";
    bin[6];

    //associative_container_test_class cls1 = bin[2];

    // 3. Check how map iterator forward work
    std::cout << "Map Iterator Forward Start --------------------------\n";
    std::map<int, string> bin_int;
    bin_int.insert(std::make_pair(1, "One"));
    bin_int.insert(std::make_pair(2, "Two"));
    auto itr = bin_int.find(2);

    std::cout << (itr++)->first << " ||| " << (itr==bin_int.end()) <<std::endl;
    itr = bin_int.find(1);
    std::cout << (--itr)->first << std::endl;
    std::cout << "Map Iterator Forward End ----------------------------\n";
};

class unordered_test_cls: public associative_container_test_class {
public:
    string s;

    unordered_test_cls() = default;

    unordered_test_cls(const unordered_test_cls& other): s(other.s) {
        std::cout << " child CPY" << std::endl;
    }

    unordered_test_cls(unordered_test_cls&& other) noexcept: s(std::move(other.s)) {
        std::cout << " child MOV" << std::endl;
    }

    bool operator== (const unordered_test_cls& other) const {
        return s == other.s;
    }
};

class unordered_test_cls_hash {
public:

    std::size_t operator() (const unordered_test_cls& other) const {
        std::hash<string> hashVal;
        return hashVal(other.s);

    }
};



void test_unordered_map() {
    std::unordered_map<unordered_test_cls, int, unordered_test_cls_hash> bin;

    std::pair<unordered_test_cls, int> pir(unordered_test_cls(), 1);
    std::cout << "------------\n";
    bin.insert(pir);

    associative_container_test_class cls1, cls2, cls3, cls4, cls5, cls6;
    std::pair<const int, associative_container_test_class> pir1(1, cls1);
    std::pair<const int, associative_container_test_class> pir2(2, std::move(cls2));

    std::cout << "--------------------Unordered_map_test----------------\n";
    std::unordered_map<int, associative_container_test_class> bin1;

    std::cout << "bin1.insert(pir1);" << std::endl;
    bin1.insert(pir1);
    std::cout << bin1.bucket_count() << " " << bin1.load_factor() << std::endl;
    std::cout << "bin1.insert(pir2);" << std::endl;
    bin1.insert(pir2);
    std::cout << bin1.bucket_count() << " " << bin1.load_factor() << std::endl;

    //note that when bin resize is triggerred, it will not reconstruct any object
    std::cout << "bin1.insert({3, std::move(cls3)});" << std::endl;
    bin1.insert({3, std::move(cls3)});
    std::cout << bin1.bucket_count() << " " << bin1.load_factor() << std::endl;
    std::cout << "--------------------Unordered_map_test_end----------------\n";

    //check merge
    std::cout << "--------------------check merge----------------\n";
    std::unordered_map<int, associative_container_test_class> bin3;
    bin3.insert({4, std::move(cls4)});
    std::cout << "--------------------check merge----------------\n";
    bin1.merge(bin3);
    std::cout << "--------------------check merge end----------------\n";

}

void test_unordered_multimap() {
    std::unordered_multimap<int, int> bin;
    bin.insert(std::make_pair(1,1));
    bin.insert(std::make_pair(1,3));
    bin.insert(std::make_pair(1,2));


    auto itr = bin.find(1);
    while (itr != bin.end()) {
        std::cout << itr->second << std::endl;
        ++itr;
    }
}