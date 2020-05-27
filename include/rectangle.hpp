#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdio>
#include <utility>

class Rectangle {
   public:
    Rectangle(int a, int b) : _a(a), _b(b) {}

    Rectangle(const Rectangle& lhs) = default;
    Rectangle& operator= (const Rectangle& rhs) = default;
    
    Rectangle(Rectangle&& rhs) noexcept {
        puts("move constructor");
        _a = rhs._a; //trivial type, no need to cal std::move expliclitly
        _b = rhs._b;
    }

    Rectangle& operator= (Rectangle&& rhs) noexcept {
        puts("move assignment operator");
        _a = rhs._a; //trivial type, no need to call std::move explicitly
        _b = rhs._b;
        return *this;
    }

    ~Rectangle() = default;

    int getArea();

   private:
    int _a;
    int _b;
};

#endif