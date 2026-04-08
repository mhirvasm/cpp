#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {

    protected:
            std::string type;

    public:
            // Orthodox Canonical Form
            WrongAnimal();
            WrongAnimal(const WrongAnimal& other);
            WrongAnimal& operator=(const WrongAnimal& other);
            ~WrongAnimal(); // Not virtual anymore

            void makeSound() const; // Not virtual anymore
            std::string getType() const;
};

#endif