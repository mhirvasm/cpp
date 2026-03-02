#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
    private:
            std::string type;

    public:
            Weapon(std::string weapon);
            ~Weapon();
            getType(void);
            setType(std::string type);

};

#endif