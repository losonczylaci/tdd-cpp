#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <stdexcept>

class Int {
   private:
    int _value = 0;

   public:
    Int(int value) : _value(value) {}  // NOLINT

    int getValue() const { return _value; }
    void setValue(int value) { _value = value; }
};

Int operator+(const Int& lhs, const Int& rhs);
Int operator-(const Int& lhs, const Int& rhs);
Int operator*(const Int& lhs, const Int& rhs);
Int operator/(const Int& lhs, const Int& rhs);

bool operator==(const Int& lhs, const Int& rhs);
bool operator!=(const Int& lhs, const Int& rhs);
#endif
