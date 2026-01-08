#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    const int size = 4;
    Animal *animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else 
            animals[i] = new Cat();
    }
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();
    for (int i = 0; i < size; i++) 
        delete animals[i];
    Dog a;
    Dog b = a;

    Dog m;
    Dog n;
    n = m;
}
