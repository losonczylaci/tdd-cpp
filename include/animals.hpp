
#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>
#include <utility>

class Dog {
   private:
    std::string _name;

   public:
    explicit Dog(std::string name) : _name(std::move(name)) {}
    const std::string& getName() const;
};

#endif
