#include <gtest/gtest.h>
#include <string>

template <typename T>
T maxOf(T a, T b) {
    return (a < b) ? b : a;
}

TEST(stlGroup, maxOfInt) {
    int i1 = 1, i2 = 2;
    EXPECT_EQ(2, maxOf<int>(i1, i2));
}

TEST(stlGroup, maxOfString) {
    std::string s1 = "s1", s2 = "s2";
    EXPECT_EQ("s2", maxOf<std::string>(s1, s2));
}

TEST(stlGroup, typeDeduction) {
    int i1 = 1, i2 = 2;
    std::string s1 = "s1", s2 = "s2";
    EXPECT_EQ(2, maxOf(i1, i2));
    EXPECT_EQ("s2", maxOf(s1, s2));
}

TEST(stlGroup, noTypeDeduction) {
    EXPECT_EQ(97, maxOf<int>('a', 2));
    EXPECT_EQ(2, maxOf<int>(1, 2.0));
    // EXPECT_EQ(97, maxOf('a', 2)); //won't compile
    // EXPECT_EQ(2, maxOf(1, 2.0)); //won't compile
}

template <typename T>
constexpr T pi(3.141592653589793238462);

TEST(stlGroup, stronglyTypesVariable) {
    float fpi = pi<float>;
    double dpi = pi<double>;
    EXPECT_NEAR(dpi, fpi, 0.0000001);
    // EXPECT_NEAR(dpi, fpi, 0.00000001); //would fail
}

template <typename T>
T areaOfCircle(T radius) {
    return radius * radius * pi<T>;
}

TEST(stlGroup, areaOfCircle) {
    auto area = areaOfCircle<double>(1.7842);
    EXPECT_NEAR(10, area, 0.001);
}
