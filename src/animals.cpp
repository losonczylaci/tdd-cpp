#include <animals.hpp>

const std::string& Dog::getName() const { return _name; }
const std::string& Dog::getSound() const { return _sound; }
void Dog::saySomething() const { std::cout << _sound << std::endl; }
