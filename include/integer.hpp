#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Int {
   private:
    int _value = 0;

   public:
    Int(int value) : _value(value) {}  // NOLINT

    int getValue() const { return _value; }
    void setValue(int value) { _value = value; }
    operator std::string() const;  // NOLINT
    int operator()(int nr) const;
    Int& operator++();
    Int operator++(int);
};

Int operator+(const Int& lhs, const Int& rhs);
Int operator-(const Int& lhs, const Int& rhs);
Int operator*(const Int& lhs, const Int& rhs);
Int operator/(const Int& lhs, const Int& rhs);

bool operator==(const Int& lhs, const Int& rhs);
bool operator!=(const Int& lhs, const Int& rhs);

std::ostream& operator<<(std::ostream& o, const Int& rhs);
#endif
