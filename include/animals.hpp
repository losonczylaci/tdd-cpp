
#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>
#include <utility>

class Animal {
   public:
    virtual ~Animal() = default;
    virtual void saySomething() const = 0;
};

class Dog : public Animal {
   private:
    std::string _name;
    std::string _sound;

   public:
    explicit Dog(std::string name)
        : _name(std::move(name)), _sound("bark-bark") {}
    const std::string& getName() const;
    const std::string& getSound() const;
    void saySomething() const override;
};

#endif
