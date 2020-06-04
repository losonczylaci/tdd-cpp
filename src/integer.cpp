#include <integer.hpp>

Int::operator std::string() const { return std::to_string(_value); }

Int operator+(const Int& lhs, const Int& rhs) {
    return lhs.getValue() + rhs.getValue();
}

Int operator-(const Int& lhs, const Int& rhs) {
    return lhs.getValue() - rhs.getValue();
}

Int operator*(const Int& lhs, const Int& rhs) {
    return lhs.getValue() * rhs.getValue();
}

Int operator/(const Int& lhs, const Int& rhs) {
    if (rhs.getValue() == 0) {
        throw std::runtime_error("Division by zero exception");
    }
    return lhs.getValue() / rhs.getValue();
}

bool operator==(const Int& lhs, const Int& rhs) {
    return lhs.getValue() == rhs.getValue();
}

bool operator!=(const Int& lhs, const Int& rhs) {
    return lhs.getValue() != rhs.getValue();
}

std::ostream& operator<<(std::ostream& o, const Int& rhs) {
    o << rhs.getValue();
    return o;
}