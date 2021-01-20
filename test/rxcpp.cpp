#include <gtest/gtest.h>

#include <rxcpp/rx.hpp>

namespace Rx {
using namespace rxcpp;
using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::util;
}  // namespace Rx

#include <iostream>

TEST(rxCppGroup, createAnObservable) {
    std::vector<int> ages{9, 20, 13, 4, 5, 6, 10, 28, 19, 15, 60, 23, 47, 12, 19, 99};
    auto values = rxcpp::observable<>::iterate(ages)
                      .filter([](int age) { return age >= 21; })
                      .count()
                      .subscribe([](int count) { EXPECT_EQ(count, 5); });
}
