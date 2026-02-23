#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
class Contact
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phonenumber;
        std::string _darksecret;

    public:

        //All the goodie setters ONLY PROTOTPES HERE
        void set_firstname(std::string firstname);
        void set_lastname(std::string lastname);
        void set_nickname(std::string nickname);
        void set_phonenumber(std::string phonenumber);
        void set_darksecret(std::string darksecret);

        //All the goodie getters ONLY PROTOTYPES HERE 
        std::string get_firstname() const;
        std::string get_lastname() const;
        std::string get_nickname() const;
        std::string get_phonenumber() const;
        std::string get_darksecret() const;

    //data here
    //function here
};

#endif
