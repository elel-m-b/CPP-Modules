#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    // Dog a;
    // const int size = 4;
    // Animal *animals[size];

    // for (int i = 0; i < size; i++)
    // {
    //     if (i < size / 2)
    //         animals[i] = new Dog();
    //     else 
    //         animals[i] = new Cat();
    // }
    // for (int i = 0; i < size; i++) 
    //     delete animals[i]; 

    // Brain a;

    Cat a;
    Cat b(a);
    // a.brain->ideas[0] = "eat";
    // a.makeSound();
}