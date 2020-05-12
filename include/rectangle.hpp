#pragma once

class Rectangle {

public:
    Rectangle(int a, int b) : m_a(a), m_b(b) {}

    int getArea();
private:
    int m_a;
    int m_b;
};
