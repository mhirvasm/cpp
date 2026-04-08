#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    
    // --- REQUIRED ARRAY TEST
    std::cout << "--- Creating an array of animals ---" << std::endl;
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; i++) {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Testing sounds from array ---" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\n--- Deleting array (Checking polymorphic destructors) ---" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i]; //This needs to call cat or dog destructor first
    }

    // --- DEEP COPY TEST   
    std::cout << "\n--- Deep Copy Verification ---" << std::endl;
    Dog basic;

    Dog tmp = basic;
    std::cout << "Original idea: " << basic.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy's idea: " << tmp.getBrain()->ideas[0] << std::endl;

    tmp.getBrain()->ideas[0] = "I love cats now"; // Muutetaan vain kopiota
    std::cout << "--- After modification ---" << std::endl;
    std::cout << "Original idea (empty thought 0): " << basic.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy's idea (should be cats): " << tmp.getBrain()->ideas[0] << std::endl;

    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    Dog a;
    Dog b;
    a = b;

    

    //ABSTRACT CLASS FAST TEST
    /*
    std::cout << "\n--- Trying to instantiate Animal ---" << std::endl;
    const Animal* meta = new Animal(); // Compiler error inc
    */
    


    std::cout << "\n--- End of tests ---" << std::endl;

    return 0;    

}