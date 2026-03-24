#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "Calling getType on dog object\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << "Calling getType on cat object\n";
    std::cout << i->getType() << " " << std::endl;
    std::cout << std::endl;

    std::cout << "Calling Cat makeSound\n";
    i->makeSound(); //will output the cat sound!
    std::cout << std::endl;
    std::cout << "Calling Dog makeSound\n";
    j->makeSound();
    std::cout << std::endl;
    std::cout << "Calling Animal class sound\n";
    meta->makeSound();
    std::cout << std::endl;

    std::cout <<"Deleting Animal:\n";
    delete meta; // remember to CLEAN
    std::cout << std::endl;
    std::cout << "Deleting Dog:\n";
    delete j;
    std::cout << std::endl;
    std::cout << "Deleting Cat:\n";
    delete i;
    std::cout << std::endl;

    //WrongAnimal tests
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i2 = new WrongCat();

    meta2->makeSound(); // Calls wrong Animal makeSOund
    i2->makeSound(); // Calls base class method because it lacks the virtual keyword
    delete meta2; // deletes wrongAnimal
    delete i2; // DANGER
    //Since the destructor is not virtual, the derived class destructor is never called, which leads to undefined behavior or memory leaks if the child has allocated resources

return 0;
}