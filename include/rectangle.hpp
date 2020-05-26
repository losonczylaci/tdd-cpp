#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdio>
#include <utility>

class Rectangle {
   public:
    Rectangle(int a, int b) : m_a(a), m_b(b) {}

    Rectangle(const Rectangle& lhs) = default;
    Rectangle& operator= (const Rectangle& rhs) = default;
    
    Rectangle(Rectangle&& rhs) noexcept {
        puts("move constructor");
        m_a = rhs.m_a; //trivial type, no need to cal std::move expliclitly
        m_b = rhs.m_b;
    }

    Rectangle& operator= (Rectangle&& rhs) noexcept {
        puts("move assignment operator");
        m_a = rhs.m_a; //trivial type, no need to call std::move explicitly
        m_b = rhs.m_b;
        return *this;
    }

    ~Rectangle() = default;

    int getArea();

   private:
    int m_a;
    int m_b;
};

#endif