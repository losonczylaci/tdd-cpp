#include <utility>
#include <gtest/gtest.h>
#include <rectangle.hpp>

using namespace std;


TEST(test, test1) {
    Rectangle rect(1,2);
    Rectangle rectB = rect;
    ASSERT_EQ(2, rect.getArea());
    ASSERT_EQ(2, rectB.getArea());

    //move assignment
    rect = std::move(rectB);
    ASSERT_EQ(2, rect.getArea());
    
    // move contructor
    Rectangle movetor = move(rectB);
    ASSERT_EQ(2, rect.getArea());
};