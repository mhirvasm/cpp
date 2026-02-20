#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phonenumber;
        std::string _darksecret;

    public:

        //All the goodie setters ONLY PROTOTPES HERE
        void setFirstname(std::string firstName);
        void setLastname();
        void setNickname();
        void setPhonenumber();
        void setDarksecret();

        //All the goodie getters ONLY PROTOTYPES HERE 
        std::string getFirstname() { return _firstName; }
        std::string getLastname() { return _lastName; }
        std::string getNickname() { return _nickName; }
        std::string getPhonenumber() { return _phonenumber; }
        std::string getDarksecret() { return _darksecret; }

    //data here
    //function here
};

#endif
