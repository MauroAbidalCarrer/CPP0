#include "Contact.hpp"
#include <iostream>


std::string Contact::getFirstName()
{
    return firstName;
}
std::string Contact::getLastName()
{
    return lastName;
}
std::string Contact::getNickname()
{
    return nickname;
}
std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}
std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}


bool getContactField(std::string prompt, std::string& dst)
{
    std::cout << prompt << " :";
    getline(std::cin, dst, '\n');
    if (std::cin.eof())
        return true;
    if (dst.empty())
    {
        std::cout << "contact field cannot be empty!" << std::endl;
        return getContactField(prompt, dst);
    }
    return false;
}

bool Contact::setFields()
{
    return  getContactField("first name", firstName) ||
            getContactField("last name", lastName) ||
            getContactField("nickname", nickname) ||
            getContactField("phone number", phoneNumber) || 
            getContactField("darkest secret", darkestSecret);
}


void Contact::test()
{
    std::cout << "test called" << std::endl;
}