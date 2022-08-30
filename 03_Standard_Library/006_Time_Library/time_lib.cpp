//
// Created by Wuji Zhu on 30/8/2022.
//

#include <chrono>
#include <iostream>

void test_duration_count() {
    // minus between two time point will give a
    auto c1 = std::chrono::high_resolution_clock();
    std::cout << (c1.now() - c1.now()).count() << std::endl;

    auto t1 = c1.now(); //time_point<steady_clock, duration<...>>
    auto v = vector<int>(100);
    auto t2 = c1.now();
    std::cout << (t2 - t1).count() << std::endl;


    typedef std::chrono::duration<int, std::ratio<1>> second;
    second one_sec(10);
    std::cout << one_sec.count() << std::endl;

};

void test_epoch() {
    //epoch is usually set to 1970.1.1.
    auto duration1 = std::chrono::high_resolution_clock().now().time_since_epoch(); //duration<long long, ratio<1,1000 000 000>>
    std::cout << duration1.count() << std::endl;
}

void test_clock_casting() {
    typedef std::chrono::duration<long long, std::ratio<1>> MySecondTick;
    MySecondTick aSecond(1);
    std::chrono::milliseconds milli(aSecond);
    std::cout << milli.count() << " ms\n";        // 1000 milli
    std::chrono::seconds seconds(aSecond);
    std::cout << seconds.count() << " sec\n";         // 1 sec
    std::chrono::minutes minutes(std::chrono::duration_cast<std::chrono::minutes>(aSecond));
    std::cout << minutes.count() << " min\n";         // 0 min
    typedef std::chrono::duration<double, std::ratio<2700>> MyLessonTick;
    MyLessonTick myLesson(aSecond);
    std::cout << myLesson.count() << " less\n";       // 0.00037037 less

    //
    std::chrono::hours hours(1);
    std::chrono::minutes m(hours);
    std::cout << m.count();
}