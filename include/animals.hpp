
#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>
#include <utility>

class Dog {
   private:
    std::string _name;
    std::string _sound;

   public:
    explicit Dog(std::string name)
        : _name(std::move(name)), _sound("bark-bark") {}
    const std::string& getName() const;
    const std::string& getSound() const;
};

#endif
