#include <gtest/gtest.h>
#include <boost/hana.hpp>

template <int _a, int _b>
struct Rectangle {
    int a = _a;
    int b = _b;
    int permiter = (a + b) * 2;
    int area = a * b;
};

TEST(tmpGroup, testRectangle) {
    Rectangle<2, 4> rect;
    EXPECT_EQ(rect.a, 2);
    EXPECT_EQ(rect.b, 4);
    EXPECT_EQ(rect.permiter, 12);
    EXPECT_EQ(rect.area, 8);
}

template <int toCube>
struct Cube {
    enum { value = toCube * toCube * toCube };
};

TEST(tmpGroup, testCube) {
    EXPECT_EQ(27, Cube<3>::value);
    EXPECT_EQ(125, Cube<5>::value);
}

template <int input, int sum = 1>
struct Factorial : Factorial<input - 1, input * sum> {};

template <int sum>
struct Factorial<1, sum> {
    enum { value = sum };
};

TEST(tmpGroup, testFactorial) {
    EXPECT_EQ(24, Factorial<4>::value);
}

namespace hana = boost::hana;
using namespace hana::literals;
using namespace std;

struct Truck {
    string name;
    double bed_length;
};

struct Car {
    string name;
};

struct Motorcycle {
    string name;
};

TEST(tmpGroup, test) {
    auto vehicles = hana::make_tuple(Truck{"F-150", 8.5}, Car{"Volt"}, Motorcycle{"Ninja"});

    auto has_bed_length = hana::is_valid([](auto&& x) -> decltype((void)x.bed_length) {});
    auto has_no_bed_length = hana::compose(hana::not_, has_bed_length);

    auto trucks = hana::filter(vehicles, has_bed_length);
    auto nontrucks = hana::filter(vehicles, has_no_bed_length);
}

template <int input, int result = 1>
struct Fibonacci : Fibonacci<input - 1, result + input> {};

template <int n>
struct Fibonacci<n> {
    enum { value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value };
};

template <>
struct Fibonacci<0> {
    enum { value = 0 };
};

template <>
struct Fibonacci<1> {
    enum { value = 1 };
};

TEST(tmpGroup, fibonacci) {
    EXPECT_EQ(1, Fibonacci<1>::value);
    EXPECT_EQ(1, Fibonacci<2>::value);
    EXPECT_EQ(2, Fibonacci<3>::value);
    EXPECT_EQ(3, Fibonacci<4>::value);
}
